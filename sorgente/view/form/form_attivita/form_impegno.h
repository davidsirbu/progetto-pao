#ifndef FORM_IMPEGNO_H
#define FORM_IMPEGNO_H

#include <QWidget>
#include <QDateTimeEdit>

class form_impegno: public QWidget {
    Q_OBJECT

    private:
    QDateTimeEdit* selettore_inizio;
    QDateTimeEdit* selettore_fine;
    QLineEdit* etichetta_luogo;

    public:
        form_impegno(QWidget* parent);
        ~form_impegno() = default;

    
};

#endif