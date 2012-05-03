#ifndef MENU_H
#define MENU_H

#include "QMenu"
#include "QMainWindow"

class MENU : public QMainWindow
{
private :
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;


public:
    MENU();

};

#endif // MENU_H
