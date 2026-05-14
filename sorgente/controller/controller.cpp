#include "controller.h"
#include "../model/gestore.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include "../view/main_view.h"
#include <QMessageBox>

controller::controller(gestore* g, main_view* v): gestore_attivita(g), main_window(v) {

    connect(main_window, &main_view::segnale_salvataggio, this, &controller::salva_su_file);
    connect(main_window, &main_view::segnale_caricamento, this, &controller::carica_da_file);
    connect(main_window, &main_view::segnale_richiesta_dati, this, &controller::esporta_per_modifica);
    connect(main_window, &main_view::segnale_elimina_attivita, this, &controller::elimina_attivita);
    connect(main_window, &main_view::invia_dati_impegno, this, &controller::importa_e_smista_impegno);
    connect(main_window, &main_view::invia_dati_scadenza, this, &controller::importa_e_smista_scadenza);
    connect(main_window, &main_view::invia_dati_routine, this, &controller::importa_e_smista_routine);
    connect(main_window, &main_view::attivita_completata, this, &controller::attivita_completata);

    connect(&ricercatore, &visitor_ricerca::trovato_impegno, main_window, &main_view::passa_dati_impegno);
    connect(&ricercatore, &visitor_ricerca::trovata_scadenza, main_window, &main_view::passa_dati_scadenza);
    connect(&ricercatore, &visitor_ricerca::trovata_routine, main_window, &main_view::passa_dati_routine);
}

void controller::passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const {
    main_window -> passa_liste(i, s, r);
}

void controller::crea_impegno(const dati_impegno& i) {
    impegno* aux = new impegno(i.nome, i.descrizione, converti_stringa_a_enum(i.categoria), i.inizio, i.fine, i.luogo);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();
}

void controller::crea_scadenza(const dati_scadenza& s) {
    scadenza* aux = new scadenza(s.nome, s.descrizione, converti_stringa_a_enum(s.categoria), s.limite);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();
}

void controller::crea_routine(const dati_routine& r) {
    routine* aux = new routine(r.nome, r.descrizione, converti_stringa_a_enum(r.categoria), r.inizio, r.intervallo);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();
}

void controller::modifica_impegno(const dati_impegno& i) {
    attivita* aux = gestore_attivita -> cerca_attivita(i.id);
    impegno* impegno_da_modificare = dynamic_cast<impegno*>(aux);

    impegno_da_modificare -> set_nome(i.nome);
    impegno_da_modificare -> set_descrizione(i.descrizione);
    impegno_da_modificare -> set_categoria(converti_stringa_a_enum(i.categoria));
    impegno_da_modificare -> set_inizio(i.inizio);
    impegno_da_modificare -> set_fine(i.fine);
    impegno_da_modificare -> set_luogo(i.luogo);
}

void controller::modifica_scadenza(const dati_scadenza& s) {
    attivita* aux = gestore_attivita -> cerca_attivita(s.id);
    scadenza* scadenza_da_modificare = dynamic_cast<scadenza*>(aux);

    scadenza_da_modificare -> set_nome(s.nome);
    scadenza_da_modificare -> set_descrizione(s.descrizione);
    scadenza_da_modificare -> set_categoria(converti_stringa_a_enum(s.categoria));
    scadenza_da_modificare -> set_limite(s.limite);
}

void controller::modifica_routine(const dati_routine& r) {
    attivita* aux = gestore_attivita -> cerca_attivita(r.id);
    routine* routine_da_modificare = dynamic_cast<routine*>(aux);

    routine_da_modificare -> set_nome(r.nome);
    routine_da_modificare -> set_descrizione(r.descrizione);
    routine_da_modificare -> set_categoria(converti_stringa_a_enum(r.categoria));
    routine_da_modificare -> set_inizio(r.inizio);
    routine_da_modificare -> set_intervallo(r.intervallo);
}

void controller::refresh() {
    smistatore.reset();
    gestore_attivita -> accetta_visitatore(smistatore);
    passa_liste(smistatore.get_impegni(), smistatore.get_scadenze(), smistatore.get_routine());
}

void controller::esporta_per_modifica(const QString& id, bool modifica) {
    attivita* ricercata = gestore_attivita -> cerca_attivita(id);
    ricercatore.reset();
    ricercatore.set_stato(modifica);
    ricercata -> accetta(ricercatore);
}

void controller::elimina_attivita(const QString& id) {
    gestore_attivita -> rimuovi_attivita(id);
    refresh();
}

void controller::importa_e_smista_impegno(const dati_impegno& i) {
    if (i.id.isEmpty()) crea_impegno(i);
    else modifica_impegno(i);
    refresh();
}

void controller::importa_e_smista_scadenza(const dati_scadenza& s) {
    if(s.id.isEmpty()) crea_scadenza(s);
    else modifica_scadenza(s);
    refresh();
}

void controller::importa_e_smista_routine(const dati_routine& r) {
    if(r.id.isEmpty()) crea_routine(r);
    else modifica_routine(r);
    refresh();
}

Gruppo controller::converti_stringa_a_enum(const QString& s) const {
    QString str = s.toLower();

    if (str == "studio") return Gruppo::Studio;
    if (str == "lavoro") return Gruppo::Lavoro;
    if (str == "hobby") return Gruppo::Hobby;
    if (str == "altro") return Gruppo::Altro;

    return Gruppo::Nessuno;
}

void controller::salva_su_file(bool manuale) {
    if (manuale) {
        QString nuovo_percorso = main_window -> chiedi_percorso_salvataggio();
        if (nuovo_percorso.isEmpty()) return; 
        percorso_salvataggio_attuale = nuovo_percorso;
    }
    gestore_attivita -> salva_dati(percorso_salvataggio_attuale);
}

void controller::carica_da_file() {
    gestore_attivita -> importa_dati(main_window -> chiedi_percorso_caricamento());
    refresh();
}

void controller::attivita_completata(const QString& id) {
    attivita* completata = gestore_attivita -> cerca_attivita(id);
    completata -> esegui_completamento();
    refresh();
}