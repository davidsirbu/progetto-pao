#include "display_routine.h"

display_routine::display_routine(const dati_routine& dto): display_astratto(dto.id, dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Inizio: ", dto.inizio.toString("dd/MM/yyyy"));
    aggiungi_riga_al_form("Prossima volta: ", dto.prossima_volta.toString("dd/MM/yyyy"));
    aggiungi_riga_al_form("Intervallo: ", QString::number(dto.intervallo));
    aggiungi_riga_al_form("Volte di completamento puntuale: ", QString::number(dto.volte_puntuale));
    aggiungi_riga_al_form("Volte di completamento in ritardo: ", QString::number(dto.volte_ritardo));
}