#ifndef FRIENDS_H
#define FRIENDS_H

#include <QDialog>
#include "initmysql.h"
namespace Ui {
class friends;
}

class friends : public QDialog
{
    Q_OBJECT

public:
    initMYSQL mysql;
    QString PID;
    QVector<QVector<QString> > friendsImformation;
    void getMyFriends(QVector<QVector<QString> > friendstmp);
    void getPID(QString PID);
    explicit friends(QWidget *parent = 0);
    ~friends();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_pushButton_2_clicked();

private:
    Ui::friends *ui;
};





#endif // FRIENDS_H
