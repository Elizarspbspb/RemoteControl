#ifndef DELETE_DEV_H
#define DELETE_DEV_H




/*#include <QDialog>
#include "./ui_addNewDev.h"
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class DialogNewDev; }
QT_END_NAMESPACE
class newDeviseAdd : public QDialog { */



#include <QDialog>

#include <iostream>

namespace Ui {
class deleteDevise;
}

class deleteDevise : public QDialog
{
    Q_OBJECT

public:
    explicit deleteDevise(QWidget *parent = nullptr);
    ~deleteDevise();

private slots:
    void on_deleteDevise_finished(int result);

private:
    Ui::deleteDevise *ui;
};

#endif // DELETE_DEV_H
