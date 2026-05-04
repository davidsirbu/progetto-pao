#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include "../../extra/dto.h"
#include <vector>
#include <QWidget>

class impegno;
class scadenza;
class routine;
class home_header;
class home_corpo;

class home_view: public QWidget {
    Q_OBJECT

    private:
        home_header* header;
        home_corpo* corpo;

    public:
        home_view(QWidget* parent = nullptr);
        ~home_view() = default;

        void passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const;
    
    signals:
        void crea_attivita();
        void segnale_dettagli(const QString& id, bool modifica);
        void segnale_elimina(const QString& id);
    
    public slots:
        void attivita_selezionata();
        void mostra_dettagli();
        void modifica_attivita();
        void elimina_attivita();
};

#endif