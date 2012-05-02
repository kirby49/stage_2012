#ifndef CELL_H
#define CELL_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <iostream>

using namespace std;

class Cell
{

    public :
        Cell();
        Cell(QPoint point,QString value);
        ~Cell();
        QPoint getPos();
        QString getValue();
        void setValue(QString value);

    private :
        QPoint m_pos;
        QString m_value;



};

#endif // CELL_H
