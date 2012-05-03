#ifndef MENU_H
#define MENU_H

#include "QMenu"
#include "QMainWindow"

class MENU : public QMenu
{
private :
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;


public:
    MENU(QWidget * parent = 0);

};

#endif // MENU_H
