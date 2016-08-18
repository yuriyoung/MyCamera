/****************************************
 *@file MainWindow.cpp
 *@auth: Yuri Young<yuri.young@qq.com>
 *@date: 2013-11-17
 *****************************************/

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MyCamera.h"

#include <QCloseEvent>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QTime>
#include <QDate>
#include <QThread>

#define QT_OS_WIN
#include <qt_windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(840, 560);

    m_index = 0;

    m_camera = new MyCamera;
    m_camera->moveToThread(&m_thread);

    connect( m_camera, SIGNAL(sendFrame(QImage)), this, SLOT(recvFrame(QImage)) );
    connect( &m_thread, SIGNAL(finished()), &m_thread, SLOT(deleteLater()) );

    connect(ui->openCamBtn, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(ui->closeCamBtn, SIGNAL(clicked()), this, SLOT(closeCamara()));
    connect(ui->takePhotoBtn, SIGNAL(clicked()), this, SLOT(takePhoto()));
    connect(ui->photoList, SIGNAL(itemDoubleClicked( QListWidgetItem*)),
            this, SLOT(openPhoto(QListWidgetItem*)));

    m_thread.start();
}

MainWindow::~MainWindow()
{
    m_camera->close();
    m_camera->deleteLater();
    m_thread.quit();
    m_thread.wait();
    delete ui;
}

/**
 * 打开摄像头
 * @brief MainWindow::openCamara
 */
void MainWindow::openCamara()
{
    if( !m_camera ) return;

    if(m_camera->open())
        updateUI();
}

/**
 * 关闭摄像头
 * @brief MainWindow::closeCamara
 */
void MainWindow::closeCamara()
{
    m_camera->close();
    QTimer::singleShot(200, this, SLOT(clearViewr()));
    updateUI();
}

/**
 * 读取图像帧信息
 * @brief MainWindow::readFrame
 */
void MainWindow::recvFrame(const QImage &frame)
{
    if( m_camera->isOpened() )
        ui->camViewer->setPixmap(QPixmap::fromImage(frame));
}

/**
 * 拍照生成图片保存到磁盘
 * @brief MainWindow::takePicture
 */
void MainWindow::takePhoto()
{
    QString photo = m_camera->takePhoto();
    QImage img(photo);
    addPhotoToList(QPixmap::fromImage(img), photo);
}

void MainWindow::clearViewr()
{
    ui->camViewer->clear();
}

/**
 * 拍照时，图片添加到缩略图列表中
 * @brief MainWindow::addPhotoToList
 * @param photo
 */
void MainWindow::addPhotoToList(const QPixmap &photo, const QString &name)
{
    //设置QListWidget中的单元项的图片大小
    ui->photoList->setIconSize(QSize(800, 60));
    ui->photoList->setResizeMode(QListView::Adjust);
       //设置QListWidget的显示模式
    ui->photoList->setViewMode(QListView::IconMode);
        //设置QListWidget中的单元项不可被拖动
    ui->photoList->setMovement(QListView::Static);

    //设置QListWidget中的单元项的间距
    ui->photoList->setSpacing(10);
    QFileInfo file(name);
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(photo.scaled(QSize(80,60))),
                                                 file.baseName());
    pItem->setToolTip(name);
    pItem->setData(Qt::UserRole+1, name);

    pItem->setSizeHint(QSize(100,100)); //设置单元项的宽度和高度
    ui->photoList->addItem(pItem);       //添加QListWidgetItem项
}

bool MainWindow::savePhoto(const QImage &image, const QString &basename)
{
    QString savePath = QDir::currentPath() + "/photos/";
    QDir dir(savePath);
    if( !dir.exists(savePath) )
    {
        dir.mkdir(savePath);
    }

    bool ok = image.save(savePath + basename, "JPG");
    if( ! ok )
    {
        return false;
    }
    return true;
}

bool MainWindow::openPhoto(QListWidgetItem *item)
{
    QString filename = item->data(Qt::UserRole+1).toString();

    ShellExecuteW(NULL, QString("open").toStdWString().c_str(),
                  filename.toStdWString().c_str(),
                  NULL, NULL, SW_SHOW);
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    closeCamara();
    //this->thread()->wait(2000);
    event->accept();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    //...
    event->accept();
}

void MainWindow::updateUI()
{
    bool bState = true;
    if( !m_camera->isOpened() )
        bState = !bState;

    ui->closeCamBtn->setEnabled(bState);
    ui->takePhotoBtn->setEnabled(bState);
    ui->openCamBtn->setEnabled(!bState);
}







