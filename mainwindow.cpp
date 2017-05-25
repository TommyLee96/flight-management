 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon(":/images/bitbug_favicon.ico"));
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("info_flight");
    model->select();
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
    // ui->tableView->setColumnWidth(0, 80);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setAlternatingRowColors(true); //使用交替行颜色
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model2 = new QSqlTableModel(this);
    model2->setTable("user");
    model2->select();
    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 提交修改按钮
void MainWindow::on_pushButton_clicked()
{
    // 开始事务操作
    model->database().transaction();
    if (model->submitAll()) {
        if(model->database().commit()) // 提交
            QMessageBox::information(this, tr("tableModel"),
                                     tr("数据修改成功！"));
    } else {
        model->database().rollback(); // 回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

// 撤销修改按钮
void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}

// 查询按钮，进行筛选
void MainWindow::on_pushButton_5_clicked()
{
    QString name = ui->lineEdit->text();

    // 根据姓名进行筛选，一定要使用单引号
    model->setFilter(QString("username = '%1'").arg(name));
    model->select();
}

// 显示全表按钮
void MainWindow::on_pushButton_6_clicked()
{
    model->setTable("user");
    model->select();
}

// 按id升序排列按钮
void MainWindow::on_pushButton_7_clicked()
{
    //id字段，即第0列，升序排列
    model->setSort(0, Qt::AscendingOrder);
    model->select();

}

// 按id降序排列按钮
void MainWindow::on_pushButton_8_clicked()
{
    model->setSort(0, Qt::DescendingOrder);
    model->select();

}
// 删除选中行按钮
void MainWindow::on_pushButton_4_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model->revertAll();
    } else { // 否则提交，在数据库中删除该行
        model->submitAll();
    }

}
// 添加记录按钮
void MainWindow::on_pushButton_3_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    int id = 10;

    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(0, 0), id);

    // 可以直接提交
    //model->submitAll();
}

void MainWindow::on_pushButton_9_clicked()
{
    // 开始事务操作
    model2->database().transaction();
    if (model2->submitAll()) {
        if(model2->database().commit()) // 提交
            QMessageBox::information(this, tr("tableModel"),
                                     tr("数据修改成功！"));
    } else {
        model2->database().rollback(); // 回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(model2->lastError().text()),
                             QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    model2->revertAll();
}

void MainWindow::on_pushButton_11_clicked()
{
    // 获得表的行数
    int rowNum = model2->rowCount();
    int id = 10;

    // 添加一行
    model2->insertRow(rowNum);
    model2->setData(model2->index(0, 0), id);

    // 可以直接提交
    //model->submitAll();
}

void MainWindow::on_pushButton_12_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView_2->currentIndex().row();

    // 删除该行
    model2->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model2->revertAll();
    } else { // 否则提交，在数据库中删除该行
        model2->submitAll();
    }

}

void MainWindow::on_pushButton_13_clicked()
{
    model2->setSort(0, Qt::AscendingOrder);
    model2->select();
}

void MainWindow::on_pushButton_14_clicked()
{
    model2->setSort(0, Qt::DescendingOrder);
    model2->select();
}

void MainWindow::on_pushButton_15_clicked()
{
    QString name = ui->lineEdit_2->text();

    // 根据姓名进行筛选，一定要使用单引号
    model2->setFilter(QString("name = '%1'").arg(name));
    model2->select();
}

void MainWindow::on_pushButton_16_clicked()
{
    model2->setTable("admin");
    model2->select();
}
