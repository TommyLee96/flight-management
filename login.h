#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<QString>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
     int flag;  //用来判断是用户还是管理员登陆  详见main.cpp   1为管理员   0用户   默认为用户登录

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::login *ui;
};

#endif // LOGIN_H
//if(ui->radioButton->isChecked())
