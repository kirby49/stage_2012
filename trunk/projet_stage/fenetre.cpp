#include "fenetre.h"

fenetre::fenetre()
{
    //widget central
    QWidget * w = new QWidget;
    setCentralWidget(w);

    //menuBar
    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");

    //ouvrir
    QAction *ouvrir = menuFichier->addAction("Ouvrir");
    ouvrir->setShortcut(QKeySequence("Ctrl+o"));
    QObject::connect(ouvrir, SIGNAL(triggered()),this, SLOT(telechargerImage()));

    //quitter
     QAction *quitter = menuFichier->addAction("&Quitter");
     quitter->setShortcut(QKeySequence("Ctrl+Q"));
     QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    //layouts
    mainLayout= new QHBoxLayout(w);

    //carte
    image = new carte();


    //menu
    //menu=new MENU(this);


    //bouttons
    //telecharger= new QPushButton("telecharger");
    // QObject::connect(telecharger, SIGNAL(clicked()), this, SLOT(telechargerImage()));

    //mise en page
    mainLayout->addWidget(image);
   // mainLayout->addWidget(telecharger);



}


void fenetre::telechargerImage()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
       // QMessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);
       image->afficherImage(fichier);
}
