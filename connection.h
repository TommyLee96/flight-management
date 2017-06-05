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
               "password varchar(20),username varchar(20),useridnum varchar(18),usersex varchar(2),usertel varchar(11),image blob)");
    query0.exec("insert into user values('333', '333','张三','111111111111111111','女','18158873043','')");
    query0.exec("insert into user values('111', '111','李四','340827199609024313','男','18156577855','')");
    query0.exec("insert into user values('000', '000','王五','254698744455555555','男','1234567899','')");
    query0.exec();

    QSqlQuery query1;
    query1.exec("create table admin (id varchar(20) primary key, "
               "password varchar(20))");
    query1.exec("insert into admin values('admin0', '000')");
    query1.exec("insert into admin values('admin1', '111')");
    query1.exec("insert into admin values('admin2', '222')");
    query1.exec();

    QSqlQuery query2;  // Aname Aircraftmodle   Aircraftid                                                                    //飞机信息表***
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

    QSqlQuery query5;
    query5.exec("create table info_flight (Fid varchar(20) primary key, "
               "Aircraftid varchar(20), Fstart varchar(20),Fend varchar(20),"                                       //飞机型号     varchar
               " AirportS varchar(20),"                                              //公司Fstart varchar(20),Fendsdate         varchar
               " AirportE  varchar(20),sdate varchar(20),Fstarttime time,Fendtime time,Fmoney float,"
               "FOREIGN KEY(Aircraftid) REFERENCES info_aircraft(Aircraftid))");                                                 //座位数量   float
    query5.exec("insert into info_flight values('000', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-01','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('001', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-03','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('002', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-05','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('003', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-07','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('004', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-09','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('005', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-11','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('006', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-13','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('007', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-15','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('008', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-17','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('009', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-19','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('010', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-21','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('011', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-23','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('012', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-25','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('013', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-27','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('014', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-29','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('015', 'HU7604','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-31','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('016', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-02','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('017', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-04','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('018', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-06','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('019', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-08','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('020', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-10','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('021', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-12','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('022', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-14','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('023', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-16','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('024', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-18','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('025', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-20','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('026', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-22','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('027', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-24','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('028', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-26','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('029', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-28','9:30','10:50:00',1000)");
    query5.exec("insert into info_flight values('030', 'CA1846','合肥','上海','合肥新桥机场','上海虹桥机场','2017-06-30','9:30','10:50:00',1000)");
    query5.exec();
    
	QSqlQuery query3;                                                                                //座位信息表****
    query3.exec("create table info_seat (Seatid int,Fid varchar(20),"             //座位id
               "Aircraftid varchar(20),sdate varchar(20),flag int,id varchar(20),"
			   "primary key(Seatid,Aircraftid,Fid),"
               "FOREIGN KEY(Fid) REFERENCES info_aircraft(info_flight),FOREIGN KEY(Aircraftid) REFERENCES info_flight(Aircraftid))");
    QSqlQuery query10;
    int w=0;//记录插入航班的数量
    query10.exec("select Fid,Aircraftid,sdate from info_flight");
    while(query10.next())
    {
    for(int q=1;q<=20;q++)
        {
        QSqlQuery query11;
        QString u=query10.value(0).toString();
        QString y=query10.value(1).toString();
        QString p=query10.value(2).toString();
        QString t="";
        query11.prepare("INSERT INTO info_seat(Seatid,Fid,Aircraftid,sdate,flag,id)VALUES(?,?,?,?,?,?)");
        query11.addBindValue(q);
        query11.addBindValue(u);
        query11.addBindValue(y);
        query11.addBindValue(p);
        query11.addBindValue(0);
        query11.addBindValue(t);
		query11.exec();
        }
    w++;
    }
    query10.exec();
    query3.exec();
    return true;
}
#endif // CONNECTION_H
