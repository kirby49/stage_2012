#include "fenetre.h"

fenetre::fenetre()
{
    QWidget * w = new QWidget;
    setCentralWidget(w);
    QVBoxLayout* vbox = new QVBoxLayout();
    QPushButton *button1 = new QPushButton("inserer une ligne");
    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(ajouterLigne()));
    QPushButton *button2 = new QPushButton("inserer une colonne");
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(ajoutercolonne()));
    vbox->setSpacing(0);
    vbox->addWidget(button1);
    vbox->addWidget(button2);

    QHBoxLayout* hbox = new QHBoxLayout(w);

    tableau  = new QGridLayout();
    cellule* cell1= new cellule(0,0);
    cellule* cell2= new cellule(1,0);
    cellule* cell3= new cellule(0,1);
    cellule* cell4= new cellule(1,1);
    cellule* cell5= new cellule(0,2);
    cellule* cell6= new cellule(1,2);

    tableau->addWidget(cell1,0,0);
    tableau->addWidget(cell2,1,0);
    tableau->addWidget(cell3,0,1);
    tableau->addWidget(cell4,1,1);
    tableau->addWidget(cell5,0,2);
    tableau->addWidget(cell6,1,2);
    hbox->setSpacing(0);
    hbox->addLayout(tableau);
    hbox->addLayout(vbox);

    x=1;
    y=2;

}

int fenetre::getX(){
    return x;
}

int fenetre::getY(){
  return y;
}

void fenetre::setX(int a)
{
x=a;
}

void fenetre::setY(int b)
{
y=b;
}


void fenetre::ajoutercolonne(){

    setY((getY()+1));
    int j=getY();
        for (int i=0; i<=x; i++)
        {
            cellule* cell= new cellule(i,j);
            tableau->addWidget(cell,i,j);
        }

 }

void fenetre::ajouterLigne(){

    setX((getX()+1));
    int i=getX();
        for (int j=0; j<=y; j++)
        {
            cellule* cell= new cellule(i,j);
            tableau->addWidget(cell,i,j);
        }

}
