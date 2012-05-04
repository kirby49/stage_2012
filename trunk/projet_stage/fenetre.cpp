#include "fenetre.h"

fenetre::fenetre()
{
    //widget central
    QWidget * w = new QWidget;
    setCentralWidget(w);



    //MENUBAR

    menuFichier = menuBar()->addMenu("&Fichier");

    //ouvrir
    QAction *ouvrir = menuFichier->addAction("Ouvrir");
    ouvrir->setShortcut(QKeySequence("Ctrl+o"));

    //quitter
     QAction *quitter = menuFichier->addAction("&Quitter");
     quitter->setShortcut(QKeySequence("Ctrl+Q"));

     menuEdition = menuBar()->addMenu("&Edition");

     //export
     QAction *exp = menuEdition->addAction("Export aux format GPX");
     exp->setShortcut(QKeySequence("Ctrl+E"));

     menuAffichage = menuBar()->addMenu("&Affichage");

     //zoom avant
     QAction *zoom_in = menuAffichage->addAction("Zoom avant");
     //zoom_in->setShortcut(QKeySequence(""));// a definir

     //zoom arriere
     QAction *zoom_out = menuAffichage->addAction("Zoom arriere");
     zoom_out->setShortcut(QKeySequence("-"));

     //TOOLBAR
     toolbar = addToolBar("Barre d'outils");
     toolbar->addAction(ouvrir);
     toolbar->addSeparator();
     toolbar->addAction(quitter);

     //zone de sélection de couleur

     toolbar->addSeparator();
     couleur = new QLabel (toolbar);
     couleur->setStyleSheet("QLabel { background-color : red; }");
     couleur->setFixedWidth(15);
     couleur->setFixedHeight(15);
     toolbar->addWidget(couleur);
     toolbar->addSeparator();
     // penser a faire le connecte et les fonctions de modifications ...

     //zone coordonnée
     //Lattitude
     QString lat = "Lattitude :";
     toolbar->addAction(lat);
     la = new QTextEdit(toolbar);
     toolbar->addWidget(la);
     la->setFixedHeight(20);
     la->setFixedWidth(150);

     //longitude
     toolbar->addSeparator();
     QString lon = "Longitude :";
     toolbar->addAction(lon);
     lo = new QTextEdit(toolbar);
     toolbar->addWidget(lo);
     lo->setFixedHeight(20);
     lo->setFixedWidth(150);

     //connect
     QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
     QObject::connect(ouvrir, SIGNAL(triggered()),this, SLOT(telechargerImage()));


    //layouts
    mainLayout= new QHBoxLayout(w);

    //carte
    image = new carte();


    //MENU
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

       //MessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);

       // QMessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);

       image->afficherImage(fichier);
}
