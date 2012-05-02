#ifndef CALC_H
#define CALC_H

#include <QtGui/QtGui>
#include <stack>
#include <string>

enum typeOp {
	PLUS,
	MINUS,
	TIMES,
	DIV,
	SQUARE,
	BRACKETL,
	BRACKETR		
};

class Calculatrice : public QObject
{
	Q_OBJECT
			
	private:
		QString        m_currentValue;
		std::stack<double> m_stackValues;
		std::stack<int>    m_stackOp;

		void pushCurrentValue();
		int opArite(int op);
		int opPriority(int op);
		void doCompute(int nextOp);
	
	public:
		Calculatrice();
		~Calculatrice();

		double finalCompute();

		void addChar(char c);

	signals:
		void resultatChanged( double );
		void resultatTxtChanged( const QString & );
		
	public slots:
		void zero();
		void one();
		void two();
		void three();
		void four();
		void five();
		void six();
		void seven();
		void eight();
		void nine();
		void comma();

		void plus();
		void minus();
		void times();
		void div();

		void square();
		void equal();

		void bracketL();
		void bracketR();
};
#endif // CALC_H
