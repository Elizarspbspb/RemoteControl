#ifndef NEWDEVISE_H
#define NEWDEVISE_H

#include <QDialog>

//#include "./ui_addNewDev.h"

#include "../backend/include/mainBack.h"

class MainDialog;
class Deviсe;

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogNewDev; }
//namespace Ui { class Dialog; }      // new
//namespace Ui { class MainDialog; }      // new
QT_END_NAMESPACE

class DialogNewDev : public QDialog {
    Q_OBJECT

private:
    //Ui::NewDevise *uidev;
    Ui::DialogNewDev *uidev;
    //Ui::Dialog *uimain;  // new
    //Ui1::DialogNewDev *uidev;
    //Deviсe& nwDev;
    Deviсe newDev;
    //Deviсe *salkaDev;
    MainDialog &dia;

public:
    //DialogNewDev(Deviсe nwDev, QWidget *parent = nullptr,  Dialog);
    //DialogNewDev(Deviсe, Ui::MainDialog, QWidget *parent = nullptr);
    DialogNewDev(Deviсe &, MainDialog&, QWidget *parent = nullptr);
    uint addNewDevice();
    ~DialogNewDev();

private slots:
    void on_addPushButton_clicked();
    void on_DialogNewDev_finished(int result);
    void on_cancelPushButton_clicked();

};

#endif // NEWDEVISE_H
