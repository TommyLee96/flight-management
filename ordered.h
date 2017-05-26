#ifndef ORDERED_H
#define ORDERED_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class ordered;
}

class ordered : public QDialog
{
    Q_OBJECT

public:
    explicit ordered(QWidget *parent = 0);
    ~ordered();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ordered *ui;
    QSqlQueryModel *model6;
    QSqlQueryModel *model7;
};

#endif // ORDERED_H
