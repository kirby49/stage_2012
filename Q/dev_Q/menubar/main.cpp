#include <QtGui>


int main (int argc, char* argv[])
{
        QApplication app(argc, argv);

        QMenu *menuFichier = menuBar()->addMenu("&Fichier");

        QAction *actionQuitter = new QAction("&Quitter");
        menuFichier->addAction(actionQuitter);

        QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
        menuFichier.show() ;
        return app.exec() ;
}
