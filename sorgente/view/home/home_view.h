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

        void passa_liste(const std::vector<dati_impegno>& i,
                         const std::vector<dati_scadenza>& s,
                         const std::vector<dati_routine>& r) const;
        
        void abilita_salvataggio_automatico();
    
    signals:
        // FLUSSO: main_view <-- home_view
        // (Emessi dal home_header, connessi nel costruttore)
        void crea_attivita();
        void segnale_salvataggio(bool manuale);
        void carica_dati();

        // FLUSSO: main_view <-- home_view
        // (Emessi dagli slot corrispondenti)
        void segnale_dettagli(const QString& id, bool modifica);
        void segnale_elimina(const QString& id);
        
        // FLUSSO: main_view <-- home_view
        // (Emesso da home_corpo)
        void attivita_completata(const QString& id);
    
    public slots:
        // Connessi con i segnali di home_corpo
        void attivita_selezionata();
        void mostra_dettagli();

        // Connessi con i segnali di home_header
        void modifica_attivita();
        void elimina_attivita();
};

#endif