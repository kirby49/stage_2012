#include "calc.h"
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

Calculatrice::Calculatrice()
{}

Calculatrice::~Calculatrice()
{}

void Calculatrice::pushCurrentValue()
{
	if (m_currentValue.isEmpty()) return;
	
	m_stackValues.push(m_currentValue.toDouble());
	m_currentValue.clear();
}

int Calculatrice::opArite(int op)
{
	switch (op)
	{
		case PLUS:
		case MINUS:
		case TIMES:
		case DIV:
			return 2;
		case SQUARE:
			return 1;
		case BRACKETL:
		case BRACKETR:
			return 0;
	}
	return -1;
}

int Calculatrice::opPriority(int op)
{
	switch (op)
	{
		case PLUS:
		case MINUS:
			return 3;
		case TIMES:
		case DIV:
			return 5;
		case SQUARE:
			return 7;
		case BRACKETL:
		case BRACKETR:
			return 1;
	}
	return 0;
}

void Calculatrice::doCompute(int nextOp)
{
	// Quand on rencontre une parenthèse ouvrante, il ne faut pas chercher
	// à évaluer ce qu'il y avait avant
	if (nextOp == BRACKETL) return;
	
	while ((!m_stackOp.empty()) &&
			(opPriority(m_stackOp.top()) >= opPriority(nextOp)))
	{
		int op = m_stackOp.top();
		m_stackOp.pop();

		// Cas spécial pour les parenthèses.
		// Il faut s'arrêter de calculer dès qu'on arrive à la parenthèse de
		// gauche
		if ((op == BRACKETL) && (nextOp == BRACKETR)) break;

		double x, y;
		if (opArite(op) > 0)
		{
			if (m_stackValues.empty()) continue;
			y = m_stackValues.top();
			m_stackValues.pop();
		}
		if (opArite(op) > 1)
		{
			if (m_stackValues.empty()) continue;
			x = m_stackValues.top();
			m_stackValues.pop();
		}

		switch (op)
		{
			case PLUS:
				m_stackValues.push(x+y);
				break;
			case MINUS:
				m_stackValues.push(x-y);
				break;
			case TIMES:
				m_stackValues.push(x*y);
				break;
			case DIV:
				m_stackValues.push(x/y);
				break;
			case SQUARE:
				m_stackValues.push(y*y);
				break;
		}
		emit resultatChanged(m_stackValues.top());
	}
}

double Calculatrice::finalCompute()
{
	pushCurrentValue();
	doCompute(-1);
	if (m_stackValues.empty()) return 0;
	else return m_stackValues.top();
}

void Calculatrice::addChar(char c)
{
	m_currentValue += c;
	emit resultatTxtChanged(m_currentValue);
}

void Calculatrice::bracketL()
{
	pushCurrentValue();
	doCompute(BRACKETL);
	m_stackOp.push(BRACKETL);
}

void Calculatrice::bracketR()
{
	pushCurrentValue();
	doCompute(BRACKETR); // On ajoute pas la parenthèse de droite !
}

void Calculatrice::plus()
{
	pushCurrentValue();
	doCompute(PLUS);
	m_stackOp.push(PLUS);
}

void Calculatrice::minus()
{
	pushCurrentValue();
	doCompute(MINUS);
	m_stackOp.push(MINUS);
}

void Calculatrice::times()
{
	pushCurrentValue();
	doCompute(TIMES);
	m_stackOp.push(TIMES);
}

void Calculatrice::div()
{
	pushCurrentValue();
	doCompute(DIV);
	m_stackOp.push(DIV);
}

void Calculatrice::square()
{
	pushCurrentValue();
	doCompute(SQUARE);
	m_stackOp.push(SQUARE);
}

void Calculatrice::equal()
{
	emit resultatChanged(finalCompute());
}

void Calculatrice::zero() {addChar('0');}
void Calculatrice::one() {addChar('1');}
void Calculatrice::two() {addChar('2');}
void Calculatrice::three() {addChar('3');}
void Calculatrice::four() {addChar('4');}
void Calculatrice::five() {addChar('5');}
void Calculatrice::six() {addChar('6');}
void Calculatrice::seven() {addChar('7');}
void Calculatrice::eight() {addChar('8');}
void Calculatrice::nine() {addChar('9');}
void Calculatrice::comma() {addChar('.');}
