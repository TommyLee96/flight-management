#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QDebug>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("h.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query0;


    query0.exec("create table user (id varchar(20) primary key, "   //用户名 密码 姓名 身份证  性别 手机号码
               "password varchar(20),username varchar(20),useridnum varchar(18),usersex varchar(2),usertel varchar(11))");
    query0.exec("insert into user values('333', '333','张三','111111111111111111','女','18158873043')");
    query0.exec("insert into user values('111', '111','李四','340827199609024313','男','18156577855')");
    query0.exec("insert into user values('000', '000','王五','254698744455555555','男','1234567899')");
    query0.exec();

    QSqlQuery query1;
    query1.exec("create table admin (id varchar(20) primary key, "
               "password varchar(20))");
    query1.exec("insert into admin values('admin0', '000')");
    query1.exec("insert into admin values('admin1', '111')");
    query1.exec("insert into admin values('admin2', '222')");
    query1.exec();

    QSqlQuery query2;                                                                         //飞机信息表***
    query2.exec("create table info_aircraft (Aircraftid int primary key, " //飞机号(主键) varchar
               "Aircraftmodle varchar(20),"                                       //飞机型号     varchar
               " Aname varchar(20),"                                              //公司        varchar
               " Sitnum float)");                                                 //座位数量   float
    query2.exec("insert into info_aircraft values('CA1846', '波音 737-800(中型)','深圳航空',60)");
    query2.exec("insert into info_aircraft values('CZ9285', '波音 737-900ER(中型)','南方航空',70)");
    query2.exec("insert into info_aircraft values('MU5101', '空中客车 A320(中型)','海南航空',60)");
    query2.exec("insert into info_aircraft values('MU5171', '空中客车 A320(中型)','东方航空',60)");
    query2.exec("insert into info_aircraft values('CZ9274', '梦想客机 波音787','中国国航',60)");
    query2.exec("insert into info_aircraft values('FM9103', '波音 787-9(大型)','海南航空',60)");
    query2.exec("insert into info_aircraft values('CZ3908', '波音 777-300ER(大型)','海南航空',60)");
    query2.exec("insert into info_aircraft values('HU7604', '波音 787-800(大型)','海南航空',60)");
    query2.exec();


    QSqlQuery query3;                                                                                //座位信息表****
    query3.exec("create table info_seat (Seatid int,"             //座位id
               "Aircraftid varchar(20),flag int,"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");
    QSqlQuery query4;
    query4.exec("insert into info_seat values(8, 'G123',1)");




        QSqlQuery query10;
        int w=0;//记录插入航班的数量
        int h=0;
        query10.exec("select Aircraftid from info_aircraft");
        while(query10.next())
        {

            qDebug()<<"hahhahahahhha";
             for(int q=1;q<=20;q++)
             {
                 h=q+20*w;
             //qDebug()<<query10.value(0).toString();
            QSqlQuery query11;
            QString y=query10.value(0).toString();
            query11.prepare("INSERT INTO info_seat(Seatid,Aircraftid,flag)VALUES(?,?,?)");
            query11.addBindValue(q);

            qDebug()<<y;
            query11.addBindValue(y);
            query11.addBindValue(0);
            query11.exec();
             }
             w++;
        }
        query10.exec();




    QSqlQuery query5;
    query5.exec("create table info_flight (Fid varchar(20) primary key,"
               "Aircraftid varchar(20), Fsart varchar(20),"
               "Fend varchar(20),AirportS varchar(20),AirportE varchar(20) , Fstarttime varchar(20),"
               "Fsartdate date, Ftime float,Fmoney float,"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");


    query5.exec("create table info_ordered (Tid int primary key,"     //订单信息
               "Fid varchar(20) ,Aircraftid varchar(20), Seatid varchar(20),"
               "id varchar(20),"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid),"
               "FOREIGN KEY(id) REFERENCES user(id),FOREIGN KEY(Seatid) REFERENCES info_seat(Seatid),"
               "FOREIGN KEY(Fid) REFERENCES info_flight(Fid),FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");

              // "FOREIGN KEY(id) REFERENCES user(id),FOREIGN KEY(Seatid) REFERENCES info_seat(Seatid),"
              // "FOREIGN KEY(Fid REFERENCES info_flight(Fid),FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");
    QSqlQuery query6;
    query6.exec("select * from info_ordered");
    while(query6.next())
    {
         qDebug()<<"info_orderedinfo_orderedinfo_orderedinfo_ordered";
         qDebug() << query6.value(0).toString()<< query6.value(1).toString();
    }

    //query.exec("CREATE TABLE list (fliename varchar(128) UNIQUE, fzip blob)";);
    return true;
}
#endif // CONNECTION_H
