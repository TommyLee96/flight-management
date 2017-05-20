#include "user_center.h"
#include"user_dialog.h"
#include "ui_user_center.h"
#include<QDebug>
#include"global.h"
#include <QSqlQuery>
user_center::user_center(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_center)
{
    ui->setupUi(this);
    QSqlQuery query4;

    query4.exec("select * from user where id=? ");
    query4.addBindValue(userinfo);
    query4.exec();
    qDebug()<<userinfo<<'88888888';
    while(query4.next())

    {
        ui->id_info->setText(query4.value(0).toString());
        ui->password_info->setText(query4.value(1).toString());
         ui->usertel_info->setText(query4.value(5).toString());
        qDebug() << query4.value(0).toString();
     qDebug() << query4.value(1).toString();
     qDebug() << query4.value(2).toString();
     qDebug() << query4.value(3).toString();
     qDebug() << query4.value(4).toString();
}

}

user_center::~user_center()
{
    delete ui;
}

void user_center::on_pushButton_2_clicked()
{
    close();
}

void user_center::on_pushButton_clicked()
{
}
