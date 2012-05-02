#include "zoneDessin.h"

ZoneDessin::ZoneDessin(QWidget * parent):QWidget(parent)
{

    this->setMinimumSize(400,200);
    m_image = QImage(400,200,QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));

}

ZoneDessin::~ZoneDessin()
{
}

void ZoneDessin::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),m_image);
}

void ZoneDessin::mousePressEvent(QMouseEvent *event)
{
    m_point = event->pos();
    this->setMouseTracking(true);
}

void ZoneDessin::mouseReleaseEvent(QMouseEvent *event)
{
    this->setMouseTracking(false);
    QPoint point;
    m_point = point;
}

void ZoneDessin::mouseMoveEvent(QMouseEvent *event)
{
    QPainter painter(&m_image);
    painter.setPen(Qt::red);

    QPoint point = event->pos();
    painter.drawLine(m_point.x(),m_point.y(),point.x(),point.y());

    m_point = point;
    update();
}

 void ZoneDessin::resizeEvent(QResizeEvent *event)
 {
    if (width() > m_image.width() || height() > m_image.height())
    {
        int newWidth = qMax(width() + 128, m_image.width());
        int newHeight = qMax(height() + 128, m_image.height());
        QSize newSize(newWidth, newHeight);

        if (m_image.size() != newSize)
        {
            QImage newImage(newSize, QImage::Format_RGB32);
            newImage.fill(qRgb(255, 255, 255));
            QPainter painter(&newImage);
            painter.drawImage(QPoint(0, 0), m_image);
            m_image = newImage;
        }
        update();
    }
    QWidget::resizeEvent(event);
 }

 void ZoneDessin::clearImage()
  {
      m_image.fill(qRgb(255, 255, 255));
      update();
  }
