#include "calculator.h"
#include <iostream>

Calculator::Calculator ( QWidget * parent ) : QWidget(parent)
{ 
  QHBoxLayout *hBox = new QHBoxLayout(this);

  QPushButton *buttonEq = new QPushButton(tr("="),this);
  QLabel *labelRes = new QLabel(this);

  QSpinBox *op1 = new QSpinBox(this);
  QSpinBox *op2 = new QSpinBox(this);
  val1 = 0;
  val2 = 0;

  QComboBox *operateur = new QComboBox(this);
  QStringList strOp;
  strOp << "+" << "-" << "*" << "/";
  operateur->insertItems(0,strOp);
  valOp = '+';

  hBox->addStretch();
  hBox->addWidget(op1);
  hBox->addStretch();
  hBox->addWidget(operateur);
  hBox->addStretch();
  hBox->addWidget(op2);
  hBox->addStretch();
  hBox->addWidget(buttonEq);
  hBox->addStretch();
  hBox->addWidget(labelRes);
  hBox->addStretch();

  QObject::connect(op1, SIGNAL( valueChanged(int) ), this, SLOT( updateOp1(int) ));
  QObject::connect(op2, SIGNAL( valueChanged(int) ), this, SLOT( updateOp2(int) ));
  QObject::connect(operateur, SIGNAL( activated(const QString &) ), this, SLOT( updateOperateur(const QString &) ));
  QObject::connect(buttonEq, SIGNAL( clicked() ), this, SLOT( calcule() ));
  QObject::connect(this, SIGNAL( changeRes(int) ), labelRes, SLOT( setNum(int) ));
}

void Calculator::updateOp1(int v)
{
  val1 = v;
}

void Calculator::updateOp2(int v)
{
  val2 = v;
}

void Calculator::updateOperateur(const QString & str)
{
  valOp = str[0].toAscii();
}

void Calculator::calcule()
{
//   std::cout << val1 << " " << valOp << " " << val2 << std::endl;
  int res=0;
  
  switch (valOp)
  {
  case '+': res = val1 + val2;
    break;
  case '-': res = val1 - val2;
    break;
  case '*': res = val1 * val2;
    break;
  case '/': res = val1 / val2;
    break;
  }

  emit changeRes(res);
}
