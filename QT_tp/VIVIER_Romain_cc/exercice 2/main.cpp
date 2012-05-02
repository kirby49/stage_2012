// VIVIER Romain
#include "mainWindow.h"
#include "myWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
