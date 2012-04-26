#include "calcul.h"

calcul::calcul()
{
    g = new QSpinBox(this);
    g->setRange(0,10);
    g->setValue(0);
    g->move(30,0);

    liste = new QComboBox(this);
    liste->addItem("+");
       liste->addItem("-");
       liste->addItem("*");
       liste->addItem("/");
       liste->move(100,0);

       d= new QSpinBox(this);
    d->setRange(0,10);
    d->setValue(0);
    d->move(170,0);


    bouton = new QPushButton(" = ",this);
    bouton->move(250,0);

    res = new QLineEdit;
    QObject::connect(bouton, SIGNAL(clicked()), res, SLOT(calculer(g->value(),liste->view(),d->value())));
    res->move(400,0);
}

calcul::calculer(int x, QString c, int y)
{
    if (c=="+") (x+y);
            else if (c=="-")  (x-y);
                else if (c=="*")  (x*y);
                        else if (c=="/")  (x/y);
                            else return 0;

}
