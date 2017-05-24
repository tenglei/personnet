#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initmysql.h"
#include "person.h"
#include "qdebug.h"
#include "friends.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->UserName = ui->lineEdit->text();
    this->UserPW = ui->lineEdit_2->text();
    this->login=this->mysql.Signup(this->UserName,this->UserPW);
    if(this->login){
        ui->label->setText("注册成功！欢迎使用！");
        this->PID=mysql.getPID(this->UserName);
        mysql.AddSExperience(this->PID,"empty","empty","empty","empty","empty");
        mysql.AddWExperience("empty",this->PID,"empty","empty","empty");
    }
    else{
        ui->label->setText("出了一点小问题= 。=");
    }
}


void MainWindow::on_pushButton_clicked()
{
    this->UserName = ui->lineEdit->text();
    this->UserPW = ui->lineEdit_2->text();
    this->login=this->mysql.Login(this->UserName,this->UserPW);
    if(this->login){
        ui->label->setText("登陆成功！欢迎使用");
        this->PID=mysql.getPID(this->UserName);
        //qDebug()<<this->PID;
    }
    else{
        ui->label->setText("用户名或密码错误！");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QVector<QString> tmp,emailtmp,articletmp,friendstmp;
    QVector<QVector<QString> >PEMAIL_TMP,ARTICLE_TMP,PFRIENDS_TMP;
    PEMAIL_TMP = mysql.ShowEmail(this->PID);
    ARTICLE_TMP = mysql.ShowArticle(this->PID);
    PFRIENDS_TMP = mysql.ShowFriends(this->PID);
    for(int i=0;i<PEMAIL_TMP.size();i++){
        emailtmp.push_back(PEMAIL_TMP[i][1]);
    }
    for(int i=0;i<ARTICLE_TMP.size();i++){
        articletmp.push_back(ARTICLE_TMP[i][2]);
        qDebug()<<"mainwindow add ariticle:"<<ARTICLE_TMP[i][2];
    }
    for(int i=0;i<PFRIENDS_TMP.size();i++){
        friendstmp.push_back(PFRIENDS_TMP[i][1]);
    }
    tmp=mysql.ShowUserImformation(this->PID);
    qDebug()<<"test:"<<tmp[0]<<tmp[1];
    PersonImformation.getImformation(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],emailtmp,friendstmp,articletmp);
    PersonImformation.show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QVector<QVector<QString> > friendstmp,friendsadd;
    QVector<QString> friendsid,friendsimformation,imformationtmp,friendsgroup;
    friendstmp = mysql.ShowFriends(this->PID);
    for(int i=0;i<friendstmp.size();i++){
        friendsid.push_back(friendstmp[i][1]);
        friendsgroup.push_back(friendstmp[i][2]);
    }
    for(int i=0;i<friendsid.size();i++){
        imformationtmp = mysql.ShowUserImformation(friendsid[i]);
        friendsimformation.push_back(imformationtmp[1]);
        friendsimformation.push_back(imformationtmp[2]);
        friendsimformation.push_back(imformationtmp[3]);
        friendsimformation.push_back(imformationtmp[4]);
        friendsimformation.push_back(friendsgroup[i]);
        friendsadd.push_back(friendsimformation);
        friendsimformation.clear();
    }

    myfriends.getMyFriends(friendsadd);
    myfriends.getPID(this->PID);
    myfriends.show();
}

void MainWindow::on_pushButton_8_clicked()
{
    experience.getPID(this->PID);
    experience.show();
}

void MainWindow::on_pushButton_6_clicked()
{
    farticle.getPID(this->PID);
    farticle.show();
}
