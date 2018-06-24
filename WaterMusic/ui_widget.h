/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Btn_Voice;
    QPushButton *Btn_OpenFile;
    QSlider *HS_SongProgress;
    QComboBox *CombBox_PlayMode;
    QPushButton *Btn_Expand;
    QPushButton *Btn_Min;
    QPushButton *Btn_Close;
    QLineEdit *lineEdit_Search;
    QTableView *tableView_PlayList;
    QPushButton *Btn_PreMusic;
    QPushButton *Btn_NextMusic;
    QPushButton *Btn_PlayPause;
    QSlider *HS_Volume;
    QLabel *Lbl_SongName;
    QLabel *Lbl_ShowTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(944, 732);
        Btn_Voice = new QPushButton(Widget);
        Btn_Voice->setObjectName(QStringLiteral("Btn_Voice"));
        Btn_Voice->setGeometry(QRect(694, 690, 41, 29));
        Btn_Voice->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Icons/Volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Voice->setIcon(icon);
        Btn_Voice->setFlat(true);
        Btn_OpenFile = new QPushButton(Widget);
        Btn_OpenFile->setObjectName(QStringLiteral("Btn_OpenFile"));
        Btn_OpenFile->setGeometry(QRect(5, 4, 71, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/Icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_OpenFile->setIcon(icon1);
        Btn_OpenFile->setAutoDefault(true);
        Btn_OpenFile->setFlat(true);
        HS_SongProgress = new QSlider(Widget);
        HS_SongProgress->setObjectName(QStringLiteral("HS_SongProgress"));
        HS_SongProgress->setGeometry(QRect(199, 694, 491, 21));
        HS_SongProgress->setContextMenuPolicy(Qt::DefaultContextMenu);
        HS_SongProgress->setOrientation(Qt::Horizontal);
        CombBox_PlayMode = new QComboBox(Widget);
        CombBox_PlayMode->setObjectName(QStringLiteral("CombBox_PlayMode"));
        CombBox_PlayMode->setGeometry(QRect(850, 694, 81, 21));
        Btn_Expand = new QPushButton(Widget);
        Btn_Expand->setObjectName(QStringLiteral("Btn_Expand"));
        Btn_Expand->setGeometry(QRect(848, 0, 33, 29));
        Btn_Expand->setFocusPolicy(Qt::StrongFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("Icons/Expand.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Expand->setIcon(icon2);
        Btn_Expand->setFlat(true);
        Btn_Min = new QPushButton(Widget);
        Btn_Min->setObjectName(QStringLiteral("Btn_Min"));
        Btn_Min->setGeometry(QRect(878, 0, 33, 29));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Icons/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Min->setIcon(icon3);
        Btn_Min->setFlat(true);
        Btn_Close = new QPushButton(Widget);
        Btn_Close->setObjectName(QStringLiteral("Btn_Close"));
        Btn_Close->setGeometry(QRect(908, 0, 33, 29));
        QIcon icon4;
        icon4.addFile(QStringLiteral("Icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Close->setIcon(icon4);
        Btn_Close->setFlat(true);
        lineEdit_Search = new QLineEdit(Widget);
        lineEdit_Search->setObjectName(QStringLiteral("lineEdit_Search"));
        lineEdit_Search->setGeometry(QRect(252, 10, 191, 21));
        tableView_PlayList = new QTableView(Widget);
        tableView_PlayList->setObjectName(QStringLiteral("tableView_PlayList"));
        tableView_PlayList->setGeometry(QRect(0, 40, 951, 631));
        Btn_PreMusic = new QPushButton(Widget);
        Btn_PreMusic->setObjectName(QStringLiteral("Btn_PreMusic"));
        Btn_PreMusic->setGeometry(QRect(3, 690, 61, 31));
        Btn_PreMusic->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/Icons/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PreMusic->setIcon(icon5);
        Btn_PreMusic->setFlat(true);
        Btn_NextMusic = new QPushButton(Widget);
        Btn_NextMusic->setObjectName(QStringLiteral("Btn_NextMusic"));
        Btn_NextMusic->setGeometry(QRect(136, 690, 71, 31));
        Btn_NextMusic->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/Icons/Next.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_NextMusic->setIcon(icon6);
        Btn_NextMusic->setAutoDefault(false);
        Btn_NextMusic->setFlat(true);
        Btn_PlayPause = new QPushButton(Widget);
        Btn_PlayPause->setObjectName(QStringLiteral("Btn_PlayPause"));
        Btn_PlayPause->setGeometry(QRect(72, 690, 71, 31));
        Btn_PlayPause->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/Icons/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PlayPause->setIcon(icon7);
        Btn_PlayPause->setFlat(true);
        HS_Volume = new QSlider(Widget);
        HS_Volume->setObjectName(QStringLiteral("HS_Volume"));
        HS_Volume->setGeometry(QRect(734, 695, 111, 22));
        HS_Volume->setOrientation(Qt::Horizontal);
        Lbl_SongName = new QLabel(Widget);
        Lbl_SongName->setObjectName(QStringLiteral("Lbl_SongName"));
        Lbl_SongName->setGeometry(QRect(200, 670, 501, 20));
        Lbl_ShowTime = new QLabel(Widget);
        Lbl_ShowTime->setObjectName(QStringLiteral("Lbl_ShowTime"));
        Lbl_ShowTime->setGeometry(QRect(565, 708, 121, 21));
        Btn_Voice->raise();
        Btn_OpenFile->raise();
        HS_SongProgress->raise();
        CombBox_PlayMode->raise();
        Btn_Expand->raise();
        Btn_Min->raise();
        Btn_Close->raise();
        lineEdit_Search->raise();
        tableView_PlayList->raise();
        Btn_PreMusic->raise();
        Btn_NextMusic->raise();
        Btn_PlayPause->raise();
        HS_Volume->raise();
        Lbl_SongName->raise();
        Lbl_ShowTime->raise();
        Lbl_SongName->raise();
        Lbl_ShowTime->raise();

        retranslateUi(Widget);

        Btn_NextMusic->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        Btn_Voice->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_OpenFile->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Btn_OpenFile->setText(QString());
        Btn_Expand->setText(QString());
        Btn_Min->setText(QString());
        Btn_Close->setText(QString());
        Btn_PreMusic->setText(QString());
        Btn_NextMusic->setText(QString());
        Btn_PlayPause->setText(QString());
        Lbl_SongName->setText(QString());
        Lbl_ShowTime->setText(QApplication::translate("Widget", "ShowTime:", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
