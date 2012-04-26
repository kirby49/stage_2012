#include <QApplication>
#include "fenetre.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    fenetre f1;
    f1.show();

    return app.exec();
}


