#include "detail_corpo.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>

detail_corpo::detail_corpo(QWidget* parent): QWidget(parent) {

    QHBoxLayout* corpo_layout = new QHBoxLayout(this);

    lista = new QListWidget(this);
    corpo_layout -> addWidget(lista, 1);

    setLayout(corpo_layout);
}