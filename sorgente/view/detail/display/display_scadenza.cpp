#include "display_scadenza.h"

display_scadenza::display_scadenza(const dati_scadenza& dto): display_astratto(dto.id, dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Limite: ", dto.limite.toString("dd/MM/yyyy HH:mm"));
}