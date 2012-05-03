#include "tableur.h"
#include "cellule.h"

#include "iostream"

tableur::tableur(int l, int c)
{

    nbcolonne=l;
    nbligne=c;
    std::cout<<" affichage : "<<nbligne<<" "<<nbcolonne<<std::endl;
    w=new QWidget;
    setCentralWidget(w);
    QHBoxLayout *hbox = new QHBoxLayout(w);
    layout = new QGridLayout;


    if (l!=nbligne)
            for (int i =0;i<nbligne;i++)
                for(int j=0;j<nbcolonne;j++)
                    {
                        cellule *cel=new cellule;
                        layout->addWidget(cel,nbligne,nbcolonne);
                    }
    else if (c!=nbcolonne)
          for (int j =0;j<nbligne;j++)
                for (int i=0;i<nbcolonne;i++)

                    {
                        cellule *cel=new cellule;
                        layout->addWidget(cel,nbligne,nbcolonne);
                    }


    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);



    vbox = new QVBoxLayout;
    vbox->setSpacing(0);


    box1 = new QPushButton("Inserer une ligne");
    QObject::connect(box1, SIGNAL( clicked() ), this, SLOT( ajoutligne() ));
    vbox->addWidget(box1);

    box2 = new QPushButton("Inserer une colonne");
    QObject::connect(box2, SIGNAL( clicked() ), this, SLOT( ajoutcol() ));
    vbox->addWidget(box2);

    hbox->setSpacing(0);
    hbox->addLayout(layout);
    hbox->addLayout(vbox);

    //QObject::connect(this, SIGNAL( changeRes(QGridLayout) ), layout, SLOT( setLayout(QGridLayout) ));

}


void tableur::ajoutligne()
{
    cellule *cel=new cellule;

    std::cout<<"ajoutligne: "<<nbligne<<" "<<nbcolonne<<std::endl;

        for(int j=0;j<nbcolonne;j++)
            {
            layout->addWidget(cel,nbligne,j);
            }


    nbligne ++;


}


void tableur::ajoutcol()
{

    cellule *cel=new cellule;

    std::cout<<"ajoutcol: "<<nbligne<<" "<<nbcolonne<<std::endl;
    for (int j =0;j<nbligne;j++)

              {
              layout->addWidget(cel,j,nbcolonne);
              }

    nbcolonne ++;

}


