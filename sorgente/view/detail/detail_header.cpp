#include "detail_header.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>


detail_header::detail_header(QWidget* parent): QWidget(parent) {

    QHBoxLayout* header_layout = new QHBoxLayout(this);

    pulsante_indietro = new QPushButton("Indietro", this);
    header_layout -> addWidget(pulsante_indietro);
    connect(pulsante_indietro, &QPushButton::clicked, this, &detail_header::torna_indietro);

    pulsante_modifica = new QPushButton("Modifica", this);
    header_layout -> addWidget(pulsante_modifica);
    connect(pulsante_modifica, &QPushButton::clicked, this, &detail_header::modifica_attivita);

    setLayout(header_layout);
}