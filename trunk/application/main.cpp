#include <QApplication>
#include "fenetre.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FENETRE fenetre;
    fenetre.show();

    return app.exec();
}
