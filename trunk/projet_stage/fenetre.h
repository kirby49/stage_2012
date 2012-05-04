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
    //menubar
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;


    //toolbar
    QToolBar *toolbar;
    QLabel * couleur;
    QTextEdit *la;
    QTextEdit *lo;




public:
    fenetre();



public slots:
void telechargerImage();


};

#endif // FENETRE_H
