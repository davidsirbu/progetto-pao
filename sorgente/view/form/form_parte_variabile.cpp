#include "form_parte_variabile.h"
#include "../../model/classi/attivita.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateTimeEdit>
#include <QDateTime>
#include <QCheckBox>
#include <QSpinBox>
#include <QLineEdit>

form_impegno::form_impegno(QWidget* parent): QWidget(parent) {
    
    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    QHBoxLayout* layout_orari = new QHBoxLayout(this);

    QLabel* etichetta_inizio = new QLabel("Ora di inizio: ", this);
    layout_orari -> addWidget(etichetta_inizio, 1);

    selettore_inizio = new QDateTimeEdit();
    selettore_inizio -> setDateTime(QDateTime::currentDateTime());

    layout_orari -> addWidget(selettore_inizio, 1);

    QWidget* spazio = new QWidget(this);
    layout_orari -> addWidget(spazio, 1);

    QLabel* etichetta_fine = new QLabel("Ora di fine: ", this);
    layout_orari -> addWidget(etichetta_fine, 1);

    selettore_fine = new QDateTimeEdit(this);
    selettore_fine -> setDateTime(QDateTime::currentDateTime());
    layout_orari -> addWidget(selettore_fine, 1);

    layout_principale -> addLayout(layout_orari);

    etichetta_luogo = new QLineEdit(this);
    etichetta_luogo -> setPlaceholderText("Inserire luogo: ");
    layout_principale -> addWidget(etichetta_luogo);

    setLayout(layout_principale);
}

mini_dto_impegno form_impegno::salva_dati() const {
    mini_dto_impegno i;
    i.inizio = selettore_inizio -> dateTime();
    i.fine = selettore_fine -> dateTime();
    i.luogo = etichetta_luogo -> text();

    return i;
}

void form_impegno::set_dati(const dati_impegno& i) {
    selettore_inizio -> setDateTime(i.inizio);
    selettore_fine -> setDateTime(i.fine);
    etichetta_luogo -> setText(i.luogo);
}

void form_impegno::reset() {
    selettore_inizio -> setDateTime(QDateTime::currentDateTime());
    selettore_fine -> setDateTime(QDateTime::currentDateTime());
}

////////////////////////////////////////////////////////////////////////////

form_scadenza::form_scadenza(QWidget* parent): QWidget(parent) {
    
    QHBoxLayout* layout_principale = new QHBoxLayout(this);

    QLabel* etichetta_tempo_limite = new QLabel("Limite: ", this);
    layout_principale -> addWidget(etichetta_tempo_limite);

    selettore_tempo_limite = new QDateTimeEdit(this);
    selettore_tempo_limite -> setDateTime(QDateTime::currentDateTime());
    layout_principale -> addWidget(selettore_tempo_limite);

    QWidget* spazio = new QWidget(this);
    layout_principale -> addWidget(spazio);

    QLabel* etichetta_completamento = new QLabel("Completato: ", this);
    layout_principale -> addWidget(etichetta_completamento);

    setLayout(layout_principale);
}

mini_dto_scadenza form_scadenza::salva_dati() const {
    mini_dto_scadenza s;
    s.limite = selettore_tempo_limite -> dateTime();
    return s;
}

void form_scadenza::set_dati(const dati_scadenza& s) {
    selettore_tempo_limite -> setDateTime(s.limite);
}

void form_scadenza::reset() {
    selettore_tempo_limite -> setDateTime(QDateTime::currentDateTime());
}

////////////////////////////////////////////////////////////////////////////

form_routine::form_routine(QWidget* parent): QWidget(parent) {

    QHBoxLayout* layout_principale = new QHBoxLayout(this);

    QLabel* etichetta_inizio = new QLabel("Inizio: ", this);
    layout_principale -> addWidget(etichetta_inizio);

    selettore_inizio = new QDateTimeEdit(this);
    selettore_inizio -> setDateTime(QDateTime::currentDateTime());
    layout_principale -> addWidget(selettore_inizio);

    QWidget* spazio = new QWidget(this);
    layout_principale -> addWidget(spazio);

    QLabel* etichetta_intervallo = new QLabel("Intervallo: ", this);
    layout_principale -> addWidget(etichetta_intervallo);

    selettore_intervallo = new QSpinBox(this);
    layout_principale -> addWidget(selettore_intervallo);

    setLayout(layout_principale);
}

mini_dto_routine form_routine::salva_dati() const {
    mini_dto_routine r;
    r.inizio = selettore_inizio -> dateTime();
    r.intervallo = selettore_intervallo -> value();

    return r;
}

void form_routine::set_dati(const dati_routine& r) {
    selettore_inizio -> setDateTime(r.inizio);
    selettore_intervallo -> setValue(r.intervallo);
}

void form_routine::reset() {
    selettore_inizio -> setDateTime(QDateTime::currentDateTime());
    selettore_intervallo -> setValue(0);
}