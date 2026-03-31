#include "form_parte_variabile.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QSpinBox>

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

form_scadenza::form_scadenza(QWidget* parent): QWidget(parent) {
    
    QHBoxLayout* layout_principale = new QHBoxLayout(this);

    QLabel* etichetta_tempo_limite = new QLabel("Limite: ", this);
    layout_principale -> addWidget(etichetta_tempo_limite);

    selettore_tempo_limite = new QDateTimeEdit(this);
    layout_principale -> addWidget(selettore_tempo_limite);

    QWidget* spazio = new QWidget(this);
    layout_principale -> addWidget(spazio);

    QLabel* etichetta_completamento = new QLabel("Completato: ", this);
    layout_principale -> addWidget(etichetta_completamento);

    casella_completamento = new QCheckBox(this);
    layout_principale -> addWidget(casella_completamento);

    setLayout(layout_principale);
}
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
