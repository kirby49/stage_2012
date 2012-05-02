#include "tableur.h"
#include "cellule.h"
#include "iostream"


tableur::tableur(int l, int c)
{

    nbcolonne=0;
    nbligne=0;
    std::cout<<" affichage :"<<nbligne<<" "<<nbcolonne<<std::endl;
    w=new QWidget;
    setCentralWidget(w);

    layout = new QGridLayout;
    frame = new QFrame(this);

    frame->setFrameShape(QFrame::StyledPanel);
    frame->setGeometry(100, 100, 500, 500);

    if (l!=nbligne)
            for (int i =nbligne;i<l;i++)
                    {
                        cellule *cel=new cellule;
                        layout->addWidget(cel,nbligne+1,nbcolonne);
                    }
    else if (c!=nbcolonne)
        for (int i=nbligne;i<c;i++)
                    {
                        cellule *cel=new cellule;
                        layout->addWidget(cel,nbligne,nbcolonne+1);
                    }


    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    frame->setLayout(layout);


    vbox = new QVBoxLayout(w);
    vbox->addLayout(layout);
    box1 = new QPushButton("Inserer une ligne");
    box2 = new QPushButton("Inserer une colonne");

    vbox->addWidget(box1);
    vbox->addWidget(box2);


    //frame->setLayout(layout);

    QObject::connect(box1, SIGNAL( clicked() ), this, SLOT( ajoutligne() ));
    QObject::connect(box2, SIGNAL( clicked() ), this, SLOT( ajoutcol() ));
    QObject::connect(this, SIGNAL( changeRes(QGridLayout) ), layout, SLOT( setLayout(QGridLayout) ));

}


void tableur::ajoutligne()
{
    cellule *cel=new cellule;
    std::cout<<"ajoutligne"<<nbligne<<" "<<nbcolonne<<std::endl;
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    emit layout->addWidget(cel,nbligne,nbcolonne);

    nbligne ++;

}


void tableur::ajoutcol()
{
    cellule *cel=new cellule;
    std::cout<<"ajoutcol"<<nbligne<<" "<<nbcolonne<<std::endl;
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    emit layout->addWidget(cel,nbligne,nbcolonne+1);
    nbcolonne ++;
}


