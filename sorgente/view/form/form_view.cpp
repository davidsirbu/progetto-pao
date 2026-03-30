#include "form_view.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

form_view::form_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    QLabel* titolo_finestra = new QLabel("Crea/Modifica attività", this);
    layout_principale -> addWidget(titolo_finestra);

    etichetta_titolo = new QLineEdit(this);
    etichetta_titolo -> setPlaceholderText("Inserisci il titolo");
    layout_principale -> addWidget(etichetta_titolo);

    menu_gruppo = new QComboBox(this);
    layout_principale -> addWidget(menu_gruppo);

    parte_scelta = new form_scelta(this);
    layout_principale -> addWidget(parte_scelta);

    etichetta_descrizione = new QTextEdit(this);
    etichetta_descrizione -> setPlaceholderText("Inserisci la descrizione");
    layout_principale -> addWidget(etichetta_descrizione);

    QHBoxLayout* action_layout = new QHBoxLayout(this);

    QWidget* spaziatore = new QWidget(this);
    action_layout -> addWidget(spaziatore, 4);

    pulsante_salva = new QPushButton("Salva", this);
    action_layout -> addWidget(pulsante_salva, 1);

    pulsante_annulla = new QPushButton("Annulla", this);
    action_layout -> addWidget(pulsante_annulla, 1);

    layout_principale -> addLayout(action_layout);

    setLayout(layout_principale);
}