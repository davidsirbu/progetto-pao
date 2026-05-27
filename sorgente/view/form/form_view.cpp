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

void form_view::reset() {
    id.clear();
    etichetta_titolo -> setText("");
    parte_scelta -> reset();
    etichetta_descrizione -> setText("");
}

void form_view::controlla_stringa(const QString& input) {
    if (input.trimmed().isEmpty()) pulsante_salva -> setEnabled(false);
    else pulsante_salva -> setEnabled(true);
}

form_view::form_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout_principale = new QVBoxLayout();

    titolo_finestra = new QLabel();
    layout_principale -> addWidget(titolo_finestra);

    etichetta_titolo = new QLineEdit();
    etichetta_titolo -> setPlaceholderText("Inserisci il titolo (obbligatorio)");
    layout_principale -> addWidget(etichetta_titolo);
    connect(etichetta_titolo, &QLineEdit::textChanged, this, &form_view::controlla_stringa);

    menu_gruppo = new QComboBox(this);
    menu_gruppo -> addItem("Studio");
    menu_gruppo -> addItem("Lavoro");
    menu_gruppo -> addItem("Hobby");
    menu_gruppo -> addItem("Altro");
    layout_principale -> addWidget(menu_gruppo);

    parte_scelta = new form_scelta(this);
    layout_principale -> addWidget(parte_scelta);

    etichetta_descrizione = new QTextEdit();
    etichetta_descrizione -> setPlaceholderText("Inserisci la descrizione");
    layout_principale -> addWidget(etichetta_descrizione);

    QHBoxLayout* action_layout = new QHBoxLayout();

    QWidget* spaziatore = new QWidget();
    action_layout -> addWidget(spaziatore, 4);

    pulsante_salva = new QPushButton("Salva", this);
    pulsante_salva -> setEnabled(false);
    connect(pulsante_salva, &QPushButton::clicked, this, &form_view::salva);
    action_layout -> addWidget(pulsante_salva, 1);

    pulsante_annulla = new QPushButton("Annulla", this);
    connect(pulsante_annulla, &QPushButton::clicked, this, &form_view::annulla);
    action_layout -> addWidget(pulsante_annulla, 1);

    layout_principale -> addLayout(action_layout);

    setLayout(layout_principale);
}

void form_view::imposta_titolo_finestra(const QString& titolo) {
    titolo_finestra -> setText(titolo);
}

void form_view::salva() {
    if (parte_scelta -> stato_stacked() == 0) {
        dati_impegno impegno;
        impegno.id = id;
        impegno.nome = etichetta_titolo -> text();
        impegno.categoria = menu_gruppo -> currentText();
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
        scadenza.categoria = menu_gruppo -> currentText();
        scadenza.descrizione = etichetta_descrizione -> toPlainText();
        mini_dto_scadenza mini = parte_scelta -> ricevi_dati_scadenza();
        scadenza.limite = mini.limite;

        emit salva_scadenza(scadenza);
    }
    else if (parte_scelta -> stato_stacked() == 2) {
        dati_routine routine;
        routine.id = id;
        routine.nome = etichetta_titolo -> text();
        routine.categoria = menu_gruppo -> currentText();
        routine.descrizione = etichetta_descrizione -> toPlainText();
        mini_dto_routine mini = parte_scelta -> ricevi_dati_routine();
        routine.inizio = mini.inizio;
        routine.intervallo = mini.intervallo;

        emit salva_routine(routine);
    }
    reset();
    parte_scelta -> attiva_pulsanti();
    emit torna_indietro();
}

void form_view::annulla() {
    reset();
    parte_scelta -> attiva_pulsanti();
    emit torna_indietro();
}

void form_view::carica_impegno(const dati_impegno& i) {
    parte_scelta -> disattiva_pulsanti();
    id = i.id;
    etichetta_titolo -> setText(i.nome);
    menu_gruppo -> setCurrentIndex(menu_gruppo -> findText(i.categoria));
    etichetta_descrizione -> setText(i.descrizione);
    parte_scelta -> inoltra_dati(i);
}

void form_view::carica_scadenza(const dati_scadenza& s) {
    parte_scelta -> disattiva_pulsanti();
    id = s.id;
    etichetta_titolo -> setText(s.nome);
    menu_gruppo -> setCurrentIndex(menu_gruppo -> findText(s.categoria));
    etichetta_descrizione -> setText(s.descrizione);
    parte_scelta -> inoltra_dati(s);
}

void form_view::carica_routine(const dati_routine& r) {
    parte_scelta -> disattiva_pulsanti();
    id = r.id;
    etichetta_titolo -> setText(r.nome);
    
    menu_gruppo -> setCurrentIndex(menu_gruppo -> findText(r.categoria));
    etichetta_descrizione -> setText(r.descrizione);
    parte_scelta -> inoltra_dati(r);
}