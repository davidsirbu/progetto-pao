#include "form_routine.h"
#include <QHBoxLayout>
#include <QLabel>

form_routine::form_routine(QWidget* parent): QWidget(parent) {

    QHBoxLayout* layout_principale = new QHBoxLayout(this);

    QLabel* etichetta_inizio = new QLabel("Inizio: ", this);
    layout_principale -> addWidget(etichetta_inizio);

    selettore_inizio = new QDateTimeEdit(this);
    layout_principale -> addWidget(selettore_inizio);

    QWidget* spazio = new QWidget(this);
    layout_principale -> addWidget(spazio);

    QLabel* etichetta_intervallo = new QLabel("Intervallo: ", this);
    layout_principale -> addWidget(etichetta_intervallo);

    selettore_intervallo = new QSpinBox(this);
    layout_principale -> addWidget(selettore_intervallo);

    setLayout(layout_principale);
}
