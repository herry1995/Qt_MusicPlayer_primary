#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint); //去掉窗口标题栏
    w.setWindowIcon(QIcon(":/img/Icons/Music.ico"));
    w.show();

    return a.exec();
}
