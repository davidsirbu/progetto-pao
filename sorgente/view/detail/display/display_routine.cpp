#include "display_routine.h"

display_routine::display_routine(const dati_routine& dto): display_astratto(dto.id, dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Inizio: ", dto.inizio.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Intervallo: ", QString::number(dto.intervallo));
}