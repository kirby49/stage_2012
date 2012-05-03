#include "fenetre.h"

fenetre::fenetre()
{
    //widget central
    QWidget * w = new QWidget;
    setCentralWidget(w);

    //layouts
    mainLayout= new QHBoxLayout(w);

    //carte
    image = new carte();


    //menu
    menu=new MENU(this);


    //bouttons
    telecharger= new QPushButton("telecharger");
    QObject::connect(telecharger, SIGNAL(clicked()), this, SLOT(telechargerImage()));

    //mise en page
    mainLayout->addWidget(image);
    mainLayout->addWidget(telecharger);
    mainLayout->addWidget(menu);


}


void fenetre::telechargerImage()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
       //MessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);
       image->afficherImage(fichier);
}
