#ifndef FORM_SCELTA_H
#define FORM_SCELTA_H

#include <QWidget>

class QPushButton;
class QStackedLayout;
class form_impegno;
class form_scadenza;
class form_routine;

class form_scelta: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_impegno;
        QPushButton* pulsante_scadenza;
        QPushButton* pulsante_routine;
        QStackedLayout* stacked_layout;
        form_impegno* impegno_window;
        form_scadenza* scadenza_window;
        form_routine* routine_window;
        
    public:
        form_scelta(QWidget* parent);
        ~form_scelta() = default;

    public slots:
        void cambia_in_impegno();
        void cambia_in_scadenza();
        void cambia_in_routine();
};

#endif