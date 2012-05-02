#ifndef MONLABEL_H
#define MONLABEL_H
#include <QtGui/QtGui>

class MyLabel : public QLabel
{
	Q_OBJECT

	public slots:
		void setPlus() {setText("+");}
		void setMinus() {setText("-");}
		void setTimes() {setText("*");}
		void setDiv() {setText("/");}
		void setBracketL() {setText("(");}
		void setBracketR() {setText(")");}
		void setSquare() {setText("^2");}
		void setEqual() {setText("=");}
	
	public:
		MyLabel ( QWidget * parent, Qt::WFlags f = 0 ) : QLabel(parent, f) {}
		MyLabel ( const QString & text, QWidget * parent, Qt::WFlags f = 0 ) : QLabel(text, parent, f) {}
};

#endif // MONLABEL_H
