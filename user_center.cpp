#include "user_center.h"
#include"user_dialog.h"
#include "ui_user_center.h"
#include<QDebug>
#include"global.h"
#include <QSqlQuery>
#include<QMessageBox>
user_center::user_center(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_center)
{
    this->setWindowIcon(QIcon(":/images/bitbug_favicon.ico"));
    ui->setupUi(this);
    QSqlQuery query4;
    query4.exec("select * from user where id=? ");
    query4.addBindValue(userinfo);
    query4.exec();
    while(query4.next())

   {
    ui->id_info->setText(query4.value(0).toString());
    ui->password_info->setText(query4.value(1).toString());
    ui->username_info->setText(query4.value(2).toString());
    ui->useridnum_info->setText(query4.value(3).toString());
    ui->usertel_info->setText(query4.value(5).toString());
    ui->usersex_info->setText(query4.value(4).toString());
    ui->password_info->setPlaceholderText("设置你的密码)");
    ui->username_info->setPlaceholderText("设置你的名字)");
    ui->useridnum_info->setPlaceholderText("设置你的身份证号)");
    ui->usersex_info->setPlaceholderText("设置你的性别)");
    ui->usertel_info->setPlaceholderText("设置你的号码)");
    ui->id_info->setAlignment(Qt::AlignCenter);
    ui->password_info->setAlignment(Qt::AlignCenter);
    ui->username_info->setAlignment(Qt::AlignCenter);
    ui->usersex_info->setAlignment(Qt::AlignCenter);
    ui->useridnum_info->setAlignment(Qt::AlignCenter);
    ui->usertel_info->setAlignment(Qt::AlignCenter);
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
    QString id=ui->id_info->text();                                  //id
    QString password=ui->password_info->text();                      //passsword
    QString name=ui->username_info->text();                           //username
    QString useridnum=ui->useridnum_info->text();                     //useridnum
    QString usersex=ui->usersex_info->text();                 //usersex
    QString usertel=ui->usertel_info->text();

    if(password.isEmpty()==1||name.isEmpty()==1)
   {
    QMessageBox::warning(this, tr("错误"),tr("修改的密码和姓名不能为空!"));
    ui->password_info->setFocus();//给一个输入焦点
   }
    else
   {
    qDebug()<<id<<password<<name<<useridnum<<usersex<<usertel ;
    QSqlQuery query5;//password  username useridnum usersex  usertel
    query5.prepare("UPDATE user SET password=?,username=?,useridnum=?,usersex=?,usertel=? where id=?");
    query5.addBindValue(password);
    query5.addBindValue(name);
    query5.addBindValue(useridnum);
    query5.addBindValue(usersex);
    query5.addBindValue(usertel);
    query5.addBindValue(id);
    if(query5.exec())
    query5.clear();
    QSqlQuery query4;
    query4.exec("select * from user where id=? ");
    query4.addBindValue(id);
    query4.exec();
    QMessageBox::warning(this, tr("恭喜"),tr("修改成功!"));
    close();
   }
}


