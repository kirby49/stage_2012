#ifndef CELLULE_H
#define CELLULE_H
#include <QtGui>

class cellule: public QWidget
{
private:
    int x;
    int y;
    QLabel* label ;


public:
    cellule(int a ,int b);
    int getX();
    int getY();
    void setX(int a);
    void setY(int b);
    ~cellule();
};

#endif // CELLULE_H
