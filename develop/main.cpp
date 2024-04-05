#include "frontend/dialog.h"
//#include "frontend/menuManager.h"
#include "backend/include/mainBack.h"

#include <QApplication>

#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Deviсe activ;
    //Dialog window;
    //Deviсe *activ = new Device();
    Dialog window(activ);
    //MenuManager mainWindow(&window);
    window.show();
    return app.exec();
}
