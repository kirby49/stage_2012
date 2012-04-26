#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QtGui>
#include "sousfenetreg.h"

class FENETRE : public QMainWindow
{

public:
    FENETRE();

private:
    SOUSFENETREG *zone;

    QMdiArea *zoneCentrale;

    QWidget *zoneTexte2;

    QMdiSubWindow *sousFenetre1;
    QMdiSubWindow *sousFenetre2;


/*public slots:
   void MenuFenetre();*/

};

#endif // FENETRE_H
