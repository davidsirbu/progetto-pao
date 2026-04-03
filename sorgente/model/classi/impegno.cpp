#include "impegno.h"
#include "../visitor.h"

impegno::impegno(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const QDateTime& f, const QString& l) : attivita(n, d, c), inizio(i), fine(f), luogo(l) {}

dati_impegno impegno::get_dati() const {
    dati_impegno i;
    i.nome = get_nome();
    i.descrizione = get_descrizione();
    i.categoria = get_categoria();
    i.inizio = inizio;
    i.fine = fine;
    i.luogo = luogo; 
}

void impegno::set_dati(dati_impegno& i) {
    set_nome(i.nome);
    set_descrizione(i.descrizione);
    set_categoria(i.categoria);
    inizio = i.inizio;
    fine = i.fine;
    luogo = i.luogo;
}

QString impegno::calcolo_durata() const {
    int secondi = inizio.secsTo(fine);
    
    int ore = secondi / 3600;
    int minuti = secondi / 60;

    return QString("%1h %2m").arg(ore).arg(minuti);
}

Fase impegno::calcola_stato() const {
    QDateTime attuale = QDateTime::currentDateTime();

    if (attuale.secsTo(fine) < 0) return Fase::Scaduto;
    if (attuale.secsTo(inizio) > 0) return Fase::DaFare;
    return Fase::InCorso; 
}

void impegno::accetta(visitor& v) {
    v.visit(*this);
}