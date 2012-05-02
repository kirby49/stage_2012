// VIVIER Romain
#include "myWidget.h"

MyWidget::MyWidget(QWidget * parent):QWidget(parent)
{
    this->setMinimumSize(100,100);
    m_image = QImage(QSize(100,100), QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));
    m_indexPoint = -1;
    m_move = -1;
    m_delete = false;

}

MyWidget::~MyWidget()
{
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    if(checkPoints(point))
        m_pointList.push_back(point);
    else
    {
        if(event->button() == Qt::LeftButton)
        {
            if(m_move != 1)
                m_delete = true;
        }
    }

    update();
}


void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_indexPoint =-1;
    m_move =-1;
}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_indexPoint != -1)
    {
        m_move = 1;
        m_pointList[m_indexPoint] = event->pos();
    }
    update();
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete && m_delete)
        m_pointList.remove(m_indexPoint);
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    clearImage();
    displayPoints();
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),m_image);
}

void MyWidget::resizeEvent(QResizeEvent *event)
{
   if (width() > m_image.width() || height() > m_image.height())
   {
       QSize newSize(width(), height());
       QImage newImage(newSize, QImage::Format_RGB32);
       newImage.fill(qRgb(255, 255, 255));
       QPainter painter(&newImage);
       painter.drawImage(QPoint(0, 0), m_image);
       m_image = newImage;

       update();
   }
   QWidget::resizeEvent(event);
}

void MyWidget::clearImage()
{
  m_image.fill(qRgb(255, 255, 255));
}

void MyWidget::displayPoints()
{
    QPainter painter(&m_image);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    if(!m_pointList.isEmpty())
    {
        int i;
        for(i=0; i< m_pointList.size(); i++)
        {
            painter.drawEllipse(m_pointList[i].x(),m_pointList[i].y(),6,6);
            if( i+1 < m_pointList.size())
                painter.drawLine(m_pointList[i],m_pointList[i+1]);
        }
    }
}

bool MyWidget::checkPoints(QPoint checkpoint)
{
    if(!m_pointList.isEmpty())
    {
        for(int i= 0 ; i<m_pointList.size() ; i++)
        {
            QPoint point = m_pointList[i];
            int dif = sqrt(double(((point.x()-checkpoint.x())*(point.x()-checkpoint.x()))+((point.y()-checkpoint.y())*(point.y()-checkpoint.y()))));
            if(dif < 9)
            {
                m_indexPoint = i;
                return false;
            }
        }
    }
    return true;
}
