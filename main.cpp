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
        return 1;
    }
    MainWindow h;
    login w;
    QSqlQuery query12;
	query12.exec("select * from info_flight");
    if(w.exec()==QDialog::Accepted)
    {
        if(w.flag==1)   //管理员登陆
            {
            h.show();
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
