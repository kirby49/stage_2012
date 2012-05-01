#include "tableur.h"
#include <QApplication>

int main (int argc, char* argv[])
{

    QApplication app(argc, argv);

    tableur tab;

    tab.show();

    return app.exec();

}
