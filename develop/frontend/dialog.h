#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "../backend/include/mainBack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

private:
    Ui::Dialog *ui;
    Deviсe& dev;
    //const Deviсe defaultDevice2;

public:
    //Dialog(QWidget *parent = nullptr);
    //Dialog(QWidget *parent = nullptr, Deviсe &dev = defaultDevice);
    //Dialog(Deviсe &dev = defaultDevice, QWidget *parent = nullptr);
    Dialog(Deviсe &dev, QWidget *parent = nullptr);

    uint addNewDevice();
    void changeIndexPhoto(int);
    ~Dialog();

private slots:
    void on_addNewDevise_clicked();

    void on_comboBoxDevice_activated(int index);
};
#endif // DIALOG_H
