#ifndef WSEXPERIENCE_H
#define WSEXPERIENCE_H

#include <QDialog>
#include "initmysql.h"
namespace Ui {
class wsexperience;
}

class wsexperience : public QDialog
{
    Q_OBJECT

public:
    initMYSQL mysql;
    QString PID;
    QString EDULEVEL;
    QString SSTIME;
    QString SETIME;
    QString SCHNAME;
    QString ADEGREE;
    QString WUNIT;
    QString WSTIME;
    QString WETIME;
    QString POSITION;
    void getPID(QString PID);
    void getImformation(QString PID);
    explicit wsexperience(QWidget *parent = 0);
    ~wsexperience();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::wsexperience *ui;
};



#endif // WSEXPERIENCE_H
