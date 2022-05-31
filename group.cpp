#include "group.h"
#include "ui_group.h"
#include <zhujiemian.h>

group::group(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::group)
{
    ui->setupUi(this);
}

group::~group()
{
    delete ui;
}

void group::on_pushButton_clicked()
{
    zhujiemian *zm = new zhujiemian();
    zm->show();
    this->close();
}
