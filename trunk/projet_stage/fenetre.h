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
    QPushButton *gestionnaire;
    bool flag_dock;
    //action
    QAction *save_as;
    QAction *save;
    QAction *zoom_in;
    QAction *zoom_out;
    QAction *exp;
    QAction *affich_dock;
    QAction *effacer;

    // latitude/longitude
    QDoubleSpinBox  *la;
    QDoubleSpinBox  *lo;
    QDoubleSpinBox  *la1;
    QDoubleSpinBox  *lo1;
    //DOCK
    QDockWidget * dock;
    //degree/minute/seconde
    QSpinBox *d1;
    QSpinBox *m1;
    QSpinBox *s1;
    QSpinBox *d2;
    QSpinBox *m2;
    QSpinBox *s2;
    QSpinBox *dd1;
    QSpinBox *mm1;
    QSpinBox *ss1;
    QSpinBox *dd2;
    QSpinBox *mm2;
    QSpinBox *ss2;
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
