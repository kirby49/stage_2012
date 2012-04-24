#include <QApplication>
#include "fenetre.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    fenetre f;
    f.show();

    return app.exec();
}
