#include "widget.h"
#include "ui_widget.h"
#include "zhujiemian.h"
#include "zhuce.h"
#include <QTextCodec>
#include<ATSysDatabaseControl.h>
#include "change.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}
//login
void Widget::on_pushButton_clicked()
{
    //database
    qlonglong userid = ui->le_username->text().toLongLong();
    ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase());
    user_info info = ATSysDatabaseControl::userload(userid);


    if(userid == info.username.toLongLong() && ui->le_username->text()!=NULL){

    // if success intend another ui
    if(ui->le_pwd->text() == info.userpwd){
        zhujiemian *zn = new zhujiemian();
        zn->show();
        this->hide();
    }
    else{ //+
        /*loginfail *fail = new loginfail();
        fail->show();
        this->hide();*/
        ui->textEdit->setText("登录失败！ 请检查用户名或密码是否正确！");
    }
}
}

//reset
void Widget::on_pushButton_2_clicked()
{
    ui->le_username->setText("");
    ui->le_pwd->setText("");
}
//注册用户名
void Widget::on_pushButton_3_clicked()
{
    /*qlonglong userid = ui->le_username->text().toLongLong();
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
    ui->textEdit->setText("注册成功");*/
    zhuce *zc = new zhuce();
    zc->show();
    this->hide();
}
//退出
void Widget::on_pushButton_4_clicked()
{
       this->close();
}

//注销
void Widget::on_pushButton_5_clicked()
{
    ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase());
    qlonglong userid = ui->le_username->text().toLongLong();
    ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase());
    user_info info = ATSysDatabaseControl::userload(userid);


    if(ui->le_username != NULL){
        qlonglong userid = ui->le_username->text().toLongLong();
        //void ATSysDatabaseControl::userremove(qlonglong userid)
         ATSysDatabaseControl::userremove(userid);
     }else{
          ui->textEdit->setText("请输入正确的帐号");
     }
}
//修改密码
void Widget::on_pushButton_6_clicked()
{
    change *cg = new change();
    cg->show();
    this->hide();
}
