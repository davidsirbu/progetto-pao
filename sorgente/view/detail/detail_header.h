#ifndef DETAIL_HEADER_H
#define DETAIL_HEADER_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class detail_header: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_indietro;
        QLineEdit* barra_ricerca;

    public:
        detail_header(QWidget* parent);
        ~detail_header() = default;

    signals:
        void torna_indietro();

};

#endif