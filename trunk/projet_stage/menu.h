#ifndef MENU_H
#define MENU_H

#include <QtGui/QtGui>
#include "carte.h"

class MENU : public QMenu
{
    Q_OBJECT

private :
    carte* image;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;


public:
    MENU(QWidget * parent = 0);


public slots:
    void telechargerImage();
};

#endif // MENU_H
