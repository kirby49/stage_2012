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

    public slots:
        void mousePressEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        void clearImage();

    signals :

    private :
        QImage m_image;
        QImage m_frontImage;
        bool m_clicked;


};

#endif // MYWIDGET_H
