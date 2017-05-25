#include "user_dialog.h"
#include "ui_user_dialog.h"
#include"login.h"
#include"global.h"
#include"user_center.h"
#include<QErrorMessage>
#include<QSqlQuery>
#include<QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QLabel>
#include <QMovie>
#include<QMediaPlayer>
#include<QMessageBox>
#include<QVideoWidget>
#include<QString>
 //默认城市搜索
QString GoPlace;        //给机票信息窗口传送地名
QString ToPlace;
QString GoTimes;
QString hangbanNum;        //给机票信息窗口传送地名
             //记录日历点击次数
user_dialog::user_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_dialog)
{
    int o=1;
    checkfor=1;
    this->setWindowIcon(QIcon(":/images/bitbug_favicon.ico"));
    ui->setupUi(this);

    model3=new QSqlTableModel(this);
    model3->setTable("info_seat");
    model3->setFilter(QString("id = '%1'").arg(""));
    model3->select();
    model3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //QSqlTableModel model3 = new QSqlTableModel;
    ui->tableView_showticket->setModel(model3);
    ui->tableView_showticket->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_showticket->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_showticket->resizeColumnsToContents();
    //ui->tableView_showticket->setAlternatingRowColors(true); //使用交替行颜色
    ui->tableView_showticket->verticalHeader()->setVisible(false);
    ui->tableView_showticket->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableView_showticket->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableView_showticket->columnsetColumnCount(5);
    model5 = new QSqlTableModel(this);
    model5->setTable("info_flight");
    model5->select();
    ui->tableView_buy->setModel(model5);
    model5->setEditStrategy(QSqlTableModel::OnManualSubmit);



    ui->tableView_buy->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_buy->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_buy->resizeColumnsToContents();
    //ui->tableView_buy->setAlternatingRowColors(true); //使用交替行颜色
    ui->tableView_buy->verticalHeader()->setVisible(false);
    ui->tableView_buy->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableView_buy->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->label->setText(userinfo);
    ui->pushButton_serachcity->setEnabled(false); //初始设置城市搜索为不可按
    ui->pushButton_searchnum->setEnabled(true);
    ui->dateEdit->setEditable(true); //设置选择航班号QComboBox可编辑
    ui->pushButton_2->hide();
    ui->getseat->show();
    ui->search->show();
    ui->getflight->show();
    ui->dateEdit->hide();
    ui->label_5->hide();
    ui->calendarWidget->hide();
    ui->pushButton_calenda->hide();
    ui->pushButton_serachcity->setFocus();
    ui->comboBox->setEditable(true);     //下拉框可编辑
    ui->comboBox_2->setEditable(true);
    QString place = "北京,上海,长沙,深圳,香港,宿州,合肥";      //添加默认热门城市
    QString place1 =  "上海,北京,宿州,深圳,香港,长沙";
    QStringList places = place.split(",",QString::SkipEmptyParts);
    QStringList places1 = place1.split(",",QString::SkipEmptyParts);
    ui->comboBox->addItems(places);
    ui->comboBox_2->addItems(places1);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd");//设("yyyy-MM-dd");设置系统时间显示格式
    //ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
    ui->label_show->show();
}

user_dialog::~user_dialog()
{
    delete ui;
}



void user_dialog::on_pushButton_clicked()
{
    user_center d;
    d.exec();
}

void user_dialog::on_pushButton_serachcity_clicked()
{
    checkfor=1;  //选择城市查询
    ui->pushButton_2->hide();
    ui->getseat->show();
    ui->search->show();
    ui->getflight->show();
    ui->tableView_buy->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->comboBox->show();
    ui->comboBox_2->show();
    ui->lineEdit_time->show();
    ui->btntime->show();
    ui->dateEdit->hide();
    ui->label_5->hide();
    ui->pushButton_serachcity->setEnabled(false);
    ui->pushButton_searchnum->setEnabled(true);
}

void user_dialog::on_pushButton_searchnum_clicked()
{
    checkfor=0;//选择航班号查询
    ui->getseat->show();
    ui->pushButton_2->show();
    ui->search->hide();
    ui->getflight->hide();
    ui->tableView_buy->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->show();
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->lineEdit_time->show();
    ui->btntime->show();
    ui->dateEdit->show();
    ui->label_5->show();
    ui->pushButton_serachcity->setEnabled(true); //初始设置城市搜索为不可按
    ui->pushButton_searchnum->setEnabled(false);
}


void user_dialog::on_btntime_clicked()
{
    o=o+1;
    //qDebug()<<j<<"on_btntime_clicked";
    if(o % 2 == 0)
    {
        qDebug()<<"on_btntime_clicked";
        //选择时间时，下面控件隐藏
        //j本身为1，当点击奇数次，日历显示
        ui->calendarWidget->show();
        ui->pushButton_calenda->show();
        ui->lineEdit_time->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
   else
    {
        //点击偶数次，日历隐藏
        ui->calendarWidget->hide();
        ui->pushButton_calenda->hide();
        ui->lineEdit_time->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
}

void user_dialog::on_pushButton_calenda_clicked()
{
    o=o+1;
    ui->lineEdit_time->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget->hide();
    ui->pushButton_calenda->hide();
}

void user_dialog::on_search_clicked()
{
    QString flagsta = ui->comboBox->currentText();
    QString flagarr = ui->comboBox_2->currentText();
    QString flagnum=ui->dateEdit->currentText();
    QString flagdate=ui->lineEdit_time->text();
    ui->tableView_buy->show();
    if(checkfor==1)           //按城市搜索
                    //"110" "HU7604" "合肥" "上海" "合肥新桥机场" "上海虹桥机场" "2017-05-12" "9:30" "10:50:00" "1000"
         // Fid,Aircraftid,Fstar,Fend,AirportS,AirportE,sdate date,Fstarttime time,Fendtime time,Fmoney float
    {
        if(flagsta.isEmpty() || flagarr.isEmpty() || flagdate.isEmpty())
        {
            QMessageBox::information(this,tr("亲爱的旅客%1").arg(userinfo),
                                  tr("请输入完整信息,起点终点日期!"),QMessageBox::Ok);
        }
        else                                  //城市搜索和日期都不为空
        {


           // qDebug()<<ui->lineEdit_time->text();
           ui->label_show->hide();
           //ui->tableView_showticket->hide();
           //现在根据出发到达日期在info_flight表中查询航班的Fid,Aircrafid,sdate
           //获得Fid,Aircrafid,sdate在model查询获得座位
           QString start=ui->comboBox->currentText();
           QString Fend=ui->comboBox_2->currentText();
           QString sdate=ui->lineEdit_time->text();
           QSqlQuery query15;
           qDebug()<<start<<"OO8O8O88O8OO8O8O8";
           /*query15.exec(QString("select * from info_flight where Fstart = '%1'AND Fend='%2' AND sdate='%3'").arg(start).arg(Fend).arg(sdate));


           //query15.addBindValue(start);

           while(query15.next())
          {
               qDebug()<<"han";

           QString f1=query15.value(0).toString();
           QString f2=query15.value(1).toString();
           QString f3=query15.value(6).toString();
           qDebug()<<"555555555";
            qDebug()<<f1<<f2<<f3;

           }
          query15.exec();
          */
          model5->setFilter(QString("Fstart = '%1' AND Fend= '%2' AND sdate='%3'").arg(start).arg(Fend).arg(sdate));
             // 根据姓名进行筛选，一定要使用单引号
        //model3->setFilter(QString("Fid = '%1'").arg(ui->comboBox->currentText()));
         model5->select();

       }
    }
    else           //按航班号搜索
    {
        if(flagnum.isEmpty() || flagdate.isEmpty())
        {
            QMessageBox::information(this,tr("亲爱的旅客%1").arg(userinfo),
                                  tr("请输入完整信息,起航班号日期!"),QMessageBox::Ok);
        }
    }
}

void user_dialog::on_pushButton_2_clicked()
{
    ui->label_show->hide();
     // 根据姓名进行筛选，一定要使用单引号
    model3->setFilter(QString("Aircraftid = '%1' and sdate = '%2' AND id= '%3'").arg(ui->dateEdit->currentText()).arg(ui->lineEdit_time->text()).arg(""));
    model3->select();
    int rowidx = ui->tableView_showticket->selectionModel()->currentIndex().row();
    qDebug()<<model3->index(rowidx,1).data().toString();  //获取选定行某列的数据

}

void user_dialog::on_getflight_clicked()
{
    if(checkfor==1)
    {int getflight_rowidx = ui->tableView_buy->selectionModel()->currentIndex().row();
    qDebug()<<"FENGEXIAN";

    qDebug()<<"FENGEXIAN888888888";
    QString hh1=model5->index(getflight_rowidx,0).data().toString();
    QString hh2=model5->index(getflight_rowidx,1).data().toString();
    QString hh3=model5->index(getflight_rowidx,6).data().toString();
    qDebug()<<hh1;
    qDebug()<<hh2;
    qDebug()<<hh3;
   // model3->setFilter(QString("id = '%1'").arg(""));
   // model3->setFilter(QString("Fid = '%1' AND Aircraftid= '%2' AND  sdat='%3'").arg(hh1).arg(hh2).arg(hh3));
    model3->setFilter(QString("Fid = '%1' AND id = '%2'").arg(hh1).arg(""));
    //model3->setFilter(QString("Fid = '%1' AND Aircraftid='%2' AND sdate=%3'").arg(hh1).arg(hh2).arg(hh3));
    model3->select();
    ui->tableView_buy->hide();
    }
    else
        {

        ui->label_show->hide();
         // 根据姓名进行筛选，一定要使用单引号
        model3->setFilter(QString("Aircraftid = '%1' and sdate = '%2' AND id= '%3'").arg(ui->dateEdit->currentText()).arg(ui->lineEdit_time->text()).arg(""));
        model3->select();
        int rowidx = ui->tableView_showticket->selectionModel()->currentIndex().row();
        qDebug()<<model3->index(rowidx,1).data().toString();  //获取选定行某列的数据

    }
}

void user_dialog::on_getseat_clicked()
{
    int showticket_curRow = ui->tableView_showticket->currentIndex().row();

    //int rowNum = model2->rowCount();
    //int id = 10;

    // 添加一行
    //model3->insertRow(rowNum);
    model3->setData(model3->index(showticket_curRow, 5), userinfo);

    // 可以直接提交
   model3->submitAll();
    //userinfo

}

void user_dialog::on_pushButton_3_clicked()
{

    if(checkfor==1)
    {
        ui->label_show->show();
        ui->pushButton_2->hide();
        ui->getseat->show();
        ui->search->show();
        ui->getflight->show();
        ui->dateEdit->hide();
        ui->label_5->hide();
        ui->calendarWidget->hide();
        ui->pushButton_calenda->hide();
    }
    else
    {
        ui->label_show->show();
        ui->search->hide();
        ui->getflight->hide();
        ui->pushButton_2->show();
        ui->getseat->show();

    }
}

void user_dialog::on_pushButton_4_clicked()
{

}
