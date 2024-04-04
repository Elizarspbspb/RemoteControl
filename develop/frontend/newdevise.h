#ifndef NEWDEVISE_H
#define NEWDEVISE_H

#include <QDialog>

#include "./ui_addNewDev.h"

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogNewDev; }
QT_END_NAMESPACE

class newDeviseAdd : public QDialog {
    Q_OBJECT
public:
    explicit newDeviseAdd(QDialog *parent = nullptr);
    uint addNewDevice();
    ~newDeviseAdd();

private:
    Ui::DialogNewDev *uidev;

signals:

private slots:
    void on_DialogNewDev_finished(int result);
    void on_cancelPushButton_clicked();
};

#endif // NEWDEVISE_H
