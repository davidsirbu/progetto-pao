#include "form_impegno.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

form_impegno::form_impegno(QWidget* parent): QWidget(parent) {
    
    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    QHBoxLayout* layout_orari = new QHBoxLayout(this);

    QLabel* etichetta_inizio = new QLabel("Ora di inizio: ", this);
    layout_orari -> addWidget(etichetta_inizio, 1);

    selettore_inizio = new QDateTimeEdit();
    layout_orari -> addWidget(selettore_inizio, 1);

    QWidget* spazio = new QWidget(this);
    layout_orari -> addWidget(spazio, 1);

    QLabel* etichetta_fine = new QLabel("Ora di fine: ", this);
    layout_orari -> addWidget(etichetta_fine, 1);

    selettore_fine = new QDateTimeEdit(this);
    layout_orari -> addWidget(selettore_fine, 1);

    layout_principale -> addLayout(layout_orari);

    setLayout(layout_principale);
}