#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
    class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private:
    Ui::menu *ui;

private slots:
    void on_action_3_triggered();
    void on_actionQT_triggered();
    void on_action_triggered();
    void on_menu_iconSizeChanged(QSize iconSize);
};

#endif // MENU_H
