#ifndef GROUP_H
#define GROUP_H

#include <QWidget>

namespace Ui {
    class group;
}

class group : public QWidget
{
    Q_OBJECT

public:
    explicit group(QWidget *parent = 0);
    ~group();

private:
    Ui::group *ui;

private slots:
    void on_pushButton_clicked();
    void on_widget_destroyed();
};

#endif // GROUP_H
