#ifndef DISPLAY_VARIABILE_H
#define DISPLAY_VARAIBILE_H

#include <QWidget>

class display_impegno: public QWidget {
    Q_OBJECT

    private:

    
    public:
        display_impegno(QWidget* parent);
        ~display_impegno() = default;
};

class display_scadenza: public QWidget {
    Q_OBJECT

    private:


    public:
        display_scadenza(QWidget* parent);
        ~display_scadenza() = default;
};

class display_routine: public QWidget {
    Q_OBJECT

    private:


    public:
        display_routine(QWidget* parent);
        ~display_routine() = default;
};

#endif