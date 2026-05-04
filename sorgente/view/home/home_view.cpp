#include "home_view.h"
#include "home_header.h"
#include "home_corpo.h"
#include <QVBoxLayout>

home_view::home_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* home_layout = new QVBoxLayout(this);

    header = new home_header(this);
    home_layout -> addWidget(header);
    connect(header, &home_header::crea_attivita, this, &home_view::crea_attivita);
    connect(header, &home_header::modifica_attivita, this, &home_view::modifica_attivita);
    connect(header, &home_header::elimina_attivita, this, &home_view::elimina_attivita);

    corpo = new home_corpo(this);
    connect(corpo, &home_corpo::cambio_selezione, this, &home_view::attivita_selezionata);
    connect(corpo, &home_corpo::doppio_click_su_attivita, this, &home_view::mostra_dettagli);
    home_layout -> addWidget(corpo);

    connect(header, &home_header::barra_cambiata, corpo, &home_corpo::filtra_liste);

    setLayout(home_layout);
}

void home_view::passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const {
    corpo -> aggiorna_liste(i, s, r);
}

void home_view::attivita_selezionata() {
    header -> attiva_pulsanti();
}

void home_view::mostra_dettagli() {
    emit segnale_dettagli(corpo -> get_id_selezionato(), false);
}

void home_view::modifica_attivita() {
    emit segnale_dettagli(corpo -> get_id_selezionato(), true);
}

void home_view::elimina_attivita() {
    emit segnale_elimina(corpo -> get_id_selezionato());
    header -> disattiva_pulsanti();
}