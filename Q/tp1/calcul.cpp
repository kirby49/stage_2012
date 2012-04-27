#include "calcul.h"

calcul::calcul() : QWidget()
{
    g = new QSpinBox(this);
    g->setRange(0,10);
    g->setValue(0);
    g->move(30,0);
    droite = 0;


    liste = new QComboBox(this);
    liste->addItem("+");
       liste->addItem("-");
       liste->addItem("*");
       liste->addItem("/");
       liste->move(100,0);
  op = '+';

       d= new QSpinBox(this);
    d->setRange(0,10);
    d->setValue(0);
    d->move(170,0);
    gauche = 0;

    bouton = new QPushButton(" = ",this);
    bouton->move(250,0);

    labelRes = new QLabel(this);
    //labelRes->setFixedSize(2,400);
    labelRes->move(400,0);

      QObject::connect(g, SIGNAL( valueChanged(int) ), this, SLOT( updateOp1(int) ));
      QObject::connect(d, SIGNAL( valueChanged(int) ), this, SLOT( updateOp2(int) ));
      QObject::connect(liste, SIGNAL( activated(const QString &) ), this, SLOT( updateOperateur(const QString &) ));
      QObject::connect(bouton, SIGNAL( clicked() ), this, SLOT( calculer() ));
      QObject::connect(this, SIGNAL( changeRes(int) ), labelRes, SLOT( setNum(int) ));
}


void calcul::updateOp1(int v)
{
  gauche = v;
}

void calcul::updateOp2(int v)
{
  droite = v;
}

void calcul::updateOperateur(const QString & str)
{
  op = str[0].toAscii();
}


void calcul::calculer()
{
    int res=0;

      switch (op)
      {
      case '+': res = gauche + droite;
        break;
      case '-': res = gauche - droite;
        break;
      case '*': res = gauche * droite;
        break;
      case '/': res = gauche / droite;
        break;
      }

      emit changeRes(res);

}
