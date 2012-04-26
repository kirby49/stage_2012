#include "fenetre.h"

fenetre::fenetre(): QWidget()
{

    setFixedSize(600, 200);
     valop = '+';
     ga=0;
     dr=0;
    gauche= new QSpinBox(this);
    gauche->setRange(0,10);
    gauche->setValue(0);
    gauche->move(10,100);
    QObject::connect(gauche, SIGNAL( valueChanged(int) ), this, SLOT( updateOp1(int) ));

    droite= new QSpinBox(this);
    droite->setRange(0,10);
    droite->setValue(0);
    droite->move(50,100);
    QObject::connect(droite, SIGNAL( valueChanged(int) ), this, SLOT( updateOp2(int) ));


    operateur= new QComboBox(this);
    QStringList strOp;
    strOp << "+" << "-" << "*" << "/";
    operateur->insertItems(0,strOp);

    operateur->move(90,100);
    QObject::connect(operateur, SIGNAL( activated(const QString &) ), this, SLOT( updateOperateur(const QString &) ));


    activer=new QPushButton("=",this);
    activer->move(150,100);
    QObject::connect(activer, SIGNAL( clicked() ), this, SLOT( calcule() ));

    res = new QLabel(this);
    res->move(250,100);
    QObject::connect(this, SIGNAL( changeRes(int) ), res, SLOT( setNum(int) ));

}

void fenetre::updateOp1(int v)
{
  ga = v;
}

void fenetre::updateOp2(int v)
{
  dr = v;
}

void fenetre::updateOperateur(const QString & str)
{
  valop = str[0].toAscii();
}

void fenetre::calcule()
{
 //std::cout << val1 << " " << valOp << " " << val2 << std::endl;
  int res=0;

  switch (valop)
  {
  case '+': res = ga + dr;
    break;
  case '-': res = ga - dr;
    break;
  case '*': res = ga * dr;
    break;
  case '/': res = ga / dr;
    break;
  }

  emit changeRes(res);
}

