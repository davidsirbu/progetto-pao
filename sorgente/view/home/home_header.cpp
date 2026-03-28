#include "home_header.h"

#include <QHBoxLayout>
#include <QPushButton>

home_header::home_header(QWidget* parent): QWidget(parent) {

    QHBoxLayout* header_layout = new QHBoxLayout(this);

    QPushButton* nuova_attivita = new QPushButton("Nuova attivita", this);
    QPushButton* importa_file = new QPushButton("Importa file", this);
    QPushButton* esporta_file = new QPushButton("Esporta file", this);
    QLineEdit* barra_ricerca = new QLineEdit(this);

    header_layout -> addWidget(nuova_attivita);
    header_layout -> addWidget(importa_file);
    header_layout -> addWidget(esporta_file);
    header_layout -> addWidget(barra_ricerca);

    setLayout(header_layout);
}