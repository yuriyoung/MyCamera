#ifndef MYCAMERA_H
#define MYCAMERA_H

/****************************************
 *@file MyCamera.h
 *@auth: Yuri Young<yuri.young@qq.com>
 *@date: 2013-11-17
 *****************************************/

#include <QObject>
#include <QImage>

#include <highgui.h>
#include <cv.h>

class MyCamera : public QObject
{
    Q_OBJECT
public:
    explicit MyCamera(QObject *parent = 0);
    ~MyCamera();

    void resize(int width, int height);

signals:
    void sendFrame(const QImage &frame);

public slots:
    bool open();
    void close();
    bool isOpened() const;
    QString takePhoto();

private slots:
    void readFrame();
    void releaseCamara();

private:
    int m_width;
    int m_height;
    bool        m_opened;
    CvCapture*  m_camera;   // 视频获取结构， 用来作为视频获取函数的一个参数
    IplImage*   m_frame;    // 申请IplImage类型指针，就是申请内存空间来存放每一帧图像
};

#endif // MYCAMERA_H
