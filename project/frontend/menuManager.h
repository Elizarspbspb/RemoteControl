#ifndef MENUMANAGER_H
#define MENUMANAGER_H

//#include <QObject>
//#include <QWidget>
#include <QtWidgets>

class MenuManager : public QObject {
    Q_OBJECT
public:
    explicit MenuManager(QObject *parent = nullptr);
    ~MenuManager();

private:
    void createMenu();
    QDialog *parentDialog;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *openAction;
    QAction *saveAction;

signals:

};

#endif // MENUMANAGER_H
