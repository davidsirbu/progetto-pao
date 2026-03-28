#ifndef HOME_HEADER_H
#define HOME_HEADER_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class home_header: public QWidget {
    Q_OBJECT

    private:
        QPushButton* nuova_attivita;
        QPushButton* importa_file;
        QPushButton* esporta_file;
        QLineEdit* barra_ricerca;
        

    public:
        home_header(QWidget* parent = nullptr);
        ~home_header() = default;
};

#endif