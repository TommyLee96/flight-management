#ifndef USER_DIALOG_H
#define USER_DIALOG_H
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QDialog>
#include <QTimer>
class QSqlTableModel;
class QSqlQueryModel;
class QMediaPlayer;
class QVideoWidget;
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
    int checkfor;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_serachcity_clicked();
    void on_pushButton_searchnum_clicked();
    void on_btntime_clicked();
    void on_pushButton_calenda_clicked();
    void on_search_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_getflight_clicked();
    void on_getseat_clicked();
    void on_pushButton_4_clicked();
    void timeout();
protected:

private:
    Ui::user_dialog *ui;
    QSqlTableModel *model3;  //座位界面
    QSqlTableModel *model5;   //航班
    QSqlQueryModel *model4;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QString flagsta;
    QString flagarr;
    QString flagdate;
    QString flagnum;
    QString f1;
    QString f2;
    QString f3;
    QString show0;
    QString show1;
    QString show2;
    QString show3;
    QString show4;
    QString show5;
    QString show6;
    QString show7;
    QString show8;
    QString show9;
    QTimer* timer;
    QImage images[6];
    int index;
};

#endif // USER_DIALOG_H
