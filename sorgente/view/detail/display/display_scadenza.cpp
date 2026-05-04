#include "display_scadenza.h"

display_scadenza::display_scadenza(const dati_scadenza& dto, const QDateTime& l): display_astratto(dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Limite: ", l.toString("dd/MM/yyyy HH:mm"));
}