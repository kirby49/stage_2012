#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtGui>

class Calculator : public QWidget
{
	Q_OBJECT

  private:
    int val1;
    int val2;
    char valOp;

  signals :
    void changeRes(int v);

  public slots :
    void updateOp1(int v);
    void updateOp2(int v);
    void updateOperateur(const QString & str);
    void calcule();

  public:
    Calculator ( QWidget * parent = 0 );

};

#endif // CALCULATOR_H
