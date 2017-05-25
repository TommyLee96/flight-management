#include "ordered.h"
#include "ui_ordered.h"

ordered::ordered(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordered)
{
    ui->setupUi(this);
}

ordered::~ordered()
{
    delete ui;
}
