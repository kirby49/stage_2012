#include "fenetre.h"

fenetre::fenetre()
{
    QWidget * w = new QWidget;
    setCentralWidget(w);
    QVBoxLayout* vbox = new QVBoxLayout();
    QPushButton *button1 = new QPushButton("inserer une ligne");
    QPushButton *button2 = new QPushButton("inserer une colonne");
    vbox->setSpacing(0);
    vbox->addWidget(button1);
    vbox->addWidget(button2);

    QHBoxLayout* hbox = new QHBoxLayout(w);
    //QGridLayout* gridOperators = new QGridLayout();
    QPushButton* tableau  = new QPushButton("tableau");


    hbox->setSpacing(0);
    hbox->addWidget(tableau);
    hbox->addLayout(vbox);

}
