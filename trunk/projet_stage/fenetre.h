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
    //carte
    carte* image;
    QRgb coul;



public:
    fenetre();
    void setCouleur(QRgb c);


public slots:
    void telechargerImage();


};

#endif // FENETRE_H
