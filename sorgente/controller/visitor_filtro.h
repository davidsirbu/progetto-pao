#ifndef VISITOR_FILTRO_H
#define VISITOR_FILTRO_H

#include "../model/visitor.h"
#include <vector>

class impegno;
class scadenza;
class routine;

class visitor_filtro: public visitor {
    private:
        std::vector<impegno*> lista_impegni;
        std::vector<scadenza*> lista_scadenze;
        std::vector<routine*> lista_routine;

    public:
        ~visitor_filtro() = default;

        void visit(impegno& i) override;
        void visit(scadenza& v) override;
        void visit(routine& r) override;

        const std::vector<impegno*>& get_impegni() const;
        const std::vector<scadenza*>& get_scadenze() const;
        const std::vector<routine*>& get_routine() const;

        void reset();
};

#endif