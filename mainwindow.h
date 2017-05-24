#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstring.h"
#include "initmysql.h"
#include "person.h"
#include "friends.h"
#include "wsexperience.h"
#include "friendarticle.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    person PersonImformation;
    friends myfriends;
    wsexperience experience;
    friendarticle farticle;
    initMYSQL mysql;
    bool login=false;
    QString UserName;
    QString UserPW;
    QString PID;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
