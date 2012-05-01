#include <QtGui>
#include "fenetre.h"

int main (int argc, char* argv[])
{
        QApplication app(argc, argv);
        fenetre w;
        w.show() ;
        return app.exec() ;
}

