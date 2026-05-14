#ifndef HOME_HEADER_H
#define HOME_HEADER_H

#include <QWidget>

class QPushButton;
class QLineEdit;

class home_header: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_nuova_attivita;
        QPushButton* pulsante_modifica_attivita;
        QPushButton* pulsante_elimina_attivita;
        QPushButton* pulsante_salvataggio_automatico;
        QPushButton* pulsante_salvataggio_manuale;
        QPushButton* pulsante_caricamento_dati;
        QLineEdit* barra_ricerca;
        
    public:
        home_header(QWidget* parent = nullptr);
        ~home_header() = default;

        void attiva_pulsanti();
        void disattiva_pulsanti();

        void salvataggio_automatico();
        void salvataggio_manuale();

        void abilita_salvataggio_automatico();

    signals:
        void crea_attivita();
        void modifica_attivita();
        void elimina_attivita();
        void segnale_salvataggio(bool manuale);
        void carica_dati();

        void barra_cambiata(const QString& s);
};

#endif