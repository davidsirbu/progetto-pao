#include <QApplication>

#include "view/main_window.h"

int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);
    main_window m;
    m.show();
    return app.exec();
}