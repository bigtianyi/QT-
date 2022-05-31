#ifndef ATSYSDATABASECONTROL_H
#define ATSYSDATABASECONTROL_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDateTime>

//用户信息表
struct user_info{
    int id;
    qlonglong userid;
    QString username;
    QString userpwd;
};

class QSqlDatabase;

class ATSysDatabaseControl : public QObject
{
public:
    QString dbPath; //定义一个设置数据库路径的全局变量
    ATSysDatabaseControl();//初始化操作
    ~ATSysDatabaseControl();//释放，结束操作

    /**
     * @brief setDatabase 设置数据库文件路径
     *
     * @param path 数据库文件路径
     * @return bool 设置是否成功
     */
    static bool setDatabase(QString path);//原始的设置数据库的路径

    static QString setNewDatabase();//重新编写的设置数据库的路径，这里写成了固定的路径

    /**
     * @brief load 加载考勤卡信息列表
     *
     * @return QList<employee_info>
     */
    //管理员
   static user_info userload(qlonglong userid);//加载用户信息表
   static void useradd(qlonglong userid, const QString &username,const QString &userpwd);
   static void userremove(qlonglong userid) ;//删除信息
private:
    static const QString _dbConnName; /**< TODO */
    static const QString _userTableName; /**< TODO */
    static QSqlDatabase *_db; /**< TODO */
};

#endif // DATABASECONTROL_H


