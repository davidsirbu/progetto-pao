#ifndef VISITOR_FILTRO_H
#define VISITOR_FILTRO_H

#include "../model/visitor.h"
#include "../extra/dto.h"
#include <vector>

class impegno;
class scadenza;
class routine;

class visitor_filtro: public visitor {
    private:
        std::vector<dati_impegno> lista_impegni;
        std::vector<dati_scadenza> lista_scadenze;
        std::vector<dati_routine> lista_routine;

        QString converti_enum(Gruppo e) const;

    public:
        ~visitor_filtro() = default;

        void visit(impegno& i) override;
        void visit(scadenza& v) override;
        void visit(routine& r) override;

        const std::vector<dati_impegno>& get_impegni() const;
        const std::vector<dati_scadenza>& get_scadenze() const;
        const std::vector<dati_routine>& get_routine() const;

        void reset();
};

#endif