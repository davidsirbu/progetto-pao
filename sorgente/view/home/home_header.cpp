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

    pulsante_modifica_attivita = new QPushButton("Modifica attivita", this);
    connect(pulsante_modifica_attivita, &QPushButton::clicked, this, &home_header::modifica_attivita);
    pulsante_modifica_attivita -> setEnabled(false);
    header_layout -> addWidget(pulsante_modifica_attivita);

    pulsante_elimina_attivita = new QPushButton("Elimina attivita", this);
    connect(pulsante_elimina_attivita, &QPushButton::clicked, this, &home_header::elimina_attivita);
    pulsante_elimina_attivita -> setEnabled(false);
    header_layout -> addWidget(pulsante_elimina_attivita);

    QLineEdit* barra_ricerca = new QLineEdit(this);
    connect(barra_ricerca, &QLineEdit::textChanged, this, &home_header::barra_cambiata);
    header_layout -> addWidget(barra_ricerca);

    setLayout(header_layout);
}

void home_header::attiva_pulsanti() {
    pulsante_modifica_attivita -> setEnabled(true);
    pulsante_elimina_attivita -> setEnabled(true);
}

void home_header::disattiva_pulsanti() {
    pulsante_modifica_attivita -> setEnabled(false);
    pulsante_elimina_attivita -> setEnabled(false);
}