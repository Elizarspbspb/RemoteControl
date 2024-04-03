#include "menuManager.h"

MenuManager::MenuManager(QDialog *parent) : QObject(parent), parentDialog(parent) {
    menuBar = new QMenuBar(parentDialog);
    createMenu();
    parentDialog->setLayout(new QVBoxLayout);
    parentDialog->layout()->setMenuBar(menuBar);
}

MenuManager::~MenuManager() {}

void MenuManager::createMenu() {
    fileMenu = menuBar->addMenu("Файл");
    openAction = fileMenu->addAction("Открыть");
    saveAction = fileMenu->addAction("Сохранить");
}
