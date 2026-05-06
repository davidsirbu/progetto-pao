#include "impegno.h"
#include "../visitor.h"

impegno::impegno(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const QDateTime& f, const QString& l) : attivita(n, d, c), inizio(i), fine(f), luogo(l) {}

QDateTime impegno::get_inizio() const {
    return inizio;
}

QDateTime impegno::get_fine() const {
    return fine;
}

QString impegno::get_luogo() const {
    return luogo;
}

void impegno::set_inizio(const QDateTime& i) {
    inizio = i;
}

void impegno::set_fine(const QDateTime& f) {
    fine = f;
}

void impegno::set_luogo(const QString& l) {
    luogo = l;
}

QString impegno::calcolo_durata() const {
    int secondi = inizio.secsTo(fine);
    int giorni = secondi / 86400;
    int ore = (secondi % 86400) / 3600;
    int minuti = (secondi % 3600) / 60;
    
    if (giorni > 0) return QString("%1d %2h %3m").arg(giorni).arg(ore).arg(minuti);
    else return QString("%1h %2m").arg(ore).arg(minuti);
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

QJsonObject impegno::salva_in_json() const {
    QJsonObject oggetto_json;

    oggetto_json["tipo"] = "impegno";
    oggetto_json["id"] = get_id();
    oggetto_json["nome"] = get_nome();
    oggetto_json["categoria"] = static_cast<int>(get_categoria());
    oggetto_json["inizio"] = inizio.toString();
    oggetto_json["fine"] = fine.toString();
    oggetto_json["luogo"] = luogo;

    return oggetto_json;
}