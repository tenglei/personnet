#include "initmysql.h"
#include "qstringlist.h"
#include "QtSql/QSqlDatabase"
#include "qdebug.h"
#include "QtSql/qtsqlglobal.h"
#include <iostream>
#include "QVector"
#include "QString"
#include "QSqlQuery"
initMYSQL::initMYSQL()
{

}
initMYSQL::ConnectMYSQL()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("personnet");
    db.setUserName("root");
    db.setPassword("87239107");
    if(db.open()){
       db.exec("SET NAMES 'GBK'");
       qDebug()<<"link success";
    }
    else{
        qDebug()<<"link fail";
    }
}
initMYSQL::DisConnectMYSQL()
{
    db.close();
}
bool initMYSQL::Signup(QString Email, QString PW)
{
    ConnectMYSQL();
    QSqlQuery query;
    QString AddOrder = "insert into email (PEMAIL,PSET) values(?,1)";
    query.prepare(AddOrder);
    query.bindValue(0,Email);
    query.exec();
    QSqlQuery query0;
    QString AddOrder0 = "insert into person (PWD) values(?)";
    query0.prepare(AddOrder0);
    query0.bindValue(0,PW);
    query0.exec();
    QSqlQuery query1;
    QString AddOrder1 = "select last_insert_id()";
    query1.prepare(AddOrder1);
    query1.exec();
    if(query1.next()){
        QString PID = query1.value(0).toString();
        QSqlQuery query2;
        QString AddOrder2 = "update email set PID=? where PEMAIL=?";
        query2.prepare(AddOrder2);
        query2.bindValue(0,PID);
        query2.bindValue(1,Email);
        query2.exec();
        return true;
    }
    DisConnectMYSQL();
    return false;
}
initMYSQL::AddUser(QString PID, QString PNAME, QString PSEX, QString PBIR, QString PADDR, QString PWD){
    ConnectMYSQL();
    QSqlQuery query;
    QString AddOrder = "insert into person (PID,PNAME,PSEX,PBIR,PADDR,PWD) values(?,?,?,?,?,?)";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,PNAME);
    query.bindValue(2,PSEX);
    query.bindValue(3,PBIR);
    query.bindValue(4,PADDR);
    query.bindValue(5,PWD);
    query.exec();
    DisConnectMYSQL();
}
bool initMYSQL::Login(QString EMAIL,QString PWD){
    ConnectMYSQL();
    bool success=false;
    QSqlQuery query;
    QString AddOrder = "select * from email where PEMAIL=?";
    query.prepare(AddOrder);
    query.bindValue(0,EMAIL);
    query.exec();
    while(query.next()){
        if(EMAIL==query.value(1).toString()&&query.value(2).toInt()==1){
            QString PID = query.value(0).toString();
            QSqlQuery query2;
            QString AddOrder2 = "select PWD from person where PID=?";
            query2.prepare(AddOrder2);
            query2.bindValue(0,PID);
            query2.exec();
            while(query2.next()){
                if(query2.value(0).toString()==PWD){
                    success = true;
                    break;
                }
            }
            break;
        }
    }
    DisConnectMYSQL();
    return success;
}
initMYSQL::ChangeUserImformation(QString PID,QString PNAME,QString PSEX,QString PBIR,QString PADDR,QString PWD){
    ConnectMYSQL();
    QString AddOrder = "update person set PNAME=?,PSEX=?,PBIR=?,PADDR=?,PWD=? where PID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PNAME);
    query.bindValue(1,PSEX);
    query.bindValue(2,PBIR);
    query.bindValue(3,PADDR);
    query.bindValue(4,PWD);
    query.bindValue(5,PID);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddEmail(QString PID,QString EMAIL){
    ConnectMYSQL();
    QString AddOrder = "insert into email(PID,PEMAIL,PSET) values(?,?,0)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,EMAIL);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::SetEmail(QString PID,QString EMAIL){
    ConnectMYSQL();
    QString AddOrder0="update email set PSET=0 where PID=?";
    QSqlQuery query0;
    query0.prepare(AddOrder0);
    query0.bindValue(0,PID);
    query0.exec();
    ShowEmail("1140310000");

    QString AddOrder = "update email set PSET=1 where PID=? and PEMAIL=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,EMAIL);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddSExperience(QString PID, QString EDULEVEL, QString STIME, QString ETIME, QString SCHNAME, QString ADEGREE){
    ConnectMYSQL();
    QString AddOrder = "insert into sexperience(PID,EDULEVEL,STIME,ETIME,SCHNAME,ADEGREE) values(?,?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,EDULEVEL);
    query.bindValue(2,STIME);
    query.bindValue(3,ETIME);
    query.bindValue(4,SCHNAME);
    query.bindValue(5,ADEGREE);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::ChangeSExperience(QString PID,QString EDULEVEL,QString STIME,QString ETIME,QString SCHNAME,QString ADEGREE){
    ConnectMYSQL();
    QString AddOrder = "update sexperience set EDULEVEL=?,STIME=?,ETIME=?,SCHNAME=?,ADEGREE=? where PID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,EDULEVEL);
    query.bindValue(1,STIME);
    query.bindValue(2,ETIME);
    query.bindValue(3,SCHNAME);
    query.bindValue(4,ADEGREE);
    query.bindValue(5,PID);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddWExperience(QString WUNIT,QString PID,QString STIME,QString ETIME,QString POSITION){
    ConnectMYSQL();
    QString AddOrder = "insert into wexperience(WUNIT,PID,STIME,ETIME,POSITION) values(?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,WUNIT);
    query.bindValue(1,PID);
    query.bindValue(2,STIME);
    query.bindValue(3,ETIME);
    query.bindValue(4,POSITION);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::ChangeWExperience(QString WUNIT,QString PID,QString STIME,QString ETIME,QString POSITION){
    ConnectMYSQL();
    QString AddOrder = "update wexperience set WUNIT=?,STIME=?,ETIME=?,POSITION=? where PID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,WUNIT);
    query.bindValue(1,STIME);
    query.bindValue(2,ETIME);
    query.bindValue(3,POSITION);
    query.bindValue(4,PID);
    query.exec();
    DisConnectMYSQL();
}
bool initMYSQL::AddFriend(QString PID,QString FID,QString FGROUP){
    ConnectMYSQL();
    bool exist=false;
    qDebug()<<"FID:"<<FID;
    QString AddOrder0="select * from person where PID=?";
    QSqlQuery query0;
    query0.prepare(AddOrder0);
    query0.bindValue(0,FID);
    query0.exec();
    if(query0.next()){
        exist=true;
    }
    else{
        return false;
    }
    QString AddOrder = "insert into friends(PID,FID,FGROUP) values(?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,FID);
    query.bindValue(2,FGROUP);
    query.exec();
    DisConnectMYSQL();
    return exist;
}
bool initMYSQL::DelFriend(QString PID,QString FID){
    ConnectMYSQL();
    bool exist=false;
    QString AddOrder0="select * from person where PID=?";
    QSqlQuery query0;
    query0.prepare(AddOrder0);
    query0.bindValue(0,FID);
    query0.exec();
    if(query0.next()){
        exist=true;
    }
    else{
        return false;
    }
    QString AddOrder = "delete from friends where PID=? and FID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,FID);
    query.exec();
    DisConnectMYSQL();
    return exist;
}
initMYSQL::ChangeFriendGroup(QString PID,QString FID,QString FGROUP){
    ConnectMYSQL();
    QString AddOrder = "update friends set FGROUP=? where PID=? and FID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,FGROUP);
    query.bindValue(1,PID);
    query.bindValue(2,FID);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddArticle(QString PID,QString AID,QString ARTICLE,QString LTIME){
    ConnectMYSQL();
    QString AddOrder = "insert into articles(PID,AID,ARTICLE,LTIME) values(?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,AID);
    query.bindValue(2,ARTICLE);
    query.bindValue(3,LTIME);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::ChangeArticle(QString PID,QString AID,QString ARTICLE,QString LTIME){
    ConnectMYSQL();
    QString AddOrder = "update articles set ARTICLE=?,LTIME=? where PID=? and AID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,ARTICLE);
    query.bindValue(1,LTIME);
    query.bindValue(2,PID);
    query.bindValue(3,AID);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::DelArticle(QString PID,QString AID){
    //删掉日志后相关回复也得删
    ConnectMYSQL();
    QString AddOrder0="delete from response where PID=? and AID=?";
    QSqlQuery query0;
    query0.prepare(AddOrder0);
    query0.bindValue(0,PID);
    query0.bindValue(1,AID);
    query0.exec();

    QString AddOrder = "delete from articles where PID=? and AID=?";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,AID);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddResponse(QString PID,QString FID,QString AID,QString CONTENT,QString LTIME){
    ConnectMYSQL();
    QString AddOrder = "insert into response(PID,FID,AID,CONTENT,LTIME) values(?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,FID);
    query.bindValue(2,AID);
    query.bindValue(3,CONTENT);
    query.bindValue(4,LTIME);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddMessage(QString PID,QString FID,QString CONTENT,QString LTIME){
    ConnectMYSQL();
    QString AddOrder = "insert into message(PID,FID,CONTENT,LTIME) values(?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,FID);
    query.bindValue(2,CONTENT);
    query.bindValue(3,LTIME);
    query.exec();
    DisConnectMYSQL();
}
initMYSQL::AddShare(QString PID,QString FID,QString AID,QString RCONTENT,QString LTIME){
    ConnectMYSQL();
    QString AddOrder = "insert into share(PID,FID,AID,RCONTENT,LTIME) values(?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.bindValue(1,FID);
    query.bindValue(2,AID);
    query.bindValue(3,RCONTENT);
    query.bindValue(4,LTIME);
    query.exec();
    DisConnectMYSQL();
}
QVector<QString> initMYSQL::ShowUserImformation(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,PNAME_TMP,PSEX_TMP,PBIR_TMP,PADDR_TMP,PWD_TMP;
    QString AddOrder = "select * from person where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         PNAME_TMP = query.value(1).toString();
         PSEX_TMP = query.value(2).toString();
         PBIR_TMP = query.value(3).toString();
         PADDR_TMP = query.value(4).toString();
         PWD_TMP = query.value(5).toString();
         t.push_back(PID_TMP);
         t.push_back(PNAME_TMP);
         t.push_back(PSEX_TMP);
         t.push_back(PBIR_TMP);
         t.push_back(PADDR_TMP);
         t.push_back(PWD_TMP);
    }
    qDebug()<<PID_TMP<<PNAME_TMP<<PSEX_TMP<<PBIR_TMP<<PADDR_TMP<<PWD_TMP;
    return t;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowEmail(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > t;
    QSqlQuery query;
    QString PID_TMP,PEMAIL_TMP,SET_TMP;
    QString AddOrder = "select * from email where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         QVector<QString> tmp;
         PID_TMP = query.value(0).toString();
         PEMAIL_TMP = query.value(1).toString();
         SET_TMP = query.value(2).toString();
         tmp.push_back(PID_TMP);
         tmp.push_back(PEMAIL_TMP);
         tmp.push_back(SET_TMP);
         t.push_back(tmp);
         qDebug()<<PID_TMP<<PEMAIL_TMP<<SET_TMP;
    }
    return t;
    DisConnectMYSQL();
}

QVector<QString> initMYSQL::ShowSExperienct(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,EDULEVEL_TMP,STIME_TMP,ETIME_TMP,SCHNAME_TMP,ADEGREE_TMP;
    QString AddOrder = "select * from sexperience where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         EDULEVEL_TMP = query.value(1).toString();
         STIME_TMP = query.value(2).toString();
         ETIME_TMP = query.value(3).toString();
         SCHNAME_TMP = query.value(4).toString();
         ADEGREE_TMP = query.value(5).toString();
         t.push_back(PID_TMP);
         t.push_back(EDULEVEL_TMP);
         t.push_back(STIME_TMP);
         t.push_back(ETIME_TMP);
         t.push_back(SCHNAME_TMP);
         t.push_back(ADEGREE_TMP);
         qDebug()<<PID_TMP<<EDULEVEL_TMP<<STIME_TMP<<ETIME_TMP<<SCHNAME_TMP<<ADEGREE_TMP;
    }
    return t;
    DisConnectMYSQL();
}

QVector<QString> initMYSQL::ShowWExperience(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,WUNIT_TMP,STIME_TMP,ETIME_TMP,POSITION_TMP;
    QString AddOrder = "select * from wexperience where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         WUNIT_TMP = query.value(1).toString();
         STIME_TMP = query.value(2).toString();
         ETIME_TMP = query.value(3).toString();
         POSITION_TMP = query.value(4).toString();
         t.push_back(PID_TMP);
         t.push_back(WUNIT_TMP);
         t.push_back(STIME_TMP);
         t.push_back(ETIME_TMP);
         t.push_back(POSITION_TMP);
         qDebug()<<PID_TMP<<WUNIT_TMP<<STIME_TMP<<ETIME_TMP<<POSITION_TMP;
    }
    return t;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowFriends(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > tmp;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,FID_TMP,GROUP_TMP;
    QString AddOrder = "select * from friends where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         FID_TMP = query.value(1).toString();
         GROUP_TMP = query.value(2).toString();
         t.push_back(PID_TMP);
         t.push_back(FID_TMP);
         t.push_back(GROUP_TMP);
         tmp.push_back(t);
         t.clear();
         qDebug()<<PID_TMP<<FID_TMP<<GROUP_TMP;
    }
    return tmp;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowArticle(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > tmp;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,AID_TMP,ARTICLE_TMP,LTIME_TMP;
    QString AddOrder = "select * from articles where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         AID_TMP = query.value(1).toString();
         ARTICLE_TMP = query.value(2).toString();
         LTIME_TMP = query.value(3).toString();
         t.push_back(PID_TMP);
         t.push_back(AID_TMP);
         t.push_back(ARTICLE_TMP);
         t.push_back(LTIME_TMP);
         tmp.push_back(t);
         t.clear();
         qDebug()<<PID_TMP<<AID_TMP<<ARTICLE_TMP<<LTIME_TMP;
    }
    return tmp;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowResponse(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > tmp;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,FID_TMP,AID_TMP,CONTENT_TMP,LTIME_TMP;
    QString AddOrder = "select * from response where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         AID_TMP = query.value(1).toString();
         FID_TMP = query.value(2).toString();
         CONTENT_TMP = query.value(3).toString();
         LTIME_TMP = query.value(4).toString();
         t.push_back(PID_TMP);
         t.push_back(AID_TMP);
         t.push_back(CONTENT_TMP);
         t.push_back(LTIME_TMP);
         t.push_back(FID_TMP);
         tmp.push_back(t);
         t.clear();
         qDebug()<<PID_TMP<<AID_TMP<<CONTENT_TMP<<FID_TMP<<LTIME_TMP;
    }
    return tmp;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowMessage(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > tmp;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,FID_TMP,CONTENT_TMP,LTIME_TMP;
    QString AddOrder = "select * from message where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         FID_TMP = query.value(1).toString();
         CONTENT_TMP = query.value(2).toString();
         LTIME_TMP = query.value(3).toString();
         t.push_back(PID_TMP);
         t.push_back(CONTENT_TMP);
         t.push_back(LTIME_TMP);
         t.push_back(FID_TMP);
         tmp.push_back(t);
         t.clear();
         qDebug()<<PID_TMP<<CONTENT_TMP<<FID_TMP<<LTIME_TMP;
    }
    return tmp;
    DisConnectMYSQL();
}

QVector<QVector<QString> > initMYSQL::ShowShare(QString PID)
{
    ConnectMYSQL();
    qDebug()<<PID;
    QVector<QVector<QString> > tmp;
    QVector<QString> t;
    QSqlQuery query;
    QString PID_TMP,FID_TMP,AID_TMP,RCONTENT_TMP,LTIME_TMP;
    QString AddOrder = "select * from share where PID=?";
    query.prepare(AddOrder);
    query.bindValue(0,PID);
    query.exec();
    while(query.next()){
         PID_TMP = query.value(0).toString();
         FID_TMP = query.value(1).toString();
         RCONTENT_TMP = query.value(2).toString();
         LTIME_TMP = query.value(3).toString();
         AID_TMP = query.value(4).toString();
         t.push_back(PID_TMP);
         t.push_back(RCONTENT_TMP);
         t.push_back(LTIME_TMP);
         t.push_back(FID_TMP);
         t.push_back(AID_TMP);
         tmp.push_back(t);
         t.clear();
         qDebug()<<PID_TMP<<AID_TMP<<RCONTENT_TMP<<FID_TMP<<LTIME_TMP;
    }
    return tmp;
    DisConnectMYSQL();
}
QString initMYSQL::getPID(QString PEMAIL)
{
    ConnectMYSQL();
    QString PID;
    QSqlQuery query;
    QString AddOrder = "select PID from email where PEMAIL=?";
    query.prepare(AddOrder);
    query.bindValue(0,PEMAIL);
    query.exec();
    if(query.next()){
         PID = query.value(0).toString();
    }
    return PID;
    DisConnectMYSQL();
}
