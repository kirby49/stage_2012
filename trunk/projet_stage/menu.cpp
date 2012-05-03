#include "menu.h"

MENU::MENU(QWidget * parent):QMenu(parent)
{

    menuFichier = this->addMenu("&Fichier");
    menuEdition = this->addMenu("&Edition");
    menuAffichage = this->addMenu("&Affichage");


    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");

}
