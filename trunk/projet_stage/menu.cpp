#include "menu.h"

MENU::MENU()
{

    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");
    menuAffichage = menuBar()->addMenu("&Affichage");


    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");

}
