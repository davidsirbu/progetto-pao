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

    lista_impegni = new QListWidget(this);
    lista_impegni -> setSelectionMode(QAbstractItemView::SingleSelection);
    connect(lista_impegni, &QListWidget::itemSelectionChanged, this, &home_corpo::impegno_cliccato);
    corpo_layout -> addLayout(crea_colonna("Impegni", lista_impegni));

    lista_scadenze = new QListWidget(this);
    lista_scadenze -> setSelectionMode(QAbstractItemView::SingleSelection);
    connect(lista_scadenze, &QListWidget::itemSelectionChanged, this, &home_corpo::scadenza_cliccata);
    corpo_layout -> addLayout(crea_colonna("Scadenze", lista_scadenze));

    lista_routine = new QListWidget(this);
    lista_routine -> setSelectionMode(QAbstractItemView::SingleSelection);
    connect(lista_routine, &QListWidget::itemSelectionChanged, this, &home_corpo::routine_cliccata);
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

void home_corpo::aggiorna_stato_pulsanti() {
    int selezioni_totali = (lista_impegni -> selectedItems().count()) + (lista_routine -> selectedItems().count()) + (lista_scadenze -> selectedItems().count());
    if (selezioni_totali > 0) emit cambio_selezione();
}

void home_corpo::carica_impegni(const std::vector<dati_impegno>& i) const {
    lista_impegni -> blockSignals(true);
    lista_impegni -> clear();
    lista_impegni -> blockSignals(false);
    for (auto it = i.begin(); it != i.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = it -> nome;
        QString categoria = it -> categoria;
        item -> setText(nome + '\n' + categoria + '\n');
        item -> setData(Qt::UserRole, it -> id);

        lista_impegni -> addItem(item);
    }
}

void home_corpo::carica_scadenze(const std::vector<dati_scadenza>& s) const {
    lista_scadenze -> blockSignals(true);
    lista_scadenze -> clear();
    lista_scadenze -> blockSignals(false);
    for (auto it = s.begin(); it != s.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = it -> nome;
        QString categoria = it -> categoria;
        QString tempo_limite = (it -> limite).toString("dd/MM/yyyy HH:mm");
        item -> setText(nome + '\n' + categoria + '\n' + tempo_limite);
        item -> setData(Qt::UserRole, it -> id);

        lista_scadenze -> addItem(item);
    }
}

void home_corpo::carica_routine(const std::vector<dati_routine>& r) const {
    lista_routine -> blockSignals(true);
    lista_routine -> clear();
    lista_routine -> blockSignals(false);
    for (auto it = r.begin(); it != r.end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem();

        QString nome = it -> id;
        QString categoria = it -> categoria;
        item -> setText(nome + '\n' + categoria);
        item -> setData(Qt::UserRole, it -> id);
       
        lista_routine -> addItem(item);
    }
}

void home_corpo::aggiorna_liste(const std::vector<dati_impegno>& i, 
                                const std::vector<dati_scadenza>& s, 
                                const std::vector<dati_routine>& r) const {
    carica_impegni(i);
    carica_scadenze(s);
    carica_routine(r);
}

QString home_corpo::get_id_selezionato() const {
    if ((lista_impegni -> selectedItems().count()) > 0) {
        return lista_impegni -> currentItem() -> data(Qt::UserRole).toString();
    }
    if ((lista_scadenze -> selectedItems().count()) > 0) {
        return lista_scadenze -> currentItem() -> data(Qt::UserRole).toString();
    }
    if ((lista_routine -> selectedItems().count()) > 0) {
        return lista_routine -> currentItem() -> data(Qt::UserRole).toString();
    }
}

void home_corpo::impegno_cliccato() {
    if ((lista_impegni -> selectedItems()).count() > 0) {
        lista_scadenze -> clearSelection();
        lista_routine -> clearSelection();
    }
    aggiorna_stato_pulsanti();
}

void home_corpo::scadenza_cliccata() {
    if ((lista_scadenze -> selectedItems()).count() > 0) {
        lista_impegni -> clearSelection();
        lista_routine -> clearSelection();
    }
    aggiorna_stato_pulsanti();
}

void home_corpo::routine_cliccata() {
    if ((lista_routine -> selectedItems()).count() > 0) {
        lista_impegni -> clearSelection();
        lista_scadenze -> clearSelection();
    }
    aggiorna_stato_pulsanti();
}

void home_corpo::filtra_liste(const QString& s) {
    for (int i = 0; i < lista_impegni -> count(); ++i) {
        QListWidgetItem* oggetto_corrente = lista_impegni -> item(i);
        bool corrispondenza = (oggetto_corrente -> text()).contains(s, Qt::CaseInsensitive);
        oggetto_corrente -> setHidden(!corrispondenza);
    }
    for (int i = 0; i < lista_scadenze -> count(); ++i) {
        QListWidgetItem* oggetto_corrente = lista_scadenze -> item(i);
        bool corrispondenza = (oggetto_corrente -> text()).contains(s, Qt::CaseInsensitive);
        oggetto_corrente -> setHidden(!corrispondenza);
    }
    for (int i = 0; i < lista_routine -> count(); ++i) {
        QListWidgetItem* oggetto_corrente = lista_routine -> item(i);
        bool corrispondenza = (oggetto_corrente -> text()).contains(s, Qt::CaseInsensitive);
        oggetto_corrente -> setHidden(!corrispondenza);
    }
}