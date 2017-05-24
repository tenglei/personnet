#include "person.h"
#include "ui_person.h"
#include "qdebug.h"
person::person(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);


}

person::~person()
{
    delete ui;
}
void person::getImformation(QString PID, QString PNAME, QString PSEX, QString PBIR, QString PADDR, QString PWD,QVector<QString>PEMAIL,QVector<QString>PFRIENDS,QVector<QString>ARTICLE)
{
    this->PID = PID;
    this->PNAME = PNAME;
    this->PSEX = PSEX;
    this->PBIR = PBIR;
    this->PADDR = PADDR;
    this->PWD = PWD;
    this->ARTICLE.clear();
    this->PFRIENDS.clear();
    this->PEMAIL.clear();
    for(int i=0;i<PEMAIL.size();i++){
        this->PEMAIL.push_back(PEMAIL[i]);
    }
    for(int i=0;i<PFRIENDS.size();i++){
        this->PFRIENDS.push_back(PFRIENDS[i]);
    }
    for(int i=0;i<ARTICLE.size();i++){
        this->ARTICLE.push_back(ARTICLE[i]);
    }

}

void person::on_pushButton_clicked()
{
    ui->lineEdit_3->setText(this->PNAME);//昵称
    ui->lineEdit_5->setText(this->PSEX);//性别
    ui->lineEdit_4->setText(this->PBIR);//bir
    ui->lineEdit_2->setText(this->PADDR);//addr
    ui->lineEdit->setText(this->PWD);//mima
    for(int i=0;i<this->ARTICLE.size();i++){
        ui->textBrowser->insertPlainText(this->ARTICLE[i]);
        ui->textBrowser->insertPlainText("\n");
    }
    for(int i=0;i<this->PFRIENDS.size();i++){
        ui->textBrowser_2->insertPlainText(this->PFRIENDS[i]);
        ui->textBrowser_2->insertPlainText("\n");
    }
    for(int i=0;i<this->PEMAIL.size();i++){
        ui->textBrowser_3->insertPlainText(this->PEMAIL[i]);
        ui->textBrowser_3->insertPlainText("\n");
    }
}

void person::on_buttonBox_accepted()
{
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    QString CNAME = ui->lineEdit_3->text();
    QString CSEX = ui->lineEdit_5->text();
    QString CBIR = ui->lineEdit_4->text();
    QString CADDR = ui->lineEdit_2->text();
    QString CPW = ui->lineEdit->text();
    this->mysql.ChangeUserImformation(this->PID,CNAME,CSEX,CBIR,CADDR,CPW);
}
