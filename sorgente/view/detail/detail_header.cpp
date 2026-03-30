#include "detail_header.h"
#include <QHBoxLayout>

detail_header::detail_header(QWidget* parent): QWidget(parent) {

    QHBoxLayout* header_layout = new QHBoxLayout(this);

    pulsante_indietro = new QPushButton("Indietro", this);
    connect(pulsante_indietro, &QPushButton::clicked, this, &detail_header::torna_indietro);

    barra_ricerca = new QLineEdit(this);

    header_layout -> addWidget(pulsante_indietro);
    header_layout -> addWidget(barra_ricerca);

    setLayout(header_layout);
}