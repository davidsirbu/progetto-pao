#include "visitor_modifica.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"

Gruppo visitor_modifica::converti_stringa_in_enum(const QString& s) const {
    QString str = s.toLower();

    if (str == "studio") return Gruppo::Studio;
    if (str == "lavoro") return Gruppo::Lavoro;
    if (str == "hobby") return Gruppo::Hobby;
    if (str == "altro") return Gruppo::Altro;

    return Gruppo::Nessuno;
}

void visitor_modifica::set_dati_impegno(const dati_impegno& i) {
    dati_i = i;
}

void visitor_modifica::set_dati_scadenza(const dati_scadenza& s) {
    dati_s = s;
}

void visitor_modifica::set_dati_routine(const dati_routine& r) {
    dati_r = r;
}

void visitor_modifica::visit(impegno& i) {
    i.set_nome(dati_i.nome);
    i.set_descrizione(dati_i.descrizione);
    i.set_categoria(converti_stringa_in_enum(dati_i.categoria));
    i.set_inizio(dati_i.inizio);
    i.set_fine(dati_i.fine);
    i.set_luogo(dati_i.luogo);
}

void visitor_modifica::visit(scadenza& s) {
    s.set_nome(dati_s.nome);
    s.set_descrizione(dati_s.descrizione);
    s.set_categoria(converti_stringa_in_enum(dati_s.categoria));
    s.set_limite(dati_s.limite);
}

void visitor_modifica::visit(routine& r) {
    r.set_nome(dati_r.nome);
    r.set_descrizione(dati_r.descrizione);
    r.set_categoria(converti_stringa_in_enum(dati_r.categoria));
    r.set_inizio(dati_r.inizio);
    r.set_intervallo(dati_r.intervallo);
}