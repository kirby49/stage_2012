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
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);

    signals :

    private :
        QImage m_up;
        QImage m_slider;
        QImage m_down;
        QImage m_carre;



};

#endif // MYWIDGET_H
