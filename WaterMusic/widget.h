#ifndef WIDGET_H
#define WIDGET_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMenu>
#include <QStandardItemModel>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QTime>
#include <QMouseEvent>
#include <QCompleter>
#include <QPixmap>
#include <QPalette>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private slots:
    void on_Btn_OpenFile_clicked();

    void on_Btn_PlayPause_clicked();

    void on_Btn_NextMusic_clicked();

    void on_Btn_PreMusic_clicked();

    void on_Btn_Close_clicked();

    void on_Btn_Min_clicked();

    void ShowSongName();


    void on_Btn_Voice_clicked();

    void on_HS_Volume_sliderMoved(int);

    void mousePressEvent(QMouseEvent* );

    void mouseMoveEvent(QMouseEvent* );

    void updatePosition(qint64);
    void updateDuration(qint64);

private:
    Ui::Widget *ui;

    QStringList* songName;
    QMediaPlayer* musicplayer;
    QMediaPlaylist* playlist;

    QStandardItemModel* model;
    QSystemTrayIcon* trayIcon;
    QMenu* trayMenu;

    QAction* playpause;
    QAction* pre;
    QAction* next;
    QAction* addfiles;
    QAction* minimizeAction;
    QCompleter* completer;

    QTime* currentTime;
    QTime* totalTime;

    QPixmap pix;
    QPalette pal;
    int xOffset,yOffset;
};

#endif // WIDGET_H
