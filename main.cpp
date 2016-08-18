/****************************************
 *@file main.cpp
 *@auth: Yuri Young<yuri.young@qq.com>
 *@date: 2013-11-17
 *****************************************/

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle(QObject::tr("My Camera"));
    w.show();

    return a.exec();
}
