#ifndef VISITOR_MODIFICA_H
#define VISITOR_MODIFICA_H

#include "../model/visitor.h"
#include "../extra/dto.h"

class visitor_modifica: public visitor {
    private:
        dati_impegno dati_i;
        dati_scadenza dati_s;
        dati_routine dati_r;

        Gruppo converti_stringa_in_enum(const QString& s) const;

    public:
        visitor_modifica() = default;
        ~visitor_modifica() = default;

        void set_dati_impegno(const dati_impegno& i);
        void set_dati_scadenza(const dati_scadenza& s);
        void set_dati_routine(const dati_routine& r);

        void reset();

        void visit(impegno& i) override;
        void visit(scadenza& s) override;
        void visit(routine& r) override;
};

#endif