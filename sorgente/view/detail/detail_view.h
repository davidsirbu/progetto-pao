#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include "detail_header.h"
#include "detail_corpo.h"
#include <QWidget>

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