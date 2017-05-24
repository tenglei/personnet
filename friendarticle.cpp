#include "friendarticle.h"
#include "ui_friendarticle.h"
#include "qdebug.h"
friendarticle::friendarticle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendarticle)
{
    ui->setupUi(this);
}

friendarticle::~friendarticle()
{
    delete ui;
}
void friendarticle::getPID(QString PID)
{
    this->PID = PID;
}
void friendarticle::getFriendsArticles()
{
    QVector<QVector<QString> > friendstmp,friendsarticles;
    QVector<QString> friendsID,friendsimformation;
    friendstmp=mysql.ShowFriends(this->PID);
    qDebug()<<"friendtmp:"<<this->PID;
    for(int i =0;i<friendstmp.size();i++){
        friendsID.push_back(friendstmp[i][1]);
        qDebug()<<"friends id:"<<friendsID[i];
    }
    QVector<QVector<QString> > friendsName(friendsID.size());
    for(int i=0;i<friendsID.size();i++){
        friendsimformation = mysql.ShowUserImformation(friendsID[i]);
        QVector<QString> tmp;
        tmp.push_back(friendsimformation[1]);
        friendsName.push_back(tmp);
    }
    for(int i=0;i<friendsID.size();i++){
        friendsarticles = mysql.ShowArticle(friendsID[i]);
        for(int j=0;j<friendsarticles.size();j++){
            friendsName[i].push_back(friendsarticles[j][2]);
            friendsName[i].push_back(friendsarticles[j][3]);
            friendsName[i].push_back("\n");
        }
    }
    for(int i=0;i<friendsName.size();i++){
        for(int j=0;j<friendsName[i].size();j++){
            ui->textBrowser->insertPlainText(friendsName[i][j]);
            ui->textBrowser->insertPlainText(" ");
        }
    }
}

void friendarticle::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    getFriendsArticles();
}
