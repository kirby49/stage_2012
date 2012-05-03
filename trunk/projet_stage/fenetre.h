#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui>
#include "carte.h"

class fenetre : public QMainWindow
{
     Q_OBJECT

private:
    QHBoxLayout* mainLayout;
    carte* image;
    QPushButton* telecharger;


public:
    fenetre();



public slots:
void telechargerImage();


};

#endif // FENETRE_H
