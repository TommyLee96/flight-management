#include "login.h"
#include "ui_login.h"
#include<QErrorMessage>
#include "connection.h"
#include<QDebug>
#include"signup.h"
#include"global.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/bitbug_favicon.ico"));
    ui->lineEdit_password->setEchoMode( QLineEdit::Password );
    ui->lineEdit_username->setFocus();//给一个输入焦点
    ui->lineEdit_username->setPlaceholderText("用户名");
    ui->lineEdit_password->setPlaceholderText("密码");
    this->setWindowFlags(Qt::WindowCloseButtonHint); //只要关闭按钮
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    flag=0;
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QSqlQuery query3;
        query3.exec("select * from user");//query3.exec("select * from user");
        while(query3.next())
        {
             qDebug()<<"test1";
             qDebug() << query3.value(0).toString()<< query3.value(1).toString();
        }
        QMessageBox::information(this,tr("提示%1").arg(username),
                              tr("请输入完整信息!"),QMessageBox::Ok);
	}
    else if(!ui->radioButton_user->isChecked() && !ui->radioButton_admin->isChecked()) //没选择身份
    {
        QMessageBox::information(this,tr("提示%1").arg(username),
                              tr("请选择登陆用户!"),QMessageBox::Ok);
        return;
    }
	else if(ui->radioButton_user->isChecked())       //旅客登录
    {
        flag=0;
        int flag_user=1;
        QSqlQuery query2;
        query2.exec("select * from user ");
        qDebug()<<"test2";
        while(query2.next())
        {
           qDebug()<<"test3";
           if(query2.value(0).toString() == username)
            {
               flag_user=0;
               if(query2.value(1).toString() == password)
               {
					userinfo=username;
					accept(); //user++;
					this->close();
               }
               else
               {
					QMessageBox::information(this,tr("错误%1").arg(username),
                                         tr("密码错啦!"),QMessageBox::Ok);
					ui->lineEdit_password->clear();
					ui->lineEdit_password->setFocus();
               }
             }
        }
        if(flag_user==1)    //判断用户名是否正确
        {
            QMessageBox::information(this,tr("错误%1").arg(username),
                                  tr("没这个用户!"),QMessageBox::Ok);
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->lineEdit_username->setFocus();
        }
     }

     else if(ui->radioButton_admin->isChecked())        //管理员登录
     {
        flag=1;
        int flag_admin=1;
        QSqlQuery query4;
        query4.exec("select * from admin ");
        while(query4.next())
        {
            if(query4.value(0).toString() == username )
             {
                 flag_admin=0;
                 if(query4.value(1).toString() == password)
                 {
                    accept(); //user++;
                    this->close();
                 }
            else
             {
                 QMessageBox::information(this,tr("错误%1").arg(username),
                                                                 tr("密码错啦!"),QMessageBox::Ok);
                 ui->lineEdit_password->clear();
                 ui->lineEdit_password->setFocus();
             }
         }

      }
      if(flag_admin==1)                   ////判断用户名是否正确
       {
         QMessageBox::information(this,tr("错误%1").arg(username),
                                      tr("没这个用户!"),QMessageBox::Ok);
         ui->lineEdit_username->clear();
         ui->lineEdit_password->clear();
         ui->lineEdit_username->setFocus();
       }
    }
}


void login::on_pushButton_2_clicked()
{
    signup w;
    w.exec();
}


