#include "fenetre.h"
#include "iostream"



fenetre::fenetre()
{
    int largeur= QApplication::desktop()->width()-100;
    int hauteur = QApplication::desktop()->height()-100;
    this->setMinimumSize(largeur,hauteur);
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
     zoom_in->setToolTip(trUtf8("La molette de la souris peut etre aussi utilisee"));

     //zoom arriere
     QAction *zoom_out = menuAffichage->addAction("Zoom arriere");
     zoom_out->setShortcut(QKeySequence("Ctrl+alt+W"));
     zoom_out->setToolTip(trUtf8("La molette de la souris peut etre aussi utilisee"));

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
     label->setToolTip(trUtf8("Couleur du chemin sélectionné"));
     toolbar->addWidget(label);
     toolbar->addSeparator();
     // penser a faire le connecte et les fonctions de modifications ...



     /********************************************************************/
                                 //DOCK

    dock = new QDockWidget(trUtf8("Gestion des coordonnées"), this);


         addDockWidget(Qt::RightDockWidgetArea, dock);
         QWidget * contenuDock = new QWidget;
         dock->setWidget(contenuDock);

         QVBoxLayout* VdockLayout1 = new QVBoxLayout();

         QVBoxLayout* VdockLayout2 = new QVBoxLayout();
         QHBoxLayout* HdockLayout1 = new QHBoxLayout();
         QHBoxLayout* HdockLayout2 = new QHBoxLayout();
         QVBoxLayout* VdockLayout3 = new QVBoxLayout();

         //zone coordonnées décimales
         QLabel *titre = new QLabel (trUtf8("En décimal :"));
         VdockLayout1->addWidget(titre);
         //Lattitude
         QLabel *lat = new QLabel ("Latitude : ");
         VdockLayout1->addWidget(lat);
         la = new QTextEdit(dock);

         VdockLayout1->addWidget(la);
         la->setFixedHeight(20);
         la->setFixedWidth(150);

         //longitude
         QLabel *lon = new QLabel ("Longitude : ");
         VdockLayout1->addWidget(lon);
         lo = new QTextEdit(dock);
         VdockLayout1->addWidget(lo);
         lo->setFixedHeight(20);
         lo->setFixedWidth(150);

         QPushButton *valider1 = new QPushButton("Valider");
         VdockLayout1->addWidget(valider1);


         //zone coordonnées sexgésimales
         QLabel *titre2 = new QLabel (trUtf8("En sexagésimal :"));
         VdockLayout2->addWidget(titre2);

         QLabel *DMS1 = new QLabel (trUtf8("Latitude : Degrée Minute Seconde "));
         VdockLayout2->addWidget(DMS1);

         d1 = new QTextEdit(dock);
         d1->setFixedHeight(20);
         d1->setFixedWidth(50);

         m1 = new QTextEdit(dock);
         m1->setFixedHeight(20);
         m1->setFixedWidth(50);

         s1 = new QTextEdit(dock);
         s1->setFixedHeight(20);
         s1->setFixedWidth(50);

         HdockLayout1->addWidget(d1);
         HdockLayout1->addWidget(m1);
         HdockLayout1->addWidget(s1);
         VdockLayout2->addLayout(HdockLayout1);

         QLabel *DMS2 = new QLabel (trUtf8("Longitude : Degrée Minute Seconde "));
         VdockLayout2->addWidget(DMS2);

         d2 = new QTextEdit(dock);
         d2->setFixedHeight(20);
         d2->setFixedWidth(50);

         m2 = new QTextEdit(dock);
         m2->setFixedHeight(20);
         m2->setFixedWidth(50);

         s2 = new QTextEdit(dock);
         s2->setFixedHeight(20);
         s2->setFixedWidth(50);

         HdockLayout2->addWidget(d2);
         HdockLayout2->addWidget(m2);
         HdockLayout2->addWidget(s2);
         VdockLayout2->addLayout(HdockLayout2);
         QPushButton *valider2 = new QPushButton("Valider");
         VdockLayout2->addWidget(valider2);

         VdockLayout3->addLayout(VdockLayout1);
         VdockLayout3->addLayout(VdockLayout2);
         contenuDock->setLayout(VdockLayout3);
        dock->setVisible(false);


     /********************************************************************/
                                //LAYOUTS
    mainLayout= new QHBoxLayout(w);
    mainLayout->addWidget(image);


    /********************************************************************/
                                 //CONNECT

     QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
     QObject::connect(ouvrir, SIGNAL(triggered()),this, SLOT(telechargerImage()));
     QObject::connect(valider1, SIGNAL(clicked()),this, SLOT(valider_dec()));
     QObject::connect(valider2, SIGNAL(clicked()),this, SLOT(valider_sexa()));


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

           dock->setVisible(true);
           image->setFlags(1);
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

    void fenetre::valider_dec()
    {
        image->setFlags(2);
    }

    void fenetre::valider_sexa()
    {
         image->setFlags(2);
    }
