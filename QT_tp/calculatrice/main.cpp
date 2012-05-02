#include <QtGui/QApplication>
#include "calculatrice.h"
#include "moteur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculatrice c;
    c.show();

    return a.exec();
}
