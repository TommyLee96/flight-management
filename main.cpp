#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include "login.h"
#include<QDebug>
#include <QMessageBox>
#include"user_dialog.h"
#include"global.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     if (!createConnection())
     {
        // QMessageBox::information(tr("登888888888功!"),QMessageBox::Ok);
        return 1;
     }
    MainWindow h;
    login w;
    QSqlQuery query12;

    query12.exec("select * from info_flight");
    while(query12.next())
    {

        qDebug()<<query12.value(0).toString()<<query12.value(1).toString()<<query12.value(2).toString()<<query12.value(3).toString()<<query12.value(4).toString()<<query12.value(5).toString();
        qDebug()<<query12.value(6).toString()<<query12.value(7).toString()<<query12.value(8).toString()<<query12.value(9).toString();
    }
    if(w.exec()==QDialog::Accepted)
    {
        if(w.flag==1)   //管理员登陆
            {
            qDebug()<<"管理员登陆";
            h.show();
            //connect(h,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
            return a.exec();
            }
        else    //默认为用户登录
        {
          user_dialog c;
          c.show();
          return a.exec();
        }
    }
}
