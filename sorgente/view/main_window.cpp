#include "main_window.h"

#include <QStackedLayout>

main_window::main_window(QWidget* parent): QWidget(parent) {

    stacked_layout = new QStackedLayout(this);

    home_window = new home_view(this);
    stacked_layout -> addWidget(home_window);
    connect(home_window, &home_view::crea_attivita, this, &main_window::crea_attivita);

    detail_window = new detail_view(this);
    stacked_layout -> addWidget(detail_window);
    connect(detail_window, &detail_view::torna_indietro, this, &main_window::torna_indietro);

    form_window = new form_view(this);
    stacked_layout -> addWidget(form_window);

    stacked_layout -> setCurrentIndex(0);  
}

void main_window::crea_attivita() {
    stacked_layout -> setCurrentIndex(2);
}

void main_window::torna_indietro() {
    stacked_layout -> setCurrentIndex(0);
}