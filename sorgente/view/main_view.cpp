#include "main_view.h"
#include "home/home_view.h"
#include "detail/detail_view.h"
#include "form/form_view.h"
#include <QStackedLayout>

main_view::main_view(QWidget* parent): QWidget(parent) {

    stacked_layout = new QStackedLayout(this);

    home_window = new home_view(this);
    stacked_layout -> addWidget(home_window);
    connect(home_window, &home_view::crea_attivita, this, &main_view::crea_attivita);
    connect(home_window, &home_view::segnale_dettagli, this, &main_view::segnale_richiesta_dati);
    connect(home_window, &home_view::segnale_elimina, this, &main_view::segnale_elimina_attivita);

    detail_window = new detail_view(this);
    stacked_layout -> addWidget(detail_window);
    connect(detail_window, &detail_view::segnale_indietro, this, &main_view::torna_indietro);
    connect(detail_window, &detail_view::segnale_modifica, this, &main_view::segnale_richiesta_dati);

    form_window = new form_view(this);
    stacked_layout -> addWidget(form_window);
    connect(form_window, &form_view::torna_indietro, this, &main_view::torna_indietro);
    connect(form_window, &form_view::salva_impegno, this, &main_view::invia_dati_impegno);
    connect(form_window, &form_view::salva_scadenza, this, &main_view::invia_dati_scadenza);
    connect(form_window, &form_view::salva_routine, this, &main_view::invia_dati_routine);

    stacked_layout -> setCurrentIndex(0);
}

void main_view::torna_indietro() {
    stacked_layout -> setCurrentIndex(0);
}

void main_view::crea_attivita() {
    stacked_layout -> setCurrentIndex(2);
}

void main_view::passa_dati_impegno(const dati_impegno& i, bool stato) {
    if (stato == true) {
        form_window -> carica_impegno(i);
        stacked_layout -> setCurrentIndex(2);
    }
    else {
        detail_window -> carica_dettagli_impegno(i);
        stacked_layout -> setCurrentIndex(1);
    }
}

void main_view::passa_dati_scadenza(const dati_scadenza& s, bool stato) {
    if (stato == true) {
        form_window -> carica_scadenza(s);
        stacked_layout -> setCurrentIndex(2);
    }
    else {
        detail_window -> carica_dettagli_scadenza(s);
        stacked_layout -> setCurrentIndex(1);
    }
}

void main_view::passa_dati_routine(const dati_routine& r, bool stato) {
    if (stato == true) {
        form_window -> carica_routine(r);
        stacked_layout -> setCurrentIndex(2);
    }
    else {
        detail_window -> carica_dettagli_routine(r);
        stacked_layout -> setCurrentIndex(1);
    }
}

void main_view::passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const {
    home_window -> passa_liste(i, s, r);
}