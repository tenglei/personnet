#ifndef INITMYSQL_H
#define INITMYSQL_H
#include "QString"
#include "QVector"
#include "QtSql/QSqlDatabase"
class initMYSQL
{
public:
    QSqlDatabase db;
    initMYSQL();
    ConnectMYSQL();
    bool Signup(QString Email,QString PW);
    QString getPID(QString PEMAIL);
    DisConnectMYSQL();
    AddUser(QString PID,QString PNAME,QString PSEX,QString PBIR,QString PADDR,QString PWD);
    bool Login(QString EMAIL,QString PWD);
    ChangeUserImformation(QString PID,QString PNAME,QString PSEX,QString PBIR,QString PADDR,QString PWD);
    QVector<QString> ShowUserImformation(QString PID);
    AddEmail(QString PID, QString EMAIL);
    QVector<QVector<QString> > ShowEmail(QString PID);
    SetEmail(QString PID,QString EMAIL);
    AddSExperience(QString PID, QString EDULEVEL, QString STIME, QString ETIME, QString SCHNAME, QString ADEGREE);
    QVector<QString> ShowSExperienct(QString PID);
    ChangeSExperience(QString PID, QString EDULEVEL, QString STIME, QString ETIME, QString SCHNAME, QString ADEGREE);
    AddWExperience(QString WUNIT,QString PID,QString STIME,QString ETIME,QString POSITION);
    QVector<QString> ShowWExperience(QString PID);
    ChangeWExperience(QString WUNIT,QString PID,QString STIME,QString ETIME,QString POSITION);
    bool AddFriend(QString PID, QString FID, QString FGROUP);
    QVector<QVector<QString> > ShowFriends(QString PID);
    bool DelFriend(QString PID,QString FID);
    ChangeFriendGroup(QString PID, QString FID, QString FGROUP);
    AddArticle(QString PID,QString AID,QString ARTICLE,QString LTIME);
    QVector<QVector<QString> > ShowArticle(QString PID);
    ChangeArticle(QString PID,QString AID,QString ARTICLE,QString LTIME);
    DelArticle(QString PID, QString AID);
    AddResponse(QString PID,QString FID,QString AID,QString CONTENT,QString LTIME);
    QVector<QVector<QString> > ShowResponse(QString PID);
    AddMessage(QString PID, QString FID, QString CONTENT, QString LTIME);
    QVector<QVector<QString> > ShowMessage(QString PID);
    AddShare(QString PID,QString FID,QString AID,QString RCONTENT,QString LTIME);
    QVector<QVector<QString> > ShowShare(QString PID);
};





#endif // INITMYSQL_H
