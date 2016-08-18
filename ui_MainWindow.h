/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *camViewer;
    QHBoxLayout *horizontalLayout;
    QPushButton *openCamBtn;
    QPushButton *closeCamBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *takePhotoBtn;
    QListWidget *photoList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(884, 539);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        camViewer = new QLabel(centralWidget);
        camViewer->setObjectName(QString::fromUtf8("camViewer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(camViewer->sizePolicy().hasHeightForWidth());
        camViewer->setSizePolicy(sizePolicy);
        camViewer->setMinimumSize(QSize(0, 0));
        camViewer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        camViewer->setScaledContents(true);

        gridLayout->addWidget(camViewer, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        openCamBtn = new QPushButton(centralWidget);
        openCamBtn->setObjectName(QString::fromUtf8("openCamBtn"));

        horizontalLayout->addWidget(openCamBtn);

        closeCamBtn = new QPushButton(centralWidget);
        closeCamBtn->setObjectName(QString::fromUtf8("closeCamBtn"));
        closeCamBtn->setEnabled(false);

        horizontalLayout->addWidget(closeCamBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        takePhotoBtn = new QPushButton(centralWidget);
        takePhotoBtn->setObjectName(QString::fromUtf8("takePhotoBtn"));
        takePhotoBtn->setEnabled(false);

        horizontalLayout->addWidget(takePhotoBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        photoList = new QListWidget(centralWidget);
        photoList->setObjectName(QString::fromUtf8("photoList"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(photoList->sizePolicy().hasHeightForWidth());
        photoList->setSizePolicy(sizePolicy1);
        photoList->setMinimumSize(QSize(140, 0));
        photoList->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(photoList, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 884, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        camViewer->setText(QString());
        openCamBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        closeCamBtn->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        takePhotoBtn->setText(QApplication::translate("MainWindow", "\346\213\215\347\205\247", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
