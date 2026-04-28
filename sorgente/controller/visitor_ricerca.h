#ifndef VISITOR_RICERCA_H
#define VISITOR_RICERCA_H

#include "../model/visitor.h"
#include "../extra/dto.h"
#include <QString>

class visitor_ricerca: public visitor {
    private:
        dati_impegno dto_impegno;
        dati_scadenza dto_scadenza;
        dati_routine dto_routine;

        QString converti_enum(Gruppo s) const;

    public:
        ~visitor_ricerca() = default;

        void visit(impegno& i) override;
        void visit(scadenza& v) override;
        void visit(routine& r) override;

        dati_impegno get_impegno();
        dati_scadenza get_scadenza();
        dati_routine get_routine();

        void reset();
};

#endif