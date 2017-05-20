#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("create table user (id varchar(20) primary key, "   //用户名 密码 姓名 身份证  性别 手机号码
               "password varchar(20),username varchar(20),useridnum varchar(18),usersex varchar(2),usertel varchar(11))");
    query.exec("insert into user values('000', '000','张三','111111111111111111','男','18158873043')");
    query.exec("insert into user values('111', '111','','','','')");
    query.exec("insert into user values('222', '222','','','','')");

    query.exec("create table admin (id varchar(20) primary key, "
               "password varchar(20))");
    query.exec("insert into admin values('admin0', '000')");
    query.exec("insert into admin values('admin1', '111')");
    query.exec("insert into admin values('admin2', '222')");
    return true;
}
#endif // CONNECTION_H
