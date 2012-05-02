// VIVIER Romain
#include "myWidget.h"

MyWidget::MyWidget(QWidget * parent):QWidget(parent)
{
    this->setMinimumSize(20,20);
    m_image = QImage(QSize(20,20), QImage::Format_RGB32);
    m_image.fill(qRgb(0, 0, 0));
    m_frontImage = QImage(QSize(16,16), QImage::Format_RGB32);
    m_frontImage.fill(qRgb(255, 255, 255));
    m_clicked = false;

}

MyWidget::~MyWidget()
{
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if(m_clicked)
    {
        stateChanged(false);
        clearImage();
    }else{
        stateChanged(true);
        m_clicked = true;
        QPainter painter(&m_frontImage);
        painter.drawLine(0,0,16,16);
        painter.drawLine(16,0,0,16);
        update();
    }
}


void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter frontpainter(&m_image);
    frontpainter.drawImage(QPoint(2,2),m_frontImage);
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),m_image);
}

void MyWidget::clearImage()
{
    m_clicked =false;
    m_image.fill(qRgb(0, 0, 0));
    m_frontImage.fill(qRgb(255, 255, 255));
    update();
}

void MyWidget::enterEvent(QEvent *event)
{
    m_image.fill(qRgb(100, 100, 100));
    update();
}

void MyWidget::leaveEvent(QEvent *event)
{
    m_image.fill(qRgb(0, 0, 0));
    update();
}

