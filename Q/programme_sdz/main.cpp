
#include <QApplication>
#include "fenetre.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FENETRE fenetre;
    fenetre.show();


    return app.exec();
}
