#include "display_astratto.h"
#include <QFormLayout>
#include <QLabel>
#include <QTextBrowser>

display_astratto::display_astratto(const QString& titolo, const QString& categoria, const QString& descrizione, QWidget* parent): QWidget(parent) {
    layout = new QFormLayout(this);

    etichetta_titolo = new QLabel(titolo, this);
    layout -> addRow("Nome:", etichetta_titolo);

    etichetta_categoria = new QLabel(categoria, this);
    layout -> addRow("Categoria:", etichetta_categoria);

    etichetta_descrizione = new QTextBrowser(this);
    etichetta_descrizione -> setText(descrizione);
    layout -> addRow("Descrizione:", etichetta_descrizione);

    setLayout(layout);
}

display_astratto::~display_astratto() {}

void display_astratto::aggiungi_riga_al_form(const QString& categoria, const QString& etichetta) {
    QLabel* label = new QLabel(etichetta, this);
    layout -> addRow(categoria, label);
}

