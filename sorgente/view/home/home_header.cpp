#include "home_header.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>


home_header::home_header(QWidget* parent): QWidget(parent) {

    QHBoxLayout* header_layout = new QHBoxLayout(this);

    pulsante_nuova_attivita = new QPushButton("Nuova attivita", this);
    header_layout -> addWidget(pulsante_nuova_attivita);
    connect(pulsante_nuova_attivita, &QPushButton::clicked, this, &home_header::crea_attivita);

    QPushButton* pulsante_importa = new QPushButton("Importa file", this);
    header_layout -> addWidget(pulsante_importa);

    QPushButton* pulsante_esporta = new QPushButton("Esporta file", this);
    header_layout -> addWidget(pulsante_esporta);

    QLineEdit* barra_ricerca = new QLineEdit(this);
    header_layout -> addWidget(barra_ricerca);

    setLayout(header_layout);
}