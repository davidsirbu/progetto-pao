#include "controller.h"
#include "../model/gestore.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include "../view/main_view.h"

Gruppo controller::converti_stringa_in_enum(const QString& s) const {
    QString str = s.toLower();

    if (str == "studio") return Gruppo::Studio;
    if (str == "lavoro") return Gruppo::Lavoro;
    if (str == "hobby") return Gruppo::Hobby;
    if (str == "altro") return Gruppo::Altro;

    return Gruppo::Nessuno;
}

void controller::passa_liste(const std::vector<dati_impegno>& i,
                             const std::vector<dati_scadenza>& s,
                             const std::vector<dati_routine>& r) const {
    main_window -> passa_liste(i, s, r);
}

controller::controller(gestore* g, main_view* v): gestore_attivita(g), main_window(v) {

    connect(main_window, &main_view::segnale_salvataggio, this, &controller::salva_su_file);
    connect(main_window, &main_view::segnale_caricamento, this, &controller::carica_da_file);
    connect(main_window, &main_view::segnale_richiesta_dati, this, &controller::esporta_a_gui);
    connect(main_window, &main_view::segnale_elimina_attivita, this, &controller::elimina_attivita);
    connect(main_window, &main_view::invia_dati_impegno, this, &controller::importa_e_smista_impegno);
    connect(main_window, &main_view::invia_dati_scadenza, this, &controller::importa_e_smista_scadenza);
    connect(main_window, &main_view::invia_dati_routine, this, &controller::importa_e_smista_routine);
    connect(main_window, &main_view::attivita_completata, this, &controller::completa_attivita);
    connect(main_window, &main_view::segnale_chiusura_finestra, this, &controller::controllo_uscita);

    connect(&ricercatore, &visitor_ricerca::trovato_impegno, main_window, &main_view::passa_dati_impegno);
    connect(&ricercatore, &visitor_ricerca::trovata_scadenza, main_window, &main_view::passa_dati_scadenza);
    connect(&ricercatore, &visitor_ricerca::trovata_routine, main_window, &main_view::passa_dati_routine);
}

void controller::refresh() {
    filtratore.reset();
    gestore_attivita -> ordina_attivita();
    gestore_attivita -> accetta(filtratore);
    passa_liste(filtratore.get_impegni(), filtratore.get_scadenze(), filtratore.get_routine());
}

void controller::crea_attivita(const dati_impegno& i) {
    impegno* aux = new impegno(i.nome, i.descrizione, converti_stringa_in_enum(i.categoria), i.inizio, i.fine, i.luogo);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();

    modifiche_non_salvate = true;
}

void controller::crea_attivita(const dati_scadenza& s) {
    scadenza* aux = new scadenza(s.nome, s.descrizione, converti_stringa_in_enum(s.categoria), s.limite);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();

    modifiche_non_salvate = true;
}

void controller::crea_attivita(const dati_routine& r) {
    routine* aux = new routine(r.nome, r.descrizione, converti_stringa_in_enum(r.categoria), r.inizio, r.intervallo);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();

    modifiche_non_salvate = true;
}

void controller::modifica_attivita(const dati_impegno& i) {
    attivita* aux = gestore_attivita -> cerca_attivita(i.id);
    modificatore.reset();
    modificatore.set_dati_impegno(i);
    aux -> accetta(modificatore);
    modifiche_non_salvate = true;
}

void controller::modifica_attivita(const dati_scadenza& s) {
    attivita* aux = gestore_attivita -> cerca_attivita(s.id);
    modificatore.reset();
    modificatore.set_dati_scadenza(s);
    aux -> accetta(modificatore);
    modifiche_non_salvate = true;
}

void controller::modifica_attivita(const dati_routine& r) {
    attivita* aux = gestore_attivita -> cerca_attivita(r.id);
    modificatore.reset();
    modificatore.set_dati_routine(r);
    aux -> accetta(modificatore);
    modifiche_non_salvate = true;
}

void controller::elimina_attivita(const QString& id) {
    gestore_attivita -> rimuovi_attivita(id);
    refresh();

    modifiche_non_salvate = true;
}

void controller::importa_e_smista_impegno(const dati_impegno& i) {
    if (i.id.isEmpty()) crea_attivita(i);
    else modifica_attivita(i);
    refresh();
}

void controller::importa_e_smista_scadenza(const dati_scadenza& s) {
    if(s.id.isEmpty()) crea_attivita(s);
    else modifica_attivita(s);
    refresh();
}

void controller::importa_e_smista_routine(const dati_routine& r) {
    if(r.id.isEmpty()) crea_attivita(r);
    else modifica_attivita(r);
    refresh();
}

void controller::esporta_a_gui(const QString& id, bool modifica) {
    attivita* ricercata = gestore_attivita -> cerca_attivita(id);
    ricercatore.reset();
    ricercatore.set_stato(modifica);
    ricercata -> accetta(ricercatore);
}

bool controller::salva_su_file(bool manuale) {
    if (manuale) {
        QString nuovo_percorso = main_window -> chiedi_percorso_salvataggio();
        if (nuovo_percorso.isEmpty()) return false; 
        percorso_salvataggio_attuale = nuovo_percorso;
    }
    gestore_attivita -> salva_dati(percorso_salvataggio_attuale);

    modifiche_non_salvate = false;
    return true;
}

bool controller::carica_da_file() {
    QString percorso = main_window -> chiedi_percorso_caricamento();
    if (percorso.isEmpty()) return false;
    gestore_attivita -> importa_dati(percorso);
    percorso_salvataggio_attuale = percorso;
    refresh();
    return true;
}

void controller::completa_attivita(const QString& id) {
    attivita* completata = gestore_attivita -> cerca_attivita(id);
    completata -> esegui_completamento();
    refresh();

    modifiche_non_salvate = true;
}

void controller::controllo_uscita() {
    if (modifiche_non_salvate) {
        QMessageBox::StandardButton risposta = main_window -> mostra_popup_salvataggio();
        if (risposta == QMessageBox::Save) {
            bool successo = false;
            if (percorso_salvataggio_attuale.isEmpty()) successo = salva_su_file(true);
            else successo = salva_su_file(false);

            if (successo) main_window -> autorizza_chiusura();
        }
        else if (risposta == QMessageBox::Discard) main_window -> autorizza_chiusura();
    }
    else main_window -> autorizza_chiusura();
}