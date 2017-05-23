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
