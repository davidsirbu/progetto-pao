#include "form_view.h"
#include "form_scelta.h"
#include "../../extra/dto.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

form_view::form_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout_principale = new QVBoxLayout(this);

    QLabel* titolo_finestra = new QLabel("Crea/Modifica attività", this);
    layout_principale -> addWidget(titolo_finestra);

    etichetta_titolo = new QLineEdit(this);
    etichetta_titolo -> setPlaceholderText("Inserisci il titolo");
    layout_principale -> addWidget(etichetta_titolo);

    menu_gruppo = new QComboBox(this);
    layout_principale -> addWidget(menu_gruppo);

    parte_scelta = new form_scelta(this);
    layout_principale -> addWidget(parte_scelta);

    etichetta_descrizione = new QTextEdit(this);
    etichetta_descrizione -> setPlaceholderText("Inserisci la descrizione");
    layout_principale -> addWidget(etichetta_descrizione);

    QHBoxLayout* action_layout = new QHBoxLayout(this);

    QWidget* spaziatore = new QWidget(this);
    action_layout -> addWidget(spaziatore, 4);

    pulsante_salva = new QPushButton("Salva", this);
    connect(pulsante_salva, &QPushButton::clicked, this, form_view::salva);
    action_layout -> addWidget(pulsante_salva, 1);

    pulsante_annulla = new QPushButton("Annulla", this);
    connect(pulsante_annulla, &QPushButton::clicked, this, form_view::annulla);
    action_layout -> addWidget(pulsante_annulla, 1);

    layout_principale -> addLayout(action_layout);

    setLayout(layout_principale);
}

void form_view::reset() {
    id.clear();
    etichetta_titolo -> setText("");
    parte_scelta -> reset();
    etichetta_descrizione -> setText("");
}

void form_view::salva() {
    if (parte_scelta -> stato_stacked() == 0) {
        dati_impegno impegno;
        impegno.id = id;
        impegno.nome = etichetta_titolo -> text();
        impegno.descrizione = etichetta_descrizione -> toPlainText();
        mini_dto_impegno mini = parte_scelta -> ricevi_dati_impegno();
        impegno.inizio = mini.inizio;
        impegno.fine = mini.fine;
        impegno.luogo = mini.luogo;
        
        emit salva_impegno(impegno);
    }
    else if (parte_scelta -> stato_stacked() == 1) {
        dati_scadenza scadenza;
        scadenza.id = id;
        scadenza.nome = etichetta_titolo -> text();
        scadenza.descrizione = etichetta_descrizione -> toPlainText();
        mini_dto_scadenza mini = parte_scelta -> ricevi_dati_scadenza();
        scadenza.limite = mini.limite;

        emit salva_scadenza(scadenza);
    }
    else if (parte_scelta -> stato_stacked() == 2) {
        dati_routine routine;
        routine.id = id;
        routine.nome = etichetta_titolo -> text();
        routine.descrizione = etichetta_descrizione -> toPlainText();
        mini_dto_routine mini = parte_scelta -> ricevi_dati_routine();
        routine.inizio = mini.inizio;
        routine.intervallo = mini.intervallo;

        emit salva_routine(routine);
    }
    reset();
    emit torna_indietro();
}

void form_view::annulla() {
    reset();
    emit torna_indietro();
}

void form_view::carica_impegno(const dati_impegno& i) {
    id = i.id;
    etichetta_titolo -> setText(i.nome);
    etichetta_descrizione -> setText(i.descrizione);
    parte_scelta -> inoltra_dati_impegno(i);
}

void form_view::carica_scadenza(const dati_scadenza& s) {
    id = s.id;
    etichetta_titolo -> setText(s.nome);
    etichetta_descrizione -> setText(s.descrizione);
    parte_scelta -> inoltra_dati_scadenza(s);
}

void form_view::carica_routine(const dati_routine& r) {
    id = r.id;
    etichetta_titolo -> setText(r.nome);
    etichetta_descrizione -> setText(r.descrizione);
    parte_scelta -> inoltra_dati_routine(r);
}