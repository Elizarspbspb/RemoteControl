#include "newdevise.h"

//#include <iostream>

using namespace std;

newDeviseAdd::newDeviseAdd(QDialog *parent):QDialog{parent}, uidev(new Ui::DialogNewDev) {
    uidev->setupUi(this);
}

newDeviseAdd::~newDeviseAdd() {
    cout << "~newDeviseAdd() 1" << endl;
    delete uidev;
}

void newDeviseAdd::on_DialogNewDev_finished(int result) {
    std::cout << "~newDeviseAdd() 2" << endl;
    delete uidev;
}

void newDeviseAdd::on_cancelPushButton_clicked() {
    cout << "~newDeviseAdd() 3" << endl;
    accept();
}

