#include "frontend/dialog.h"
//#include "frontend/menuManager.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Dialog window;
    //MenuManager mainWindow(&window);
    window.show();
    return app.exec();
}
