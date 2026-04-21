#include "form_scelta.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

form_scelta::form_scelta(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    QHBoxLayout* layout_attivita = new QHBoxLayout(this);

    pulsante_impegno = new QPushButton("Impegno", this);
    pulsante_impegno -> setCheckable(true);
    pulsante_impegno -> setAutoExclusive(true);
    pulsante_impegno -> setChecked(true);
    connect(pulsante_impegno, &QPushButton::clicked, this, &form_scelta::cambia_in_impegno);
    layout_attivita -> addWidget(pulsante_impegno);

    pulsante_scadenza = new QPushButton("Scadenza", this);
    pulsante_scadenza -> setCheckable(true);
    pulsante_scadenza -> setAutoExclusive(true);
    connect(pulsante_scadenza, &QPushButton::clicked, this, &form_scelta::cambia_in_scadenza);
    layout_attivita -> addWidget(pulsante_scadenza);

    pulsante_routine = new QPushButton("Routine", this);
    pulsante_routine -> setCheckable(true);
    pulsante_routine -> setAutoExclusive(true);
    connect(pulsante_routine, &QPushButton::clicked, this, &form_scelta::cambia_in_routine);
    layout_attivita -> addWidget(pulsante_routine);

    layout_principale -> addLayout(layout_attivita);

    stacked_layout = new QStackedLayout(this);

    impegno_window = new form_impegno(this);
    stacked_layout -> addWidget(impegno_window);

    scadenza_window = new form_scadenza(this);
    stacked_layout -> addWidget(scadenza_window);

    routine_window = new form_routine(this);
    stacked_layout -> addWidget(routine_window);

    stacked_layout -> setCurrentIndex(0);  

    layout_principale -> addLayout(stacked_layout);
}

mini_dto_impegno form_scelta::ricevi_dati_impegno() const {
    return impegno_window -> salva_dati();
}

mini_dto_scadenza form_scelta::ricevi_dati_scadenza() const {
    return scadenza_window -> salva_dati();
}

mini_dto_routine form_scelta::ricevi_dati_routine() const {
    return routine_window -> salva_dati();
}

void form_scelta::inoltra_dati_impegno(const dati_impegno& i) {
    cambia_in_impegno();
    impegno_window -> set_dati(i);
}

void form_scelta::inoltra_dati_scadenza(const dati_scadenza& s) {
    cambia_in_scadenza();
    scadenza_window -> set_dati(s);
}

void form_scelta::inoltra_dati_routine(const dati_routine& r) {
    cambia_in_routine();
    routine_window -> set_dati(r);
}

int form_scelta::stato_stacked() {
    return stacked_layout -> currentIndex();
}

void form_scelta::reset() {
    impegno_window -> reset();
    scadenza_window -> reset();
    routine_window -> reset();
}

void form_scelta::cambia_in_impegno() {
    stacked_layout -> setCurrentIndex(0);
}

void form_scelta::cambia_in_scadenza() {
    stacked_layout -> setCurrentIndex(1);
}

void form_scelta::cambia_in_routine() {
    stacked_layout -> setCurrentIndex(2);
}