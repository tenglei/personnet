#include "mainwindow.h"
#include <QApplication>
#include "initmysql.h"
#include "qdebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("星之跳跃"));
    //initMYSQL test;
//    test.ChangeUserImformation("1140310000","小黑","女","1994.5.6","漠河","123");
//    test.ShowUserImformation("1140310000");
//    test.AddEmail("1140310000","789@qq.com");
//    test.SetEmail("1140310000","123@qq.com");
//    test.ShowEmail("1140310000");
//    test.AddSExperience("1140310202","Undergraduate","2015.9.1","2019.7.1","哈工大","本科");
//    test.ChangeSExperience("1140310202","Undergraduate","2015.9.1","2019.7.1","哈工大","硕士");
//    test.ShowSExperienct("1140310000");
//    test.AddWExperience("school","1140310202","2014.9.1","2017.5.19","teacher");
//    test.ChangeWExperience("school","1140310202","2014.9.1","2017.5.19","superman");
//    test.ShowWExperience("1140310000");
//    test.AddFriend("1140310000","1140310202","normalfriend");
//      test.ShowFriends("1140310000");
//      test.ChangeFriendGroup("1140310000","1140310202","NORMAL friend");
//      test.DelFriend("1140310000","1140310202");
//      test.ShowFriends("1140310000");
//    test.ShowFriends("1140310000");

   //   test.ShowArticle("1140310000");
   //   test.AddArticle("1140310000","1140310003","add article","2017.5.19");
  //    test.ChangeArticle("1140310000","1140310003","change article","2017.5.20");
  //    test.DelArticle("1140310202","1140310203");
   //   test.AddResponse("1140310000","1140310202","1140310001","very good","2017.5.19");
//    test.ShowResponse("1140310000");
//    test.ShowMessage("1140310000");
//    test.ShowShare("1140310000");
//    qDebug()<<test.Login("456@qq.com","123");

    w.show();


    return a.exec();
}
