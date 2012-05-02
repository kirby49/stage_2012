#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QtGui>
#include "calc.h"

class MainWindow : public QMainWindow
{
	Calculatrice m_calc;
public:
	MainWindow();
	~MainWindow();
};

#endif
