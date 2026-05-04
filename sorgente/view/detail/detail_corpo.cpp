#include "detail_corpo.h"
#include "display/display_impegno.h"
#include "display/display_scadenza.h"
#include "display/display_routine.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QLabel>

detail_corpo::detail_corpo(QWidget* parent): QWidget(parent) {

    QHBoxLayout* corpo_layout = new QHBoxLayout(this);

    lista = new QListWidget(this);
    corpo_layout -> addWidget(lista, 1);

    contenitore = new QWidget(this);
    corpo_layout -> addWidget(lista, 2);

    setLayout(corpo_layout);
}