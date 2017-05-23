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
#include<QVideoWidget>

int checkfor;
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
    this->setWindowIcon(QIcon(":/images/bitbug_favicon.ico"));
    ui->setupUi(this);
    model3 = new QSqlTableModel(this);
    ui->tableView_showticket->setModel(model3);
    model3->setTable("info_seat");
    model3->select();
    ui->tableView_showticket->setModel(model3);
    model3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_showticket->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_showticket->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_showticket->resizeColumnsToContents();
    ui->tableView_showticket->setAlternatingRowColors(true); //使用交替行颜色
    ui->tableView_showticket->verticalHeader()->setVisible(false);
    ui->tableView_showticket->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->label->setText(userinfo);
    ui->pushButton_serachcity->setEnabled(false); //初始设置城市搜索为不可按
    ui->pushButton_searchnum->setEnabled(true);
    ui->dateEdit->setEditable(true); //设置选择航班号QComboBox可编辑
    ui->dateEdit->hide();
    ui->label_5->hide();
    ui->calendarWidget->hide();
    ui->pushButton_calenda->hide();
    ui->pushButton_serachcity->setFocus();
    ui->comboBox->setEditable(true);     //下拉框可编辑
    ui->comboBox_2->setEditable(true);
    QString place = "北京,上海,长沙,深圳,香港,宿州";      //添加默认热门城市
    QString place1 =  "上海,北京,宿州,深圳,香港,长沙";
    QStringList places = place.split(",",QString::SkipEmptyParts);
    QStringList places1 = place1.split(",",QString::SkipEmptyParts);
    ui->comboBox->addItems(places);
    ui->comboBox_2->addItems(places1);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd");//设("yyyy-MM-dd");设置系统时间显示格式
    ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
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
void user_dialog::timemove()
{
    i += 3;
    if(i % 20 == 0)
    {
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString strTime = time.toString("yyyy-MM-dd");//设置系统时间显示格式
        ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
    }
}

void user_dialog::on_pushButton_serachcity_clicked()
{
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
    qDebug()<<j<<"on_btntime_clicked";
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
    ui->lineEdit_time->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget->hide();
    ui->pushButton_calenda->hide();
}

void user_dialog::on_search_clicked()
{
    qDebug()<<ui->dateEdit->currentText();
    ui->label_show->hide();
    // 根据姓名进行筛选，一定要使用单引号
    model3->setFilter(QString("Aircraftid = '%1'").arg(ui->dateEdit->currentText()));
    model3->select();
}
