#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/****************************************
 *@file MainWindow.h
 *@auth: Yuri Young<yuri.young@qq.com>
 *@date: 2013-11-17
 *****************************************/

#include <QMainWindow>
#include <QListWidgetItem>
#include <QImage>
#include <QTimer>
#include <QThread>

class MyCamera;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openCamara();
    void closeCamara();
    void recvFrame(const QImage &frame);

    void takePhoto();
    void clearViewer();
    void addPhotoToList(const QPixmap &photo, const QString &name);
    bool savePhoto(const QImage &image, const QString &basename);
    bool openPhoto(QListWidgetItem *item);

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    void updateUI();

private:
    Ui::MainWindow *ui;
    QThread     m_thread;
    MyCamera*   m_camera;
    int         m_index;
};

#endif // MAINWINDOW_H
