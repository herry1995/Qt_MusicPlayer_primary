#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint); //ȥ�����ڱ�����
    w.setWindowIcon(QIcon(":/img/Icons/Music.ico"));
    w.show();

    return a.exec();
}
