#include "form_scadenza.h"
#include <QHBoxLayout>
#include <QLabel>

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