#include "display_impegno.h"

display_impegno::display_impegno(const dati_impegno& dto): display_astratto(dto.id, dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Inizio: ", dto.inizio.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Fine: ", dto.fine.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Durata: ", dto.durata);
    aggiungi_riga_al_form("Luogo: ", dto.luogo);
}