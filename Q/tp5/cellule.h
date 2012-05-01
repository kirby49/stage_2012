#ifndef CELLULE_H
#define CELLULE_H

#include <Qt/QtGui>

class cellule :public QWidget
{
private:
    int x;
    int y;
   // QlineEdit contient;
    QLabel *frame;


public:
    cellule();
};

#endif // CELLULE_H
