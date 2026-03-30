#include "attivita.h" 
#include <QString>

attivita::attivita(const QString& n, const QString& d, const Gruppo c) : id(QUuid::createUuid().toString()), nome(n), descrizione(d), categoria(c) {};

QString attivita::get_nome() const {
    return nome;
}

QString attivita::get_descrizione() const {
    return descrizione;
}

Gruppo attivita::get_categoria() const {
    return categoria;
}

QString attivita::get_id() const {
    return id;
}

void attivita::set_nome(const QString& n) {
    nome = n;
}

void attivita::set_descrizione(const QString& d) {
    descrizione = d;
}

void attivita::set_categoria(const Gruppo c) {
    categoria = c;
}