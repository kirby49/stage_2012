#include <QtGui/QtGui>
#include <iostream>
#include <string>

#include "monlabel.h"
#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow()
{
//	calc.addChar('1');
//	calc.addChar('0');
//	calc.addChar('.');
//	calc.addChar('5');
//	calc.plus();
//	calc.square();
//	calc.bracketL();
//	calc.addChar('2');
//	calc.times();
//	calc.addChar('2');
//	calc.bracketR();
//
//	cout << "=" << calc.finalCompute() << endl;

	QWidget * w = new QWidget;
	setCentralWidget(w);
	QVBoxLayout* vbox = new QVBoxLayout(w);

	QHBoxLayout* hbox = new QHBoxLayout();
		
	QGridLayout* gridNumbers = new QGridLayout();
	QPushButton* b0 = new QPushButton("0", w);
	QPushButton* b1 = new QPushButton("1", w);
	QPushButton* b2 = new QPushButton("2", w);
	QPushButton* b3 = new QPushButton("3", w);
	QPushButton* b4 = new QPushButton("4", w);
	QPushButton* b5 = new QPushButton("5", w);
	QPushButton* b6 = new QPushButton("6", w);
	QPushButton* b7 = new QPushButton("7", w);
	QPushButton* b8 = new QPushButton("8", w);
	QPushButton* b9 = new QPushButton("9", w);
	QPushButton* bComma = new QPushButton(",", w);

	gridNumbers->setSpacing(0);
	gridNumbers->addWidget(b7,0,0);
	gridNumbers->addWidget(b8,0,1);
	gridNumbers->addWidget(b9,0,2);
	gridNumbers->addWidget(b4,1,0);
	gridNumbers->addWidget(b5,1,1);
	gridNumbers->addWidget(b6,1,2);
	gridNumbers->addWidget(b1,2,0);
	gridNumbers->addWidget(b2,2,1);
	gridNumbers->addWidget(b3,2,2);
	gridNumbers->addWidget(b0,3,0,1,2);
	gridNumbers->addWidget(bComma,3,2);

	QGridLayout* gridOperators = new QGridLayout();
	QPushButton* bPlus = new QPushButton("+", w);
	QPushButton* bMinus = new QPushButton("-", w);
	QPushButton* bTimes = new QPushButton("*", w);
	QPushButton* bDiv = new QPushButton("/", w);
	QPushButton* bBracketL = new QPushButton("(", w);
	QPushButton* bBracketR = new QPushButton(")", w);
	QPushButton* bSquare = new QPushButton("^2", w);
	QPushButton* bEqual = new QPushButton("=", w);

	gridOperators->setSpacing(0);
	gridOperators->addWidget(bPlus,0,0);
	gridOperators->addWidget(bMinus,0,1);
	gridOperators->addWidget(bTimes,1,0);
	gridOperators->addWidget(bDiv,1,1);
	gridOperators->addWidget(bBracketL,2,0);
	gridOperators->addWidget(bBracketR,2,1);
	gridOperators->addWidget(bSquare,3,0);
	gridOperators->addWidget(bEqual,3,1);

	hbox->setSpacing(0);
	hbox->addStretch();
	hbox->addLayout(gridNumbers);
	hbox->addStretch();
	hbox->addLayout(gridOperators);
	hbox->addStretch();

	MyLabel* resultat = new MyLabel(w);
	resultat->setText(QString("0"));
	
  QPalette palette = resultat->palette();
  palette.setColor(resultat->backgroundRole(), QColor(189,255,100));
  resultat->setPalette(palette);
	resultat->setAutoFillBackground( true );


	resultat->setFrameShape(QFrame::StyledPanel);
	resultat->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
	
	MyLabel* opPrint = new MyLabel(w);

  opPrint->setPalette(palette);
	opPrint->setAutoFillBackground( true );

	opPrint->setFrameShape(QFrame::StyledPanel);
	opPrint->setAlignment(Qt::AlignCenter);
	opPrint->setMinimumWidth(30);

	QHBoxLayout* opPrintLayout = new QHBoxLayout();
	opPrintLayout->addStretch();
	opPrintLayout->addWidget(opPrint);

	vbox->setMargin(0);
	vbox->setSpacing(0);
	vbox->addStretch();
	vbox->addWidget(resultat);
	vbox->addLayout(opPrintLayout);
	vbox->addStretch();
	vbox->addLayout(hbox);
	vbox->addStretch();
	
	// Les signaux
	QObject::connect( bPlus, SIGNAL( clicked() ), opPrint, SLOT( setPlus() ));
	QObject::connect( bMinus, SIGNAL( clicked() ), opPrint, SLOT( setMinus() ));
	QObject::connect( bTimes, SIGNAL( clicked() ), opPrint, SLOT( setTimes() ));
	QObject::connect( bDiv, SIGNAL( clicked() ), opPrint, SLOT( setDiv() ));
	QObject::connect( bBracketL, SIGNAL( clicked() ), opPrint, SLOT( setBracketL() ));
	QObject::connect( bBracketR, SIGNAL( clicked() ), opPrint, SLOT( setBracketR() ));
	QObject::connect( bSquare, SIGNAL( clicked() ), opPrint, SLOT( setSquare() ));
	QObject::connect( bEqual, SIGNAL( clicked() ), opPrint, SLOT( setEqual() ));
	
	QObject::connect( bPlus, SIGNAL( clicked() ), &m_calc, SLOT( plus() ));
	QObject::connect( bMinus, SIGNAL( clicked() ), &m_calc, SLOT( minus() ));
	QObject::connect( bTimes, SIGNAL( clicked() ), &m_calc, SLOT( times() ));
	QObject::connect( bDiv, SIGNAL( clicked() ), &m_calc, SLOT( div() ));
	QObject::connect( bBracketL, SIGNAL( clicked() ), &m_calc, SLOT( bracketL() ));
	QObject::connect( bBracketR, SIGNAL( clicked() ), &m_calc, SLOT( bracketR() ));
	QObject::connect( bSquare, SIGNAL( clicked() ), &m_calc, SLOT( square() ));
	QObject::connect( bEqual, SIGNAL( clicked() ), &m_calc, SLOT( equal() ));

	QObject::connect( b0, SIGNAL( clicked() ), &m_calc, SLOT( zero() ));
	QObject::connect( b1, SIGNAL( clicked() ), &m_calc, SLOT( one() ));
	QObject::connect( b2, SIGNAL( clicked() ), &m_calc, SLOT( two() ));
	QObject::connect( b3, SIGNAL( clicked() ), &m_calc, SLOT( three() ));
	QObject::connect( b4, SIGNAL( clicked() ), &m_calc, SLOT( four() ));
	QObject::connect( b5, SIGNAL( clicked() ), &m_calc, SLOT( five() ));
	QObject::connect( b6, SIGNAL( clicked() ), &m_calc, SLOT( six() ));
	QObject::connect( b7, SIGNAL( clicked() ), &m_calc, SLOT( seven() ));
	QObject::connect( b8, SIGNAL( clicked() ), &m_calc, SLOT( eight() ));
	QObject::connect( b9, SIGNAL( clicked() ), &m_calc, SLOT( nine() ));
	QObject::connect( bComma, SIGNAL( clicked() ), &m_calc, SLOT( comma() ));

	QObject::connect( &m_calc, SIGNAL( resultatChanged(double) ), resultat, SLOT( setNum(double) ));
	QObject::connect( &m_calc, SIGNAL( resultatTxtChanged( const QString & ) ), resultat, SLOT( setText( const QString & ) ));
}

MainWindow::~MainWindow()
{
}

