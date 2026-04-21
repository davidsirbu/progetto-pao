#include "visitor_ricerca.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"

void visitor_ricerca::visit(impegno& i) {
    dto_impegno.id = i.get_id();
    dto_impegno.nome = i.get_nome();
    dto_impegno.categoria = i.get_categoria();
    dto_impegno.descrizione = i.get_descrizione();
    dto_impegno.inizio = i.get_inizio();
    dto_impegno.fine = i.get_fine();
    dto_impegno.luogo = i.get_luogo();
}

void visitor_ricerca::visit(scadenza& s) {
    dto_scadenza.id = s.get_id();
    dto_scadenza.nome = s.get_nome();
    dto_scadenza.categoria = s.get_categoria();
    dto_scadenza.descrizione = s.get_descrizione();
    dto_scadenza.limite = s.get_limite();
}

void visitor_ricerca::visit(routine& r) {
    dto_routine.id = r.get_id();
    dto_routine.nome = r.get_nome();
    dto_routine.categoria = r.get_categoria();
    dto_routine.descrizione = r.get_descrizione();
    dto_routine.inizio = r.get_inizio();
    dto_routine.intervallo = r.get_intervallo();
}

dati_impegno visitor_ricerca::get_impegno() {
    return dto_impegno;
}

dati_scadenza visitor_ricerca::get_scadenza() {
    return dto_scadenza;
}

dati_routine visitor_ricerca::get_routine() {
    return dto_routine;
}

void visitor_ricerca::reset() {
    dto_impegno.id.clear();
    dto_impegno.nome.clear();
    dto_impegno.categoria = Gruppo::Nessuno;
    dto_impegno.descrizione.clear();
    dto_impegno.inizio = QDateTime();
    dto_impegno.fine = QDateTime();
    dto_impegno.luogo.clear();

    dto_scadenza.id.clear();
    dto_scadenza.nome.clear();
    dto_scadenza.categoria = Gruppo::Nessuno;
    dto_scadenza.descrizione.clear();
    dto_scadenza.limite = QDateTime();

    dto_routine.id.clear();
    dto_routine.nome.clear();
    dto_routine.categoria = Gruppo::Nessuno;
    dto_routine.descrizione.clear();
    dto_routine.inizio = QDateTime();
    dto_routine.intervallo = 0;
}