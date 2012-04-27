#include <QApplication>
#include "directory.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

   directory dir;

   dir.show();

    return app.exec();
}

