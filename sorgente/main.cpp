#include <QApplication>

#include "model/gestore.h"
#include "view/main_view.h"
#include "controller/controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    gestore gestore_attivita;
    main_view main_window;

    controller controller_applicazione(&gestore_attivita, &main_window);

    main_window.show();
    return app.exec();
}