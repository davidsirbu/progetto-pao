#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include <vector>
#include <QWidget>

class impegno;
class scadenza;
class routine;
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

        void passa_liste(const std::vector<impegno*>& i, const std::vector<scadenza*>& s, const std::vector<routine*>& r) const;
    
    signals:
        void crea_attivita();
};

#endif