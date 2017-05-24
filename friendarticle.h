#ifndef FRIENDARTICLE_H
#define FRIENDARTICLE_H

#include <QDialog>
#include "initmysql.h"
namespace Ui {
class friendarticle;
}

class friendarticle : public QDialog
{
    Q_OBJECT

public:
    QString PID;
    initMYSQL mysql;
    void getPID(QString PID);
    void getFriendsArticles();
    explicit friendarticle(QWidget *parent = 0);
    ~friendarticle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::friendarticle *ui;
};



#endif // FRIENDARTICLE_H
