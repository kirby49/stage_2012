#include "sousfenetreg.h"

SOUSFENETREG::SOUSFENETREG() : QWidget()
{

    //setFixedSize(,600);
    bouton1 = new QPushButton("Inserer une carte",this);
    bouton2 = new QPushButton("Selectionner le point de depart",this);// il va faloir une case pour ressortir les coordonnée GPS
    bouton3 = new QPushButton("Selectionner le point d\'arriver",this);// de même
    bouton4 = new QPushButton("Selectionner le type de trace a l\'aide de la pipette",this);//pipette avec un champs qui ressort la couleur sélectionner
    bouton5 = new QPushButton("Export du projet en format GPX",this);

    layout = new QGridLayout(this);
    layout->addWidget(bouton1, 0, 0);
    layout->addWidget(bouton2, 1, 0);
    layout->addWidget(bouton3, 2, 0);
    layout->addWidget(bouton4, 3, 0);
    layout->addWidget(bouton5, 4, 0);
    setLayout(layout);
}
