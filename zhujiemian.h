#ifndef ZHUJIEMIAN_H
#define ZHUJIEMIAN_H

#include <QWidget>

namespace Ui {
    class zhujiemian;
}

class zhujiemian : public QWidget
{
    Q_OBJECT

public:
    explicit zhujiemian(QWidget *parent = 0);
    ~zhujiemian();

private:
    Ui::zhujiemian *ui;

private slots:
    void on_textEdit_2_destroyed();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // ZHUJIEMIAN_H
