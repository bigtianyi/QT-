#include "change.h"
#include "ui_change.h"
#include "ATSysDatabaseControl.h"
#include "widget.h"
#include <QMessageBox>
#include <QSqlQuery>

change::change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
}

change::~change()
{
    delete ui;
}
//确定  此功能为
void change::on_pushButton_clicked()
{




       /* QSqlQuery query;
        int id = ui->IDEdit->text().toInt();

        double userCP = ui->scoreEdit->text().toDouble();
        QString str = QString("UPDATE boys SET userCP=%1 WHERE id=%2"
                              ).arg(userCP).arg(id);
        if(query.exec(str)==false){
            QMessageBox::critical(this,"Error","修改失败！");
        }
        else{
            QMessageBox::information(this,"success","修改成功！");
            queryTable();
        }
*/




    /*qlonglong userid = ui->le_username->text().toLongLong(),userpwd = ui->le_pwd->text().toLongLong();
    ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase());
    //user_info ATSysDatabaseControl::userload(qlonglong userid)
    user_info info = ATSysDatabaseControl::userload(userid);

    if(info.username == "")
    {
        if(ui->le_username->text()!="" && ui->le_pwd->text()!="")
        {
            //void ATSysDatabaseControl::useradd(qlonglong userid, const QString &username,const QString &userpwd)
            //ATSysDatabaseControl::useradd(userid,ui->le_username->text(),ui->le_pwd->text());
            info.userpwd = userpwd;
        }
         ui->textEdit->setText("密码修改成功");
    }
    /*if(){
        ui->textEdit->setText("密码修改成功");
    }else{
        ui->textEdit->setText("密码修改失败");
    }*/
}

void change::on_pushButton_2_clicked()
{
    Widget *fh = new Widget();
    fh->show();
    this->close();
}
