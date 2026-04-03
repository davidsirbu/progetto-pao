#include "visitor_filtro.h"
#include "../model/classi/impegno.h"
#include "../model/classi/scadenza.h"
#include "../model/classi/routine.h"
#include <QListWidget>
#include <QListWidgetItem>

void visitor_filtro::visit(impegno& i) {
    lista_impegni.push_back(&i);
}

void visitor_filtro::visit(scadenza& s) {
    lista_scadenze.push_back(&s);
}

void visitor_filtro::visit(routine& r) {
    lista_routine.push_back(&r);
}

const std::vector<impegno*>& visitor_filtro::get_impegni() const {
    return lista_impegni;
}

const std::vector<scadenza*>& visitor_filtro::get_scadenze() const {
    return lista_scadenze;
}

const std::vector<routine*>& visitor_filtro::get_routine() const {
    return lista_routine;
}

void visitor_filtro::reset() {
    lista_impegni.clear();
    lista_scadenze.clear();
    lista_routine.clear();
}