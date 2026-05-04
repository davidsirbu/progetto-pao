#ifndef VISITOR_RICERCA_H
#define VISITOR_RICERCA_H

#include "../model/visitor.h"
#include "../extra/dto.h"
#include <QString>

class main_window;

class visitor_ricerca: public visitor {
    private:
        main_window* m;
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

        dati_impegno get_impegno();
        dati_scadenza get_scadenza();
        dati_routine get_routine();

        void set_stato(bool x);

        void set_window(main_window* w);

        void reset();
};

#endif