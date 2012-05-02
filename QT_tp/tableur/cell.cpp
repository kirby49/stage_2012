#include "cell.h"


Cell::Cell():m_pos(QPoint(0,0)),m_value("")
{
}

Cell::Cell(QPoint point, QString value):m_pos(point),m_value(value)
{
}

Cell::~Cell()
{
}

QPoint Cell::getPos()
{
    return m_pos;
}

QString Cell::getValue()
{
    return m_value;
}

void Cell::setValue(QString value)
{
    m_value = value;
}
