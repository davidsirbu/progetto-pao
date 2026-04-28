#include "visitor_filtro.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include <QListWidget>
#include <QListWidgetItem>

void visitor_filtro::visit(impegno& i) {
    dati_impegno dto;
    dto.id = i.get_id();
    dto.nome = i.get_nome();
    dto.categoria = converti_enum(i.get_categoria());
    dto.descrizione = i.get_descrizione();
    dto.inizio = i.get_inizio();
    dto.fine = i.get_fine();
    dto.luogo = i.get_luogo();
    lista_impegni.push_back(dto);
}

void visitor_filtro::visit(scadenza& s) {
    dati_scadenza dto;
    dto.id = s.get_id();
    dto.nome = s.get_nome();
    dto.categoria = converti_enum(s.get_categoria());
    dto.descrizione = s.get_descrizione();
    dto.limite = s.get_limite();

}

void visitor_filtro::visit(routine& r) {
    dati_routine dto;
    dto.id = r.get_id();
    dto.nome = r.get_nome();
    dto.categoria = converti_enum(r.get_categoria());
    dto.descrizione = r.get_descrizione();
    dto.inizio = r.get_inizio();
    dto.intervallo = r.get_intervallo();
}

const std::vector<dati_impegno>& visitor_filtro::get_impegni() const {
    return lista_impegni;
}

const std::vector<dati_scadenza>& visitor_filtro::get_scadenze() const {
    return lista_scadenze;
}

const std::vector<dati_routine>& visitor_filtro::get_routine() const {
    return lista_routine;
}

void visitor_filtro::reset() {
    lista_impegni.clear();
    lista_scadenze.clear();
    lista_routine.clear();
}


QString visitor_filtro::converti_enum(Gruppo e) const {
    switch(e) {
        case Gruppo::Studio: return "Studio";
        case Gruppo::Lavoro: return "Lavoro";
        case Gruppo::Hobby: return "Hobby";
        case Gruppo::Altro: return "Altro";
        default: return "Altro";
    }
}