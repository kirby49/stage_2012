#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui/QtGui>
#include "carte.h"
#include "menu.h"


class fenetre : public QMainWindow
{
     Q_OBJECT

private:
    QHBoxLayout* mainLayout;
    carte* image;
    QPushButton* telecharger;
    //MENU *menu;
    QMenu *menuFichier;
    QMenu *menuEdition;

public:
    fenetre();



public slots:
void telechargerImage();


};

#endif // FENETRE_H
