#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QMessageBox"
#include <QStandardItem>
#include <QAbstractItemView>
#include <QCloseEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    pix.load(":/BackGroundPixMap/image/background.jpg");
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
     setPalette(pal);
    musicplayer = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    songName = new QStringList();


    //ui->Btn_PlayPause->setToolTip(QString::fromLocal8Bit("????"));
    ui->Btn_PlayPause->setToolTip(QString::fromLocal8Bit("play\pause"));
    ui->Btn_PreMusic->setToolTip(QString::fromLocal8Bit("preMusic"));
    ui->Btn_NextMusic->setToolTip(QString::fromLocal8Bit("NextMusic"));
    ui->Btn_Close->setToolTip(QString::fromLocal8Bit("Close"));
    ui->Btn_Min->setToolTip(QString::fromLocal8Bit("Min"));
    ui->Btn_OpenFile->setToolTip(QString::fromLocal8Bit("OpenFile"));
    ui->Btn_Expand->setToolTip(QString::fromLocal8Bit("Max"));
    ui->Btn_Voice->setToolTip(QString::fromLocal8Bit("Voice"));
    ui->CombBox_PlayMode->setToolTip(QString::fromLocal8Bit("PlayMode"));
    ui->tableView_PlayList->setRowHeight(0,60);
    ui->tableView_PlayList->setColumnWidth(0,200);
    ui->HS_Volume->setRange(0,100);

    model = new QStandardItemModel(ui->tableView_PlayList);
//    model->setItem(0,new QStandardItem(QString::fromLocal8Bit("????")));
//    ui->tableView_PlayList->setSelectionBehavior(QAbstractItemView::SelectRows);//??????????? ??????API  ??????????????????锟斤拷????

//    ui->tableView_PlayList->setModel(model);
    QStringList strings;
    strings << "currentItemInLoop" << "sequential" << "loop" << "random";
    completer = new QCompleter(strings,this);
    ui->CombBox_PlayMode->clear();
    ui->CombBox_PlayMode->addItems(strings);
    ui->CombBox_PlayMode->setEditable(false);
    ui->CombBox_PlayMode->setCompleter(completer);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/img/Icons/Music.ico"));
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));

    connect(musicplayer,&QMediaPlayer::positionChanged,this,&Widget::updatePosition);  /* This Position is not be good at musicplayer,sometimes have a little of stopping*/
    connect(ui->HS_SongProgress,&QSlider::sliderMoved,musicplayer,&QMediaPlayer::setPosition);
    connect(ui->HS_SongProgress,&QSlider::valueChanged,musicplayer,&QMediaPlayer::setPosition);
    connect(musicplayer,&QMediaPlayer::durationChanged,this,&Widget::updateDuration);
    connect(musicplayer,&QMediaPlayer::currentMediaChanged,this,&Widget::ShowSongName);
    connect(ui->HS_Volume,&QSlider::sliderMoved,musicplayer,&QMediaPlayer::setVolume);
    connect(ui->HS_Volume,&QSlider::valueChanged,musicplayer,&QMediaPlayer::setVolume);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_Btn_OpenFile_clicked()
{
    QString initialName = QDir::homePath();

    QStringList pathList = QFileDialog::getOpenFileNames(this,QString::fromLocal8Bit("OpenFile"),initialName,tr("MP3 Files(*.mp3)"));


    for(int i = 0; i < pathList.size(); ++i)
    {
        QString path = QDir::toNativeSeparators(pathList.at(i));

        if(!path.isEmpty())
        {
            playlist->addMedia(QUrl::fromLocalFile(path));
            QString filename = path.split("\\").last();
            QString Name = filename.split(".").front();
            QStandardItem* item = new QStandardItem(Name);
            songName->append(Name);
            this->model->appendRow(item);
        }
    }

    musicplayer->setPlaylist(playlist);
    // Show SongName in LV_PlayList

    ui->tableView_PlayList->setModel(model);
}


