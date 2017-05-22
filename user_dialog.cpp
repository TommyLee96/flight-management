#include "user_dialog.h"
#include "ui_user_dialog.h"
#include"login.h"
#include"global.h"
#include"user_center.h"
#include<QErrorMessage>
#include<QSqlQuery>
#include<QDebug>
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
    ui->label->setText(userinfo);
    QSqlQuery query4;

   /* query4.exec("select * from user where id=? ");
    query4.addBindValue(userinfo);
    query4.exec();
    //qDebug()<<userinfo<<'88888888';
    while(query4.next())
   {
    ui->label->setText(query4.value(2).toString());
   }
*/
    ui->calendarWidget->hide();
    ui->dateEdit->show();
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

void user_dialog::on_pushButton_2_clicked()
{

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
}

void user_dialog::on_pushButton_searchnum_clicked()
{
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->lineEdit_time->hide();
    ui->btntime->hide();
    ui->dateEdit->show();
}


void user_dialog::on_btntime_clicked()
{

    o=o+1;
    qDebug()<<j<<"on_btntime_clicked";
    if(o % 2 == 0)
    {
         qDebug()<<"on_btntime_clicked";
        //选择时间时，下面控件隐藏
       // ui->label_5->hide();
       // ui->label_4->hide();
       // ui->kedingpiao->hide();
        //ui->kedingpiao_2->hide();
       // ui->btnchaxun->hide();
       // ui->btnchaxun_2->hide();
        //j本身为1，当点击奇数次，日历显示
        ui->calendarWidget->show();
        ui->pushButton_calenda->show();
        ui->lineEdit_time->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
   else
    {
       // ui->label_5->show();
       // ui->label_4->show();
        //ui->kedingpiao->show();
       // ui->kedingpiao_2->show();
        //ui->btnchaxun->show();
       // ui->btnchaxun_2->show();
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
