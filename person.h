#ifndef PERSON_H
#define PERSON_H

#include <QDialog>
#include "qstring.h"
#include "qvector.h"
#include "initmysql.h"
namespace Ui {
class person;
}

class person : public QDialog
{
    Q_OBJECT

public:
    initMYSQL mysql;
    void getImformation(QString PID,QString PNAME,QString PSEX,QString PBIR,QString PADDR,QString PWD,QVector<QString>PEMAIL,QVector<QString>PFRIENDS,QVector<QString>ARTICLE);
    QString PID;
    QString PNAME;
    QString PSEX;
    QString PBIR;
    QString PADDR;
    QString PWD;
    QVector<QString> PEMAIL;
    QVector<QString> PFRIENDS;
    QVector<QString> ARTICLE;
    explicit person(QWidget *parent = 0);
    ~person();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::person *ui;
};



#endif // PERSON_H
