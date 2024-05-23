#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

//#include "../backend/include/mainBack.h"
#include "newdevise.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

private:
    Ui::Dialog *ui;
    Deviсe& dev;
    //const Deviсe defaultDevice2;
    //unordered_map<int, QString> photoDev;
    unordered_map<QString, QString> photoDev;

public:
    //Dialog(QWidget *parent = nullptr);
    //Dialog(QWidget *parent = nullptr, Deviсe &dev = defaultDevice);
    //Dialog(Deviсe &dev = defaultDevice, QWidget *parent = nullptr);
    Dialog(Deviсe &dev, QWidget *parent = nullptr);

    //uint addNewDevice();
    //void changeIndexPhoto(int);
    ~Dialog();

private slots:
    void on_deleteDevise_clicked();

private slots:
    void on_comboBoxDevice_activated(const QString &arg1);

private slots:
    void on_exitButton_clicked();

private slots:
    void on_addNewDevise_clicked();

    //void on_comboBoxDevice_activated(int index);
};
#endif // DIALOG_H
