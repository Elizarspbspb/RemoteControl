#ifndef NEWDEVISE_H
#define NEWDEVISE_H

#include <QDialog>

//#include "./ui_addNewDev.h"

#include "../backend/include/mainBack.h"

#include <iostream>

QT_BEGIN_NAMESPACE
//namespace Ui1 { class DialogNewDev; }
namespace Ui { class DialogNewDev; }
QT_END_NAMESPACE


class DialogNewDev : public QDialog {
    Q_OBJECT

private:
    //Ui::NewDevise *uidev;
    Ui::DialogNewDev *uidev;
    //Ui1::DialogNewDev *uidev;
    //Deviсe& nwDev;
    Deviсe nwDev;

public:
    DialogNewDev(Deviсe nwDev, QWidget *parent = nullptr);
    uint addNewDevice();
    ~DialogNewDev();

private slots:
    void on_addPushButton_clicked();

signals:

private slots:
    void on_DialogNewDev_finished(int result);
    void on_cancelPushButton_clicked();
};

#endif // NEWDEVISE_H
