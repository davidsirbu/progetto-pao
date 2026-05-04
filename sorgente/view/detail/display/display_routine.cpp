#include "display_routine.h"

display_routine::display_routine(const dati_routine& dto, const QDateTime& l, const int n): display_astratto(dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Inizio: ", l.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Intervallo: ", QString::number(n));
}