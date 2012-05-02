#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <iostream>

using namespace std;

class ZoneDessin : public QWidget
{
    Q_OBJECT

    public :
        ZoneDessin(QWidget * parent = 0);
        ~ZoneDessin();

    public slots:
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void clearImage();

    signals :

    private :
        QPoint m_point;
        QImage m_image;




};

#endif // ZONEDESSIN_H
