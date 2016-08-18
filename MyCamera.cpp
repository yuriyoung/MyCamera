/****************************************
 *@file MyCamera.cpp
 *@auth: Yuri Young<yuri.young@qq.com>
 *@date: 2013-11-17
 *****************************************/

#include "MyCamera.h"
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QDir>

#include <QDebug>

MyCamera::MyCamera(QObject *parent) :
    QObject(parent), m_opened(false)
{
    m_camera = NULL;
    m_width = 800;
    m_height = 420;
}

MyCamera::~MyCamera()
{
    qDebug() << "MyCamera::~MyCamera";
    releaseCamara();
}

void MyCamera::resize(int width, int height)
{
    width <= 0 ? width = 1 : width;
    height <= 0 ? height = 1 : height;
    m_width = width;
    m_height = height;
}

bool MyCamera::open()
{
    if( m_camera )
        return m_opened = true;

    m_camera = cvCreateCameraCapture(0);
    m_camera != NULL ? m_opened = true: m_opened = false;

    if(m_opened)
        QTimer::singleShot(0, this, SLOT(readFrame()));

    return m_opened;
}

void MyCamera::close()
{
    m_opened = false;
}

bool MyCamera::isOpened() const
{
    return m_opened;
}

QString MyCamera::takePhoto()
{
    QString d = QDate::currentDate().toString("yyyy-MM-dd ");
    QString t =  QTime::currentTime().toString("hhmmss");
    QString photoName = QString("photo%1.jpg").arg(d+t);

    QString savePath = QDir::currentPath() + "/photos/";
    QDir dir(savePath);
    if( !dir.exists(savePath) )
        dir.mkdir(savePath);

    photoName = savePath + photoName;

    IplImage *srcFrame = cvQueryFrame(m_camera);
    cvCvtColor(srcFrame, srcFrame, CV_BGR2RGB);

    CvSize size;
    size.width = srcFrame->width * 4;
    size.height = srcFrame->height * 4;
    IplImage* desImage = cvCreateImage(size, srcFrame->depth, srcFrame->nChannels);
    cvResize(srcFrame, desImage, CV_INTER_LINEAR);

    cvSaveImage( photoName.toStdString().data(), desImage );

    // 使用cvCreateImage创建图像时必须要释放内存
    cvReleaseImage(&desImage);

    return photoName;
}

void MyCamera::readFrame()
{
    if( !m_camera ) return;

    while( m_opened )
    {
        // 缩放
//        CvSize size;
//        size.width = m_width;
//        size.height = m_width;
        // 从摄像头中抓取并返回每一帧
        IplImage* srcFrame = cvQueryFrame(m_camera);
        cvCvtColor(srcFrame, srcFrame, CV_BGR2RGB);

//        IplImage* desImage = cvCreateImage(size, srcFrame->depth, srcFrame->nChannels);
//        cvResize(srcFrame, desImage, CV_INTER_LINEAR);

        //QImage::Format_RGB888不同的摄像头用不同的格式。
        QImage image((const uchar*)srcFrame->imageData, srcFrame->width,
                     srcFrame->height, QImage::Format_RGB888);
        emit sendFrame(image);
    }

    releaseCamara();
}

void MyCamera::releaseCamara()
{
    if(m_camera)
        cvReleaseCapture(&m_camera);
}
