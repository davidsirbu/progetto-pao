#include "home_header.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>

home_header::home_header(QWidget* parent): QWidget(parent) {

    QHBoxLayout* header_layout = new QHBoxLayout();

    pulsante_salvataggio_automatico = new QPushButton("Salva", this);
    connect(pulsante_salvataggio_automatico, &QPushButton::clicked, this, &home_header::salva_dati);

    pulsante_salvataggio_manuale = new QPushButton("Salva con nome", this);
    connect(pulsante_salvataggio_manuale, &QPushButton::clicked, this, &home_header::salva_dati_con_nome);

    pulsante_caricamento_dati = new QPushButton("Apri", this);
    connect(pulsante_caricamento_dati, &QPushButton::clicked, this, &home_header::carica_dati);

    pulsante_nuova_attivita = new QPushButton("Nuova attivita", this);
    connect(pulsante_nuova_attivita, &QPushButton::clicked, this, &home_header::crea_attivita);

    pulsante_modifica_attivita = new QPushButton("Modifica attivita", this);
    connect(pulsante_modifica_attivita, &QPushButton::clicked, this, &home_header::modifica_attivita);
    pulsante_modifica_attivita -> setEnabled(false);

    pulsante_elimina_attivita = new QPushButton("Elimina attivita", this);
    connect(pulsante_elimina_attivita, &QPushButton::clicked, this, &home_header::elimina_attivita);
    pulsante_elimina_attivita -> setEnabled(false);

    QVBoxLayout* colonna_1 = new QVBoxLayout();
    colonna_1 -> addWidget(pulsante_salvataggio_manuale);
    colonna_1 -> addWidget(pulsante_nuova_attivita);
    header_layout -> addLayout(colonna_1);

    QVBoxLayout* colonna_2 = new QVBoxLayout();
    colonna_2 -> addWidget(pulsante_salvataggio_automatico);
    colonna_2 -> addWidget(pulsante_modifica_attivita);
    header_layout -> addLayout(colonna_2);

    QVBoxLayout* colonna_3 = new QVBoxLayout();
    colonna_3 -> addWidget(pulsante_caricamento_dati);
    colonna_3 -> addWidget(pulsante_elimina_attivita);
    header_layout -> addLayout(colonna_3);

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