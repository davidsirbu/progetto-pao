#include "display_impegno.h"

display_impegno::display_impegno(const dati_impegno& dto, const QDateTime& i, const QDateTime& f, const QString& l): display_astratto(dto.nome, dto.categoria, dto.descrizione) {

    aggiungi_riga_al_form("Inizio: ", i.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Fine: ", f.toString("dd/MM/yyyy HH:mm"));
    aggiungi_riga_al_form("Luogo: ", l);
}