#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

//#include "../backend/include/mainBack.h"
#include "newdevise.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class MainDialog : public QDialog {
    Q_OBJECT

private:
    //MainDialog *ui;
    Ui::Dialog *ui;
    Deviсe& dev;
    unordered_map<QString, QString> photoDev;

public:
    MainDialog(Deviсe &dev, QWidget *parent = nullptr);
    void updateViewDevises();
    void clearView();
    ~MainDialog();

private slots:
    void on_deleteDevise_clicked();
    void on_comboBoxDevice_activated(const QString &arg1);
    void on_exitButton_clicked();
    void on_addNewDevise_clicked();

};
#endif // DIALOG_H
