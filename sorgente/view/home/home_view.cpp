#include "home_view.h"

#include <QVBoxLayout>

home_view::home_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* home_layout = new QVBoxLayout(this);
    header = new home_header(this);
    corpo = new home_corpo(this);

    home_layout -> addWidget(header);
    home_layout -> addWidget(corpo);

    setLayout(home_layout);
}