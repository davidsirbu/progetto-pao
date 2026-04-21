#include "main_window.h"
#include "home/home_view.h"
#include "detail/detail_view.h"
#include "form/form_view.h"
#include "../controller/controller.h"
#include <QStackedLayout>

main_window::main_window(controller* c, QWidget* parent): QWidget(parent), control(c) {

    stacked_layout = new QStackedLayout(this);

    home_window = new home_view(this);
    stacked_layout -> addWidget(home_window);
    connect(home_window, &home_view::crea_attivita, this, &main_window::crea_attivita);
    connect(home_window, &home_view::segnale_modifica, control, &controller::modifica_attivita);
    connect(home_window, &home_view::segnale_elimina, control, &controller::elimina_attivita);

    detail_window = new detail_view(this);
    stacked_layout -> addWidget(detail_window);

    form_window = new form_view(this);
    stacked_layout -> addWidget(form_window);
    connect(form_window, &form_view::torna_indietro, this, &main_window::torna_indietro);
    connect(form_window, &form_view::salva_impegno, control, &controller::crea_impegno);
    connect(form_window, &form_view::salva_scadenza, control, &controller::crea_scadenza);
    connect(form_window, &form_view::salva_routine, control, &controller::crea_routine);

    stacked_layout -> setCurrentIndex(0);
}

void main_window::torna_indietro() {
    stacked_layout -> setCurrentIndex(0);
}

void main_window::crea_attivita() {
    stacked_layout -> setCurrentIndex(2);
}

void main_window::passa_dati_impegno(const dati_impegno& i) {
    form_window -> carica_impegno(i);
    stacked_layout -> setCurrentIndex(2);
}

void main_window::passa_dati_scadenza(const dati_scadenza& s) {
    form_window -> carica_scadenza(s);
    stacked_layout -> setCurrentIndex(2);
}

void main_window::passa_dati_routine(const dati_routine& r) {
    form_window -> carica_routine(r);
    stacked_layout -> setCurrentIndex(2);
}

void main_window::passa_liste(const std::vector<impegno*>& i, const std::vector<scadenza*>& s, const std::vector<routine*>& r) const {
    home_window -> passa_liste(i, s, r);
}