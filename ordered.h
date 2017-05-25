#ifndef ORDERED_H
#define ORDERED_H

#include <QDialog>

namespace Ui {
class ordered;
}

class ordered : public QDialog
{
    Q_OBJECT

public:
    explicit ordered(QWidget *parent = 0);
    ~ordered();

private:
    Ui::ordered *ui;
};

#endif // ORDERED_H
