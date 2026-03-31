#include "display_view.h"
#include "display_variabile.h"
#include <QLabel>
#include <QStackedLayout>
#include <QVBoxLayout>

display_view::display_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    etichetta_titolo = new QLabel(this);
    layout_principale -> addWidget(etichetta_titolo);

    etichetta_categoria = new QLabel(this);
    layout_principale -> addWidget(etichetta_categoria);

    stacked_layout = new QStackedLayout(this);

    impegno_window = new display_impegno(this);
    stacked_layout -> addWidget(impegno_window);

    scadenza_window = new display_scadenza(this);
    stacked_layout -> addWidget(scadenza_window);

    routine_window = new display_routine(this);
    stacked_layout -> addWidget(routine_window);

    layout_principale -> addLayout(stacked_layout);

    etichetta_descrizione = new QLabel(this);
    layout_principale -> addWidget(etichetta_descrizione);

    setLayout(layout_principale);
}