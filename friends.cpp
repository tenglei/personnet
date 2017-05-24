#include "friends.h"
#include "ui_friends.h"
#include "qdebug.h"
friends::friends(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friends)
{
    ui->setupUi(this);
}

friends::~friends()
{
    delete ui;
}

void friends::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    for(int i=0;i<this->friendsImformation.size();i++){
        for(int j=0;j<this->friendsImformation[i].size();j++){
            ui->textBrowser->insertPlainText(this->friendsImformation[i][j]);
            ui->textBrowser->insertPlainText(" ");
        }
        ui->textBrowser->insertPlainText("\n");
    }
}
void friends::getMyFriends(QVector<QVector<QString> > friendstmp)
{
    QVector<QString> tmp;
    this->friendsImformation.clear();
    for(int i=0;i<friendstmp.size();i++){
        for(int j=0;j<friendstmp[i].size();j++){
            tmp.push_back(friendstmp[i][j]);
        }
        this->friendsImformation.push_back(tmp);
        tmp.clear();
    }
}

void friends::on_pushButton_clicked()
{
    QString addfriends = ui->lineEdit->text();
    QString addGroups = ui->lineEdit_3->text();
    if(this->mysql.AddFriend(this->PID,addfriends,addGroups)){
        ui->label_2->setText("添加成功");
    }
    else{
        ui->label_2->setText("找不到目标");
    }
//    qDebug()<<"show addfriends:"<<addfriends;
}
void friends::getPID(QString PID)
{
    this->PID = PID;
}

void friends::on_buttonBox_accepted()
{
    ui->textBrowser->clear();
    delete ui;
}

void friends::on_pushButton_2_clicked()
{
    QString delfriend = ui->lineEdit_2->text();
    if(this->mysql.DelFriend(this->PID,delfriend)){
        ui->label_2->setText("删除成功");
    }
    else{
        ui->label_2->setText("找不到目标");
    }
}
