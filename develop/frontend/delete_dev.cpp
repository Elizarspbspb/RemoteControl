#include "delete_dev.h"
#include "ui_delete_dev.h"

using namespace std;

deleteDevise::deleteDevise(QWidget *parent) : QDialog(parent), ui(new Ui::deleteDevise) {
    ui->setupUi(this);
}

deleteDevise::~deleteDevise()
{
    delete ui;
}

void deleteDevise::on_deleteDevise_finished(int result) {
    std::cout << "~deleteDevise" << endl;
    delete ui;
}

