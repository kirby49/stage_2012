#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui>
#include "cellule.h"

class fenetre : public QMainWindow
{
     Q_OBJECT
private:
int x;
int y;
QGridLayout* tableau;

public:
    fenetre();
    int getX();
    int getY();
    void setX(int a);
    void setY(int b);


public slots:
    void ajouterLigne();
    void ajoutercolonne();

};

#endif // FENETRE_H
