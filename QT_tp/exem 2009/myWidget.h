// VIVIER Romain
#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <iostream>

using namespace std;

class MyWidget : public QWidget
{
    Q_OBJECT

    public :
        MyWidget(QWidget * parent = 0);
        ~MyWidget();
        void displayPoints();
        bool checkPoints(QPoint checkpoint);
        bool checkLines(QPoint checkpoint);
        void selectPoint();

    public slots:
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void clearImage();

    signals :

    private :
        QImage m_image;
        QVector<QPoint> m_pointList;
        int m_indexPoint;
        int m_move;
        bool m_delete;



};

#endif // MYWIDGET_H
