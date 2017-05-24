#include "wsexperience.h"
#include "ui_wsexperience.h"

wsexperience::wsexperience(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wsexperience)
{
    ui->setupUi(this);
}

wsexperience::~wsexperience()
{
    delete ui;
}
void wsexperience::getPID(QString PID)
{
    this->PID = PID;
}
void wsexperience::getImformation(QString PID)
{
    QVector<QString> school = this->mysql.ShowSExperienct(PID);
    QVector<QString> work = this->mysql.ShowWExperience(PID);
    ui->lineEdit_5->setText(school[4]);
    ui->lineEdit_4->setText(school[5]);
    ui->lineEdit_3->setText(school[1]);
    ui->lineEdit_2->setText(school[2]);
    ui->lineEdit->setText(school[3]);
    ui->lineEdit_9->setText(work[1]);
    ui->lineEdit_8->setText(work[4]);
    ui->lineEdit_7->setText(work[2]);
    ui->lineEdit_6->setText(work[3]);

}
void wsexperience::on_pushButton_clicked()
{
    getImformation(this->PID);
}

void wsexperience::on_buttonBox_accepted()
{
   this->SCHNAME =ui->lineEdit_5->text();
   this->ADEGREE = ui->lineEdit_4->text();
   this->EDULEVEL = ui->lineEdit_3->text();
   this->SSTIME = ui->lineEdit_2->text();
   this->SETIME = ui->lineEdit->text();
   this->WUNIT = ui->lineEdit_9->text();
   this->POSITION = ui->lineEdit_8->text();
   this->WSTIME = ui->lineEdit_7->text();
   this->WETIME = ui->lineEdit_6->text();
   this->mysql.ChangeSExperience(this->PID,this->EDULEVEL,this->SSTIME,this->SETIME,this->SCHNAME,this->ADEGREE);
   this->mysql.ChangeWExperience(this->WUNIT,this->PID,this->WSTIME,this->WETIME,this->POSITION);
}
