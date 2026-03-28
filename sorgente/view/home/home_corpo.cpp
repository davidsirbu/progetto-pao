#include "home_corpo.h"
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>

home_corpo::home_corpo(QWidget* parent): QWidget(parent) {
    
    QHBoxLayout* corpo_layout = new QHBoxLayout(this);
    lista_eventi = new QListWidget(this);
    lista_scadenze = new QListWidget(this);
    lista_routine = new QListWidget(this);
    
    corpo_layout -> addLayout(crea_colonna("Eventi", lista_eventi));
    corpo_layout -> addLayout(crea_colonna("Scadenze", lista_scadenze));
    corpo_layout -> addLayout(crea_colonna("Routine", lista_routine));

    setLayout(corpo_layout);
}

QVBoxLayout* home_corpo::crea_colonna(const QString& nome_attivita, QListWidget* lista) {

    QVBoxLayout* colonna = new QVBoxLayout();
    QLabel* titolo = new QLabel(nome_attivita);

    colonna -> addWidget(titolo);
    colonna -> addWidget(lista);

    return colonna;
}