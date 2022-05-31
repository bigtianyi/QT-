#include "menu.h"
#include "ui_menu.h"
#include <mainwindow.h>
#include <zhujiemian.h>
#include <group.h>

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_action_triggered()
{
    zhujiemian *zjm = new zhujiemian();
    zjm->show();
    this->close();
}

void menu::on_actionQT_triggered()
{

    MainWindow *mw = new MainWindow();
    mw->show();
    this->close();
}

void menu::on_action_3_triggered()
{
    group *ap = new group();
    ap->show();
    this->hide();
}
