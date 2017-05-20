#include "user_dialog.h"
#include "ui_user_dialog.h"
#include"login.h"
#include"global.h"
#include"user_center.h"
#include<QErrorMessage>

int checkfor;
QString GoPlace;        //给机票信息窗口传送地名
QString ToPlace;
QString GoTimes;
QString hangbanNum;        //给机票信息窗口传送地名
user_dialog::user_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_dialog)
{


    i = 0;      //滚动字幕的横坐标
    j = 1;      //记录时间按钮按下的次数
    checkfor = 0;

    ui->setupUi(this);
    ui->label->setText(userinfo);
    ui->calendarWidget->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->comboBox->setEditable(true);     //下拉框可编辑
    ui->comboBox_2->setEditable(true);
    ui->lineEdit_3->setReadOnly(true);  //余票数只可读
    QString place = "北京,上海,长沙,深圳,香港,宿州";      //添加默认热门城市
    QString place1 =  "上海,北京,宿州,深圳,香港,长沙";
    QStringList places = place.split(",",QString::SkipEmptyParts);
    QStringList places1 = place1.split(",",QString::SkipEmptyParts);
    ui->comboBox->addItems(places);
    ui->comboBox_2->addItems(places1);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd hh:mm");//设置系统时间显示格式
    ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
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
        QString strTime = time.toString("yyyy-MM-dd hh:mm");//设置系统时间显示格式
        ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
    }

    if(i != 570)
        ui->label_7->move(570-i,30);
    else
    {
        ui->label_7->move(i,30);
        i = 0;
    }

    //判断查询方式，以便改变航班号输入框的可读性
    if(ui->radioButton_2->isChecked())          //按航班查询
    {
        ui->comboBox->setEnabled(false);        //查询出的航班信息只读
        ui->comboBox_2->setEnabled(false);
        ui->btntime->setEnabled(false);     //时间只读
        ui->lineEdit_3->setReadOnly(false);
        //不跳转，航班和余票都显示
        ui->label_5->show();
        ui->label_6->show();
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
       // ui->btnchaxun_2->setEnabled(true);     //预订功能可用

    }
    else            //按起始地点查询
    {
        ui->comboBox->setEnabled(true);        //查询出的航班信息只读
        ui->comboBox_2->setEnabled(true);
        ui->btntime->setEnabled(true);     //时间只读
        ui->lineEdit_3->setReadOnly(true);
        //要跳转到Ticketmessage界面，所以隐藏航班和余票
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
       // ui->btnchaxun_2->setEnabled(false);     //预订功能不可用
    }

}

void user_dialog::on_pushButton_2_clicked()
{
    checkfor++;

    if(!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked())
    {
        QErrorMessage *error = new QErrorMessage(this);
        error->setWindowTitle(tr("提示"));
        error->showMessage(tr("请选择查询条件！"));
        return;
    }

    if(ui->radioButton->isChecked())        //按出发地查询
    {
        GoPlace = ui->comboBox->currentText();
        ToPlace = ui->comboBox_2->currentText();
        GoTimes = ui->lineEdit_time->text();
       // /TicketMessage *ticmess = new TicketMessage(this);
       // ticmess->setModal(true);
        //ticmess->setWindowTitle(tr("航班详细信息表"));
       // ticmess->show();
        return;
    }
    else if(ui->radioButton_2->isChecked())     //按航班查询
    {
        hangbanNum = ui->lineEdit_3->text();  //获取航班号


        ui->comboBox->setEnabled(false);        //查询出的航班信息只读
        ui->comboBox_2->setEnabled(false);
        ui->btntime->setEnabled(false);     //时间只读

        //查询航班座位信息

    }
}
