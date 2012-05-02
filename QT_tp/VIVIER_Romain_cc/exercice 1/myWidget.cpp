// VIVIER Romain
#include "myWidget.h"


MyWidget::MyWidget(QWidget * parent):QWidget(parent)
{
    this->setMinimumSize(20,100);
    m_up = QImage(QSize(20,20), QImage::Format_RGB32);
    m_up.fill(qRgb(200, 200, 200));
    m_slider = QImage(QSize(20,100), QImage::Format_RGB32);
    m_slider.fill(qRgb(200, 200, 200));
    m_down = QImage(QSize(20,20), QImage::Format_RGB32);
    m_down.fill(qRgb(200, 200, 200));
    m_carre = QImage(QSize(20,20), QImage::Format_RGB32);
    m_carre.fill(qRgb(50, 50, 50));

}

MyWidget::~MyWidget()
{
}


void MyWidget::paintEvent(QPaintEvent *event)
{
    m_slider.fill(qRgb(200,200,200));
    QPainter uppainter(&m_up);
    uppainter.setPen(Qt::black);
    uppainter.drawLine(0,20,10,0);
    uppainter.drawLine(20,20,10,0);
    QPainter downpainter(&m_down);
    downpainter.setPen(Qt::black);
    downpainter.drawLine(20,0,10,20);
    downpainter.drawLine(0,0,10,20);
    QPainter sliderpainter(&m_slider);
    sliderpainter.drawImage(QPoint(0,0),m_up);
    sliderpainter.drawImage(QPoint(0,20),m_carre);
    sliderpainter.drawImage(QPoint(0,m_slider.height()-20),m_down);
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),m_slider);
}

void MyWidget::resizeEvent(QResizeEvent *event)
{
   if ( height() > m_slider.height())
   {
       int newHeight = qMax(height() + 5, m_slider.height());
       QSize newSize(20, newHeight);

       if (m_slider.size() != newSize)
       {
           QImage newImage(newSize, QImage::Format_RGB32);
           newImage.fill(qRgb(255, 255, 255));
           QPainter painter(&newImage);
           painter.drawImage(QPoint(0, 0), m_slider);
           m_slider = newImage;
       }
       update();
   }
   QWidget::resizeEvent(event);
}

