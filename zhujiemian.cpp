#include "zhujiemian.h"
#include "ui_zhujiemian.h"
#include "menu.h"

zhujiemian::zhujiemian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhujiemian)
{
    ui->setupUi(this);
}

zhujiemian::~zhujiemian()
{
    delete ui;
}
//继续
void zhujiemian::on_pushButton_clicked()
{
    menu *m = new menu();
    m->show();
    this->hide();
}
//退出
void zhujiemian::on_pushButton_2_clicked()
{
    this->close();
}


