#include "fenetre.h"


FENETRE::FENETRE()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    //this.setWindowTitle("Le Programme du Zéro v0.0");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

        zoneCentrale = new QMdiArea;

        zoneTexte2 = new QWidget;

        zone= new SOUSFENETREG;

        sousFenetre1 = zoneCentrale->addSubWindow(zone);
       // sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

        setCentralWidget(zoneCentrale);

}


