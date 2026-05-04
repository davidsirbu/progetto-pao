#include "controller.h"
#include "../model/gestore.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include "../view/main_window.h"
#include <QMessageBox>

controller::controller(gestore* g): gestore_attivita(g) {}

void controller::assegna_main_window(main_window* m) {
    m_window = m;
    ricercatore.set_window(m);
}

void controller::passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const {
    m_window -> passa_liste(i, s, r);
}

void controller::crea_impegno(const dati_impegno& i) {
    impegno* aux = new impegno(i.nome, i.descrizione, Gruppo::Altro, i.inizio, i.fine, i.luogo);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();
}

void controller::crea_scadenza(const dati_scadenza& s) {
    scadenza* aux = new scadenza(s.nome, s.descrizione, Gruppo::Altro, s.limite);
    gestore_attivita -> aggiungi_attivita(aux);
    refresh();
}

void controller::crea_routine(const dati_routine& r) {
    routine* aux = new routine(r.nome, r.descrizione, Gruppo::Altro, r.inizio, r.intervallo);
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