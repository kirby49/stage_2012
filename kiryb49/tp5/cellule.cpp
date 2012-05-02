#include "cellule.h"

cellule::cellule(int a, int b)
{
     x=a;
     y=b;
     label= new QLabel(this);
     label->setText("coord: ");

}

int cellule::getX(){
    return x;
}

int cellule::getY(){
  return y;
}

void cellule::setX(int a)
{
x=a;
}

void cellule::setY(int b)
{
y=b;
}

cellule::~cellule(){

}
