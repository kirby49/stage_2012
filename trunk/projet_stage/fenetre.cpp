#include "fenetre.h"

fenetre::fenetre()
{

    //widget central
    QWidget * w = new QWidget;
    setCentralWidget(w);
    menu = new MENU(this);

    //layouts
    mainLayout= new QHBoxLayout(w);
    //image = new carte();

    //bouttons
    telecharger= new QPushButton("telecharger");
    QObject::connect(telecharger, SIGNAL(clicked()), this, SLOT(telechargerImage()));

    //mise en page
    //mainLayout->addWidget(image);
    mainLayout->addWidget(telecharger);




}


void fenetre::telechargerImage()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
       QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);

}
