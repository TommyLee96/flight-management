#include "user_dialog.h"
#include "ui_user_dialog.h"
#include"login.h"
#include"global.h"
#include"user_center.h"
user_dialog::user_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_dialog)
{



    ui->setupUi(this);
    ui->label->setText(userinfo);

}

user_dialog::~user_dialog()
{
    delete ui;
}



void user_dialog::on_pushButton_clicked()
{

    user_center d;

    d.exec();

}
