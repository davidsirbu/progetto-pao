#ifndef HOME_CORPO_H
#define HOME_CORPO_H

#include "../../extra/enums.h"
#include <vector>
#include <QWidget>

class impegno;
class scadenza;
class routine;
class QListWidget;
class QVBoxLayout;

class home_corpo: public QWidget {
    Q_OBJECT

    private:
        QListWidget* lista_impegni;
        QListWidget* lista_scadenze;
        QListWidget* lista_routine;
    
        QVBoxLayout* crea_colonna(const QString& nome_attivita, QListWidget* lista);
        void carica_impegni(const std::vector<impegno*>& i) const;
        void carica_scadenze(const std::vector<scadenza*>& s) const;
        void carica_routine(const std::vector<routine*>& r) const;
        QString converti_enum(const Gruppo e) const;

        void aggiorna_stato_pulsanti();

    public:
        home_corpo(QWidget* parent = nullptr);
        ~home_corpo() = default;

        void aggiorna_liste(const std::vector<impegno*>& i, 
                            const std::vector<scadenza*>& s, 
                            const std::vector<routine*>& r) const;

        QString get_id_selezionato() const;

    signals:
        void cambio_selezione();

    public slots:
        void impegno_cliccato();
        void scadenza_cliccata();
        void routine_cliccata();
};

#endif