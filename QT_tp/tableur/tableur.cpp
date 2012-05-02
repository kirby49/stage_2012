#include "tableur.h"

Tableur::Tableur(QWidget * parent):QWidget(parent)
{
    this->setMinimumSize(100,100);
    m_image = QImage(QSize(100,100), QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));
    m_lign = 4;
    m_column = 4;
    m_textZone = new QLineEdit(this);
    m_textZone->setVisible(false);
    m_textZone->setEnabled(false);


    QObject::connect(m_textZone, SIGNAL(returnPressed()),this,SLOT(addCell()));
}

Tableur::~Tableur()
{
}

void Tableur::mousePressEvent(QMouseEvent *event)
{
    selectClickedCell(event->pos());
    showSelectedCell();
}


void Tableur::paintEvent(QPaintEvent *event)
{
    clearImage();
    drawGrid();
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),m_image);
}

void Tableur::resizeEvent(QResizeEvent *event)
{
   if (width() > m_image.width() || height() > m_image.height())
   {
       m_textZone->setVisible(false);
       m_textZone->setEnabled(false);
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

void Tableur::clearImage()
{
  m_image.fill(qRgb(255, 255, 255));
  update();
}

void Tableur::drawGrid()
{
    calculateCellSize();
    QPainter painter(&m_image);
    painter.setPen(Qt::black);

    for(int i = 0;i<=this->height();i+=m_cellSize.height())
    {
        painter.drawLine(QPoint(0,i),QPoint(this->width(),i));
    }

    for(int i = 0;i<=this->width();i+=m_cellSize.width())
    {
        painter.drawLine(QPoint(i,0),QPoint(i,this->height()));
    }

    if(!m_cellList.isEmpty())
    {
        Cell cell;
        foreach (cell, m_cellList)
        {
            QPoint point = QPoint(cell.getPos().x()*m_cellSize.width(),(cell.getPos().y()*m_cellSize.height()+m_cellSize.height()/2));

            painter.drawText(point,cell.getValue());
        }
    }

    update();
}

void Tableur::showSelectedCell()
{
    QPainter painter(&m_image);
    painter.setPen(Qt::red);

    m_textZone->setGeometry(m_cellSize.width()*m_cellSelected.x(),m_cellSize.height()*m_cellSelected.y(),m_cellSize.width(),m_cellSize.height());
    m_textZone->setVisible(true);
    m_textZone->setEnabled(true);
}

void Tableur::calculateCellSize()
{
    m_cellSize.setWidth(this->width()/m_column);
    m_cellSize.setHeight(this->height()/m_lign);
}

void Tableur::setLign(int lign)
{
    m_lign = lign;
}

void Tableur::setColumn(int column)
{
    m_column = column;
}

void Tableur::selectClickedCell(QPoint point)
{
    m_cellSelected.setX(point.x()/m_cellSize.width());
    m_cellSelected.setY(point.y()/m_cellSize.height());
}

void Tableur::addLign()
{
    m_textZone->setVisible(false);
    m_textZone->setEnabled(false);
    setLign(m_lign+1);
    drawGrid();
}

void Tableur::addColumn()
{
    m_textZone->setVisible(false);
    m_textZone->setEnabled(false);
    setColumn(m_column+1);
    drawGrid();
}


void Tableur::addCell()
{
    Cell cell;
    if(!m_cellList.isEmpty())
    {
        bool ok =false;
        foreach(cell ,m_cellList)
        {
            if(cell.getPos() == m_cellSelected)
            {
                cell.setValue(m_textZone->text());
                ok = true;
            }
        }
        if(!ok)
        {
            cell = Cell(m_cellSelected,m_textZone->text());
            m_cellList.push_back(cell);
        }
    }else{
        cell = Cell(m_cellSelected,m_textZone->text());
        m_cellList.push_back(cell);
    }
    m_textZone->setVisible(false);
    m_textZone->setEnabled(false);

    update();
}
