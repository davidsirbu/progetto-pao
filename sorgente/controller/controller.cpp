#include "controller.h"
#include "../model/gestore.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include "../view/main_window.h"

controller::controller(gestore* g): gestore_attivita(g) {}

void controller::assegna_main_window(main_window* m) {
    m_window = m;
}

void controller::crea_impegno(const dati_impegno& i) {
    impegno* aux = new impegno(i.nome, i.descrizione, Gruppo::Altro, i.inizio, i.fine, i.luogo);
    gestore_attivita -> aggiungi_attivita(aux);
    smistamento();
}

void controller::crea_scadenza(const dati_scadenza& s) {
    scadenza* aux = new scadenza(s.nome, s.descrizione, Gruppo::Altro, s.limite);
    gestore_attivita -> aggiungi_attivita(aux);
    smistamento();
}

void controller::crea_routine(const dati_routine& r) {
    routine* aux = new routine(r.nome, r.descrizione, Gruppo::Altro, r.inizio, r.intervallo);
    gestore_attivita -> aggiungi_attivita(aux);
    smistamento();
}

void controller::smistamento() {
    smistatore.reset();
    gestore_attivita -> accetta_visitatore(smistatore);
    passa_liste(smistatore.get_impegni(), smistatore.get_scadenze(), smistatore.get_routine());
}

void controller::passa_liste(const std::vector<impegno*>& i, const std::vector<scadenza*>& s, const std::vector<routine*>& r) const {
    m_window -> passa_liste(i, s, r);
}