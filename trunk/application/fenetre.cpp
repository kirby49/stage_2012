#include "fenetre.h"

FENETRE::FENETRE()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

        QAction *actionQuitter = menuFichier->addAction("&Quitter");

        QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

        connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

   /* QMdiArea *zoneCentrale = new QMdiArea;

       QTextEdit *zoneTexte1 = new QTextEdit;
       QTextEdit *zoneTexte2 = new QTextEdit;

       QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(zoneTexte1);
       QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

       setCentralWidget(zoneCentrale);*/
}

/*FENETRE::fenetre_droite()
{


}*/
