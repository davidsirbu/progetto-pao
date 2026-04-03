#include "home_corpo.h"
#include "../../model/classi/impegno.h"
#include "../../model/classi/scadenza.h"
#include "../../model/classi/routine.h"
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QDateTime>

home_corpo::home_corpo(QWidget* parent): QWidget(parent) {

    QHBoxLayout* corpo_layout = new QHBoxLayout(this);

    lista_eventi = new QListWidget(this);
    corpo_layout -> addLayout(crea_colonna("Eventi", lista_eventi));

    lista_scadenze = new QListWidget(this);
    corpo_layout -> addLayout(crea_colonna("Scadenze", lista_scadenze));

    lista_routine = new QListWidget(this);
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

QString home_corpo::converti_enum(const Gruppo e) const {
    switch(e) {
        case Gruppo::Studio: return "Studio";
        case Gruppo::Lavoro: return "Lavoro";
        case Gruppo::Hobby: return "Hobby";
        case Gruppo::Altro: return "Altro";

        default: return "Altro";
    }
}

void home_corpo::carica_impegni(const std::vector<impegno*>& i) const {
    lista_eventi -> blockSignals(true);
    lista_eventi -> clear();
    lista_eventi -> blockSignals(false);
    for (auto it = i.begin(); it != i.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = (*it) -> get_nome();
        QString categoria = converti_enum((*it) -> get_categoria());
        item -> setText(nome + '\n' + categoria + '\n');

        lista_eventi -> addItem(item);
    }
}

void home_corpo::carica_scadenze(const std::vector<scadenza*>& s) const {
    lista_scadenze -> blockSignals(true);
    lista_scadenze -> clear();
    lista_scadenze -> blockSignals(false);
    for (auto it = s.begin(); it != s.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = (*it) -> get_nome();
        QString categoria = converti_enum((*it) -> get_categoria());
        QString tempo_limite = (*it) -> get_limite().toString("dd/MM/yyyy HH:mm");
        item -> setText(nome + '\n' + categoria + '\n' + tempo_limite);

        lista_scadenze -> addItem(item);
    }
}

void home_corpo::carica_routine(const std::vector<routine*>& r) const {
    lista_routine -> blockSignals(true);
    lista_routine -> clear();
    lista_routine -> blockSignals(false);
    for (auto it = r.begin(); it != r.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = (*it) -> get_nome();
        QString categoria = converti_enum((*it) -> get_categoria());
        item -> setText(nome + '\n' + categoria);
       
        lista_routine -> addItem(item);
    }
}

void home_corpo::aggiorna_liste(const std::vector<impegno*>& i, 
                                const std::vector<scadenza*>& s, 
                                const std::vector<routine*>& r) const {
    carica_impegni(i);
    carica_scadenze(s);
    carica_routine(r);
}