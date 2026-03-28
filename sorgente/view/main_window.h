#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "home/home_view.h"
#include "detail/detail_view.h"

#include <QMainWindow>
#include <QStackedLayout>


class main_window : public QWidget {
    Q_OBJECT

    private:
        QStackedLayout* stacked_layout;
        home_view* home_window;
        detail_view* detail_window;

    
    public:
        main_window(QWidget* parent = nullptr);
        ~main_window() = default;

};


#endif