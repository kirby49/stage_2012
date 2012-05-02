#include <QtGui/QApplication>
#include "Mafenetre.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mafenetre fenetre;
    fenetre.show();

    return a.exec();
}
