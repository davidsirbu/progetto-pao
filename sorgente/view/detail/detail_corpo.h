#ifndef DETAIL_CORPO_H
#define DETAIL_CORPO_H

#include "display/display_view.h"
#include <QWidget>
#include <QListWidget>

class detail_corpo: public QWidget {
    Q_OBJECT

    private:
        QListWidget* lista;
        display_view* display_window;

    public:
        detail_corpo(QWidget* parent);
        ~detail_corpo() = default;
};

#endif