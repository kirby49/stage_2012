#include <QtGui/QApplication>
#include "directory.h"
#include "ma_ComboBox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Directory d;
    d.show();

    return a.exec();
}

