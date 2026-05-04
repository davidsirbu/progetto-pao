#ifndef DETAIL_HEADER_H
#define DETAIL_HEADER_H

#include <QWidget>

class QPushButton;
class QLineEdit;

class detail_header: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_indietro;
        QPushButton* pulsante_modifica;

    public:
        detail_header(QWidget* parent);
        ~detail_header() = default;

    signals:
        void torna_indietro();
        void modifica_attivita();

};

#endif