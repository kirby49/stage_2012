#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui/QtGui>
#include "carte.h"



class fenetre : public QMainWindow
{
     Q_OBJECT

private:
    QHBoxLayout* mainLayout;

    //MENU *menu;
    //menubar
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    //toolbar
    QToolBar *toolbar;
    QLabel * label;
    //action
    QAction *save_as;
    QAction *save;
    QAction *zoom_in;
    QAction *zoom_out;
    QAction *exp;
    QAction *affich_dock;
    QAction *effacer;

    // latitude/longitude
    QTextEdit *la;
    QTextEdit *lo;
    //DOCK
    QDockWidget * dock;
    //degree/minute/seconde
    QTextEdit *d1;
    QTextEdit *m1;
    QTextEdit *s1;
    QTextEdit *d2;
    QTextEdit *m2;
    QTextEdit *s2;
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
    void valider_dec();
    void valider_sexa();
    void ignor();
    void afficher_dock();



};

#endif // FENETRE_H
