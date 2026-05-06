#ifndef VISITOR_RICERCA_H
#define VISITOR_RICERCA_H

#include "../model/visitor.h"
#include "../extra/dto.h"
#include <QObject>
#include <QString>

class main_view;

class visitor_ricerca: public QObject, public visitor {
    Q_OBJECT

    private:
        dati_impegno dto_impegno;
        dati_scadenza dto_scadenza;
        dati_routine dto_routine;
        bool stato;

        QString converti_enum(Gruppo s) const;

    public:
        ~visitor_ricerca() = default;

        void visit(impegno& i) override;
        void visit(scadenza& v) override;
        void visit(routine& r) override;

        bool get_stato();
        void set_stato(bool x);

        void reset();

    signals:
        void trovato_impegno(const dati_impegno& i, bool modifica);
        void trovata_scadenza(const dati_scadenza& s, bool modifica);
        void trovata_routine(const dati_routine& r, bool modifica);
};

#endif