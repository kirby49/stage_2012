#include "tableur.h"

#include <QApplication>

int main (int argc, char* argv[])
{

    QApplication app(argc, argv);

    tableur tab(0,0);

    tab.show();

    return app.exec();

}
