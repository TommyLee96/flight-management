#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("h.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;


    query.exec("create table user (id varchar(20) primary key, "   //用户名 密码 姓名 身份证  性别 手机号码
               "password varchar(20),username varchar(20),useridnum varchar(18),usersex varchar(2),usertel varchar(11))");
    query.exec("insert into user values('333', '333','张三','111111111111111111','女','18158873043')");
    query.exec("insert into user values('111', '111','李四','340827199609024313','男','18156577855')");
    query.exec("insert into user values('000', '000','王五','254698744455555555','男','1234567899')");

    query.exec("create table admin (id varchar(20) primary key, "
               "password varchar(20))");
    query.exec("insert into admin values('admin0', '000')");
    query.exec("insert into admin values('admin1', '111')");
    query.exec("insert into admin values('admin2', '222')");



    query.exec("create table info_aircraft (Aircraftid varchar(20) primary key, "
               "Aircraftmodle varchar(20), Aname varchar(20), Sitnum int)");
    query.exec("insert into info_aircraft values('GD123', 'BY747','深圳航空',60)");  //飞机信息
    query.exec("insert into info_aircraft values('NFHK123', 'HK232','南方航空',70)");
    query.exec("insert into info_aircraft values('NNHK123', 'BY787','海南航空',60)");


    query.exec("create table info_seat (Seatid varchar(20) primary key,"
               "Aircraftid varchar(20), flag int,"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");
    query.exec("insert into info_seat values('01', 'G123',1)");

    query.exec("create table info_flight (Fid varchar(20) primary key,"
               "Aircraftid varchar(20), Fsart varchar(20),"
               "Fend varchar(20), Fstarttime varchar(20),"
               "Fsartdate date, Ftime float,"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");


    query.exec("create table info_ordered (Tid int primary key,"     //订单信息
               "Fid varchar(20) ,Aircraftid varchar(20), Seatid varchar(20),"
               "id varchar(20)),FOREIGN KEY(id) REFERENCES user(id),FOREIGN KEY(Seatid) REFERENCES info_seat(Seatid),"
               "FOREIGN KEY(Fid) REFERENCES info_flight(Fid),FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");

    return true;
}
#endif // CONNECTION_H
