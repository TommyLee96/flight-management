#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>


namespace Ui {
class user_dialog;
}

class user_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit user_dialog(QWidget *parent = 0);
    ~user_dialog();
    int i;      //文字滚动
    int j;

    int o;
private slots:
    void on_pushButton_clicked();

     void timemove();

    //void recdate(QString date);

   // void recmessage();

     void on_pushButton_2_clicked();

     void on_pushButton_serachcity_clicked();

     void on_pushButton_searchnum_clicked();



     void on_btntime_clicked();

     void on_pushButton_calenda_clicked();

private:
    Ui::user_dialog *ui;


};

#endif // USER_DIALOG_H
