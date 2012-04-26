#include <QApplication>
#include "calcul.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

   calcul cal;

   cal.show();

    return app.exec();
}
