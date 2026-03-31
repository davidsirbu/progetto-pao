#include "detail_corpo.h"
#include "display/display_view.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>

detail_corpo::detail_corpo(QWidget* parent): QWidget(parent) {

    QHBoxLayout* corpo_layout = new QHBoxLayout(this);

    lista = new QListWidget(this);
    corpo_layout -> addWidget(lista, 1);

    display_window = new display_view(this);
    corpo_layout -> addWidget(display_window, 2);

    setLayout(corpo_layout);
}