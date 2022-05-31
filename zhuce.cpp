#include "zhuce.h"
#include "ui_zhuce.h"
#include "widget.h"
#include "ATSysDatabaseControl.h"
zhuce::zhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);
}

zhuce::~zhuce()
{
    delete ui;
}

//确定
void zhuce::on_pushButton_clicked()
{
    qlonglong userid = ui->le_username->text().toLongLong();
    ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase());
    //user_info ATSysDatabaseControl::userload(qlonglong userid)
    user_info info = ATSysDatabaseControl::userload(userid);

    if(info.username == "")
    {
        if(ui->le_username->text()!="" && ui->le_pwd->text()!="")
        {
            //void ATSysDatabaseControl::useradd(qlonglong userid, const QString &username,const QString &userpwd)
            ATSysDatabaseControl::useradd(userid,ui->le_username->text(),ui->le_pwd->text());
        }
    }
    ui->textEdit->setText("注册成功");
}
//取消
void zhuce::on_pushButton_2_clicked()
{
    Widget *home = new Widget();
    home->show();
    this->hide();

}
