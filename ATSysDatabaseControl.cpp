#include "ATSysDatabaseControl.h"
#include <QStringList>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QDebug>
#include <QCoreApplication>

const QString ATSysDatabaseControl::_dbConnName("_user_db_");
const QString ATSysDatabaseControl::_userTableName("tbl_user_info");

QSqlDatabase *ATSysDatabaseControl::_db = NULL;

ATSysDatabaseControl::ATSysDatabaseControl()
{
    if(_db != NULL)
        return;
    _db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", _dbConnName));
}

ATSysDatabaseControl::~ATSysDatabaseControl()
{
    if(_db == NULL)
        return;
    _db->close();
    delete _db;
    _db = NULL;
    QSqlDatabase::removeDatabase(_dbConnName);
}

bool ATSysDatabaseControl::setDatabase(QString path)
{
    if(_db->isOpen())
        _db->close();
    _db->setDatabaseName(path);
    if(!_db->open())
        return false;
    //创建用户表
    if(!_db->tables().contains(_userTableName))
    {
        // 如果数据库中没有tbl_user_info表则创建它
        _db->exec(QString("CREATE TABLE [%1] ("
                  "[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "[userid] INTEGER  UNIQUE NOT NULL,"
                  "[username] TEXT  NULL,"
                  "[userpwd] TEXT  NULL"
                  ")").arg(_userTableName)
                  );
    }
    return _db;
}

//设置新的数据库的路径
QString ATSysDatabaseControl::setNewDatabase()
{
    //获取数据库路径，在项目的debug文件中
// qDebug()<<"db card:"<<QCoreApplication::applicationDirPath() + "/user.db";
    return QCoreApplication::applicationDirPath() + "/user.db";
}

//查询用户名和密码
user_info ATSysDatabaseControl::userload(qlonglong userid)
{
    user_info info;
    info.id = 0;
    info.userid = 0;
    QSqlQuery query(
                QString(
                    "SELECT * from %1 WHERE"
                    " userid='%2'"
                    ).arg(_userTableName).arg(userid)
                , *_db);
//    qDebug()<<"query:"<<query.executedQuery();
    if(query.next())
    {
        info.id = query.value(0).toInt();
        info.userid = query.value(1).toLongLong();
        info.username = query.value(2).toString();
        info.userpwd = query.value(3).toString();
    }
    return info;
}

//添加管理员信息
void ATSysDatabaseControl::useradd(qlonglong userid, const QString &username,const QString &userpwd)
{
    _db->exec(
                QString(
                    "INSERT  INTO [%1]"
                    " (userid,username,userpwd)VALUES (%2,'%3','%4')")
                .arg(_userTableName).arg(userid).arg(username).arg(userpwd));
}
//删除管理员信息
void ATSysDatabaseControl::userremove(qlonglong userid)
{
    _db->exec(QString("DELETE FROM %1 WHERE userid = %2")
              .arg(_userTableName).arg(userid));
}

static ATSysDatabaseControl __dummy_instance__;
