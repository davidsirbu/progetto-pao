#ifndef HOME_VIEW_H
#define HOME_VIEW_H


#include <QWidget>

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
    
    signals:
        void crea_attivita();
};

#endif