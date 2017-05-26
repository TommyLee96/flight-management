#include "ordered.h"
#include "ui_ordered.h"
#include"global.h"
#include<QDebug>
#include <QSqlQuery>
#include<QMessageBox>
ordered::ordered(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordered)
{
    ui->setupUi(this);
    model6=new QSqlQueryModel(this);
    //model6->setQuery("select * from info_seat,info_flight where id ='111'");
    model6->setQuery(QString("select info_seat.Fid,info_seat.Seatid,info_seat.Aircraftid,info_seat.sdate,info_flight.Fstart,info_flight.Fend,info_flight.AirportS, info_flight.AirportE,info_flight.Fstarttime,info_flight.Fendtime from info_seat,info_flight where id = '%1' AND info_seat.Fid=info_flight.Fid").arg(userinfo));





    //model6->setFilter(QString("id = '%1'").arg(""));
    //model6->select();
    //model6->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //QSqlTableModel model3 = new QSqlTableModel;
    ui->tableView->setModel(model6);
   ui->tableView->hideColumn(0);
   // ui->tableView->hideColumn(4);
    //ui->tableView->hideColumn(5);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:lightblue;color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setFocusPolicy(Qt::NoFocus); //去除选中虚线框


}

ordered::~ordered()
{
    delete ui;
}

void ordered::on_pushButton_clicked()
{
 int show_curRow = ui->tableView->currentIndex().row();

 QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, tr("确认退票？"),
                                  QString(tr("尊敬的客户")+userinfo+tr(",您确认退掉您")+model6->index(show_curRow,3).data().toString()+tr("日，从")+model6->index(show_curRow,4).data().toString()+tr("到")+model6->index(show_curRow,5).data().toString()+tr("的航班")+model6->index(show_curRow,2).data().toString()+tr(",您的座位号为")+model6->index(show_curRow,0).data().toString()+tr(". 如有疑问请致电24小时人工客服热线：95530,vip客户专属服务热线：96300，中国东方航空祝您旅途愉快！！")),
                                   QMessageBox::Yes | QMessageBox::Cancel);
     if (reply == QMessageBox::Yes)
         {QSqlQuery query17;
         query17.exec(QString("update info_seat set id = '' where Fid='%1' and Seatid='%2' and Aircraftid='%3' ").arg(model6->index(show_curRow,0).data().toString()).arg(model6->index(show_curRow,1).data().toString()).arg(model6->index(show_curRow,2).data().toString()));
         qDebug()<<show_curRow<<model6->index(show_curRow,0).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,1).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,2).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,3).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,4).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,5).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,6).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,7).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,8).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,9).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,10).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,11).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,12).data().toString();
         qDebug()<<show_curRow<<model6->index(show_curRow,13).data().toString();
         model6->setQuery(QString("select info_seat.Fid,info_seat.Seatid,info_seat.Aircraftid,info_seat.sdate,info_flight.Fstart,info_flight.Fend,info_flight.AirportS, info_flight.AirportE,info_flight.Fstarttime,info_flight.Fendtime from info_seat,info_flight where id = '%1' AND info_seat.Fid=info_flight.Fid").arg(userinfo));

       }


}

void ordered::on_pushButton_2_clicked()
{
    //ui->label_show->show();
    close();
}
