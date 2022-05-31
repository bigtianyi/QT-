#ifndef ZHUCE_H
#define ZHUCE_H

#include <QWidget>

namespace Ui {
    class zhuce;
}

class zhuce : public QWidget
{
    Q_OBJECT

public:
    explicit zhuce(QWidget *parent = 0);
    ~zhuce();

private:
    Ui::zhuce *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

};

#endif // ZHUCE_H
