#ifndef USER_CENTER_H
#define USER_CENTER_H

#include <QDialog>

namespace Ui {
class user_center;
}

class user_center : public QDialog
{
    Q_OBJECT

public:
    explicit user_center(QWidget *parent = 0);
    ~user_center();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::user_center *ui;
};

#endif // USER_CENTER_H