void Widget::on_Btn_PlayPause_clicked()
{
    if(playlist->isEmpty())
        return;

    if (musicplayer->state() == musicplayer->PausedState || musicplayer->state() == musicplayer->StoppedState)
    {

        ui->Btn_PlayPause->setIcon(QIcon(":/img/Icons/Pause.png"));
        musicplayer->play();
    }
    else
    {
        ui->Btn_PlayPause->setIcon(QIcon(":/img/Icons/Play.png"));
        musicplayer->pause();
    }


/*    musicplayer->setMedia(QMediaContent(QUrl::fromLocalFile("C:/Users/Administrator/Music/Alan Walker - Faded.mp3")));
    musicplayer->setPlaylist(playlist);
    musicplayer->setVolume(50);
    if (musicplayer->state() == musicplayer->StoppedState)
        musicplayer->play();
    else
        musicplayer->stop();*/
}

/*
void setPlaylist(QMediaPlaylist *list,int row,int position,int volume,\
                 QMediaPlayer::State state,QMediaPlaylist::PlaybackMode playmodel,int i)
{
    playlist=list;
        music->setPlaylist(playlist);
        playlist->setCurrentIndex(row);
        music->setPosition(position);
        music->setVolume(volume);
        if(state==QMediaPlayer::PlayingState)
            music->play();
        playlist->setPlaybackMode(playmodel);
}
*/

void Widget::on_Btn_NextMusic_clicked()
{
   if(playlist->isEmpty())
       return;

   int currenIndex = playlist->currentIndex();
   if (++currenIndex == playlist->mediaCount())
   {
       currenIndex = 0;
       playlist->setCurrentIndex(currenIndex);
   }

   musicplayer->play();
}

void Widget::on_Btn_PreMusic_clicked()
{
    if(playlist->isEmpty())
        return;
    int currentIndex = playlist->currentIndex();
    if(--currentIndex < 0)
    {
       currentIndex = 0;
    }
    playlist->setCurrentIndex(currentIndex);
    musicplayer->play();
}

void Widget::ShowSongName()
{
    ui->Lbl_SongName->setText(songName->at(playlist->currentIndex()));
}

void Widget::on_Btn_Close_clicked()
{
    close();
}

void Widget::on_Btn_Min_clicked()
{
    showMinimized();
}


void Widget::on_Btn_Voice_clicked()
{
    if(!musicplayer->isMuted())
    {
        musicplayer->setMuted(true);
        ui->Btn_Voice->setIcon(QIcon(":img/Icons/NoVolume.png"));
    }
    else
    {
        musicplayer->setMuted(false);
        ui->Btn_Voice->setIcon(QIcon(":img/Icons/Volume.png"));
    }
}

void Widget::on_HS_Volume_sliderMoved(int position)
{
    if(position != 0)
    {
        ui->Btn_Voice->setIcon(QIcon(":img/Icons/Volume.png"));
    }
    else
    {
        ui->Btn_Voice->setIcon(QIcon(":img/Icons/NoVolume.png"));
    }
    musicplayer->setVolume(position);
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    this->xOffset = event->globalPos().rx() - this->pos().rx();
    this->yOffset = event->globalPos().ry() - this->pos().ry();
}

void Widget::mouseMoveEvent(QMouseEvent * event)
{
  if (event->buttons() == Qt::LeftButton)
  {
      this->move(event->globalX()-this->xOffset,event->globalY()-this->yOffset);
  }
}


static QString Time(qint64 time)
{
    qint64 seconds=time/1000;
    const qint64 minutes=seconds/60;
    seconds-=minutes*60;
    return QStringLiteral("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'));
}

void Widget::updatePosition(qint64 position)
{
    ui->Lbl_ShowTime->setText(Time(position)+"/"+Time(musicplayer->duration()));
    ui->HS_SongProgress->setValue(position);
}

void Widget::updateDuration(qint64 duration)
{
    ui->HS_SongProgress->setRange(0,duration);
    ui->HS_SongProgress->setEnabled(duration>0);
    ui->HS_SongProgress->setPageStep(duration/10);
}


