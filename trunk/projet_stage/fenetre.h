#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui/QtGui>
#include "carte.h"



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
    QLabel * label;
    QTextEdit *la;
    QTextEdit *lo;
    //carte
    carte* image;
    //couleur
    QString couleur;



public:
    fenetre();


signals:


public slots:
    void telechargerImage();
    void setCouleur();

};

#endif // FENETRE_H
