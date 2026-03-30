#include "detail_corpo.h"
#include <QVBoxLayout>
#include <QLabel>

detail_corpo::detail_corpo(QWidget* parent): QWidget(parent) {

    QHBoxLayout* corpo_layout = new QHBoxLayout(this);

    QVBoxLayout* colonna = new QVBoxLayout(this);

    QLabel* etichetta = new QLabel("Etichetta", this);
    QListWidget* lista = new QListWidget(this);

    colonna -> addWidget(etichetta);
    colonna -> addWidget(lista);

    QWidget* prova = new QWidget(this);

    corpo_layout -> addLayout(colonna, 1);
    corpo_layout -> addWidget(prova, 2);

    setLayout(corpo_layout);
}