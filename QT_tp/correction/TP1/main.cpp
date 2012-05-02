// moc -o moc_calculator.cpp calculator.h
// g++  -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -framework QtCore -framework QtGui *.cpp

#include <QtGui>
#include "calculator.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
  Calculator cal; 

	cal.show();
	return app.exec();
}
