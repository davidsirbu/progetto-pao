#include "detail_view.h"
#include "detail_header.h"
#include "display/display_impegno.h"
#include "display/display_scadenza.h"
#include "display/display_routine.h"

#include <QVBoxLayout>

detail_view::detail_view(QWidget* parent): QWidget(parent) {

    layout = new QVBoxLayout(this);

    header = new detail_header(this);
    layout -> addWidget(header);
    connect(header, &detail_header::torna_indietro, this, &detail_view::torna_indietro);
    connect(header, &detail_header::modifica_attivita, this, &detail_view::inoltra_segnale_modifica);
    
    setLayout(layout);
}

void detail_view::inoltra_dettagli(const dati_impegno& i) {
    display_attuale = new display_impegno(i);
    layout -> addWidget(display_attuale);
}

void detail_view::inoltra_dettagli(const dati_scadenza& s) {
    display_attuale = new display_scadenza(s);
    layout -> addWidget(display_attuale);
}

void detail_view::inoltra_dettagli(const dati_routine& r) {
    display_attuale = new display_routine(r);
    layout -> addWidget(display_attuale);
}

void detail_view::torna_indietro() {
    layout -> removeWidget(display_attuale);
    delete display_attuale;
    display_attuale = nullptr;
    emit segnale_indietro();
}

void detail_view::inoltra_segnale_modifica() {
    emit segnale_modifica(display_attuale -> get_id_attuale());
    layout -> removeWidget(display_attuale);
    delete display_attuale;
    display_attuale = nullptr;
}