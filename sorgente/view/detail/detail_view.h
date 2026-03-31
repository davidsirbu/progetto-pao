#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include <QWidget>

class detail_header;
class detail_corpo;

class detail_view: public QWidget {
    Q_OBJECT

    private:
        detail_header* header;
        detail_corpo* corpo;

    public:
        detail_view(QWidget* parent = nullptr);
        ~detail_view() = default;

    signals:
        void torna_indietro();
};

#endif