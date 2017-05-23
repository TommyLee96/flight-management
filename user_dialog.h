#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>
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

private slots:
    void on_pushButton_clicked();
    void timemove();
    void on_pushButton_serachcity_clicked();
    void on_pushButton_searchnum_clicked();
    void on_btntime_clicked();
    void on_pushButton_calenda_clicked();
    void on_search_clicked();

private:
    Ui::user_dialog *ui;
    QSqlTableModel *model3;
    QSqlQueryModel *model4;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;

};

#endif // USER_DIALOG_H
