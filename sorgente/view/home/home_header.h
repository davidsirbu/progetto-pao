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
        QLineEdit* barra_ricerca;
        
    public:
        home_header(QWidget* parent = nullptr);
        ~home_header() = default;

        void attiva_pulsanti();
        void disattiva_pulsanti();

    signals:
        void crea_attivita();
        void modifica_attivita();
        void elimina_attivita();

        void barra_cambiata(const QString& s);
};

#endif