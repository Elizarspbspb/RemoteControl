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
    unordered_map<QString, QString> photoDev;

public:
    Dialog(Deviсe &dev, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_deleteDevise_clicked();

private slots:
    void on_comboBoxDevice_activated(const QString &arg1);

private slots:
    void on_exitButton_clicked();

private slots:
    void on_addNewDevise_clicked();
};
#endif // DIALOG_H
