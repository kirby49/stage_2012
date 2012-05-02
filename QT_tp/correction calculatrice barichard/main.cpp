// moc -o moc_calc.cpp calc.h
// moc -o moc_monlabel.cpp monlabel.h
// g++  -I/usr/include/qt4 -lQtCore -lQtGui *.cpp
#include <QtGui/QtGui>

#include "mainwindow.h"

int main (int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow w;
	w.show() ;
	return app.exec() ;
}
