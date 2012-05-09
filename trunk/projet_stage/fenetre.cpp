#include "fenetre.h"
#include "iostream"



fenetre::fenetre()
{
    //widget central
    QWidget * w = new QWidget;
    setCentralWidget(w);

    /********************************************************************/
                                 //CARTE
    image = new carte();

    /********************************************************************/
                                 //MENUBAR

    menuFichier = menuBar()->addMenu("&Fichier");

    //ouvrir
    QAction *ouvrir = menuFichier->addAction("Ouvrir");
    ouvrir->setShortcut(QKeySequence("Ctrl+O"));

    //Enregistrer sous
    QAction *save_as = menuFichier->addAction("Sauvegarder le projet sous");


    //Enregistrer
    QAction *save = menuFichier->addAction("Sauvegarder le projet");
    save->setShortcut(QKeySequence("Ctrl+S"));


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
     zoom_in->setShortcut(QKeySequence("Ctrl+W"));
     zoom_in->setToolTip("La molette de la souris peut etre aussi utilisee");

     //zoom arriere
     QAction *zoom_out = menuAffichage->addAction("Zoom arriere");
     zoom_out->setShortcut(QKeySequence("Ctrl+alt+W"));
     zoom_out->setToolTip("La molette de la souris peut etre aussi utilisee");

    /********************************************************************/
                                 //TOOLBAR

     toolbar = addToolBar("Barre d'outils");

     //ouvrir //prenser a mettre les icones
     toolbar->addAction(ouvrir);
     toolbar->addSeparator();

     //enregistrer
     toolbar->addAction(save);
     toolbar->addSeparator();

     //Effacer
     QAction *effacer = toolbar->addAction("Fermer le projet");
     toolbar->addAction(effacer);

     //Zoom
     toolbar->addAction(zoom_in);
     toolbar->addSeparator();
     toolbar->addAction(zoom_out);


     //zone de sélection de couleur

     toolbar->addSeparator();
     label = new QLabel (toolbar);
     couleur = "background-color: rgb(255,255,255);";
     label->setStyleSheet(couleur);
     label->setFixedWidth(15);
     label->setFixedHeight(15);
     label->setToolTip("Couleur du chemin sélectionné");
     toolbar->addWidget(label);
     toolbar->addSeparator();
     // penser a faire le connecte et les fonctions de modifications ...

     //zone coordonnée
     //Lattitude
     QLabel *lat = new QLabel ("Latitude : ");
     toolbar->addWidget(lat);
     la = new QTextEdit(toolbar);
     toolbar->addWidget(la);
     la->setFixedHeight(20);
     la->setFixedWidth(150);
     la->setToolTip("Entrez la lattitude du point remarquable");


     //longitude
     toolbar->addSeparator();
     QLabel *lon = new QLabel ("Longitude : ");
     toolbar->addWidget(lon);
     lo = new QTextEdit(toolbar);
     toolbar->addWidget(lo);
     lo->setFixedHeight(20);
     lo->setFixedWidth(150);
     lo->setToolTip("Entrez la longitude du point remarquable");




                                //LAYOUTS
    mainLayout= new QHBoxLayout(w);
    mainLayout->addWidget(image);


    /********************************************************************/
                                 //CONNECT

     QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
     QObject::connect(ouvrir, SIGNAL(triggered()),this, SLOT(telechargerImage()));

     QObject::connect(effacer, SIGNAL(triggered()),image, SLOT(fermerProjet()));
     QObject::connect(zoom_in, SIGNAL(triggered()),image, SLOT(augmenter_zoom()));
     QObject::connect(zoom_out, SIGNAL(triggered()),image, SLOT(diminuer_zoom()));

     QObject::connect(image, SIGNAL(ChangeRes()),this, SLOT(setCouleur()));
}


    /********************************************************************/
                                 // FONCTIONS



    void fenetre::telechargerImage()
    {
        QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");

           //MessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);

           // QMessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);

           image->afficherImage(fichier);
    }

    void fenetre::setCouleur()
    {

        QString r,g,b;
        r= QString::number(qRed(image->getCouleur()));g=QString::number(qGreen(image->getCouleur())); b=QString::number(qBlue(image->getCouleur()));
        couleur="background-color: rgb("+r+","+g+","+b+");";
        label->setStyleSheet(couleur);
        update();

    }

