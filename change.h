#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>

namespace Ui {
    class change;
}

class change : public QWidget
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = 0);
    ~change();

private:
    Ui::change *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // CHANGE_H
