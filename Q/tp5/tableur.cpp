#include "tableur.h"
#include "cellule.h"

tableur::tableur(int l, int c)
{

    nbcolonne=0;
    nbligne=0;

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


    vbox = new QHBoxLayout(w);
    box1 = new QPushButton("Inserer une ligne");
    box2 = new QPushButton("Inserer une colonne");

    vbox->addWidget(box1);
    vbox->addWidget(box2);
    vbox->addLayout(layout);


    QObject::connect(box1, SIGNAL( clicked() ), this, SLOT( ajoutligne() ));
    QObject::connect(box2, SIGNAL( clicked() ), this, SLOT( ajoutcol() ));

}


void tableur::ajoutligne()
{
    delete w;
    delete layout;
    delete frame;
    delete vbox;
    delete box1;
    delete box2;
    nbligne ++;
    tableur tab(nbligne,nbcolonne);
}


void tableur::ajoutcol()
{

    delete w;
    delete layout;
    delete frame;
    delete vbox;
    delete box1;
    delete box2;
    nbcolonne ++;
    tableur tab(nbligne,nbcolonne);

}
