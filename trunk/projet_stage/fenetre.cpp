#include "fenetre.h"
#include "iostream"



fenetre::fenetre():flag_dock(false)
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

    //FICHIER

    menuFichier = menuBar()->addMenu("&Fichier");

    //ouvrir
    QAction *ouvrir = menuFichier->addAction("Ouvrir");
    ouvrir->setShortcut(QKeySequence("Ctrl+O"));
    ouvrir->setIcon(QIcon("ouvrir1.png"));
    //Enregistrer sous
    save_as = menuFichier->addAction("Sauvegarder le projet sous");
    save_as->setEnabled(false);

    //Enregistrer
    save = menuFichier->addAction("Sauvegarder le projet");
    save->setShortcut(QKeySequence("Ctrl+S"));
    save->setEnabled(false);
    save->setIcon(QIcon("svg.png"));
    //quitter
     QAction *quitter = menuFichier->addAction("&Quitter");
     quitter->setShortcut(QKeySequence("Ctrl+Q"));

     //EDITION

     menuEdition = menuBar()->addMenu("&Edition");

     //export
     exp = menuEdition->addAction("Export aux format GPX");
     exp->setShortcut(QKeySequence("Ctrl+E"));
     exp->setEnabled(false);


     //AFFICHAGE

     menuAffichage = menuBar()->addMenu("&Affichage");

     //zoom avant
     zoom_in = menuAffichage->addAction("Zoom avant");
     zoom_in->setShortcut(QKeySequence("Ctrl+W"));
     zoom_in->setToolTip(trUtf8("La molette de la souris peut etre aussi utilisee"));
     zoom_in->setEnabled(false);
     zoom_in->setIcon(QIcon("zoom+.png"));
     //zoom arriere
     zoom_out = menuAffichage->addAction("Zoom arriere");
     zoom_out->setShortcut(QKeySequence("Ctrl+alt+W"));
     zoom_out->setToolTip(trUtf8("La molette de la souris peut etre aussi utilisee"));
     zoom_out->setEnabled(false);
     zoom_out->setIcon(QIcon("zoom-.png"));
     //afficher le dock
     affich_dock = menuAffichage->addAction("Afficher le gestionnaire GPS");
     affich_dock->setShortcut(QKeySequence("Ctrl+D"));
     affich_dock->setEnabled(false);

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
     effacer = toolbar->addAction("Fermer le projet");
     toolbar->addAction(effacer);
     effacer->setEnabled(false);
     effacer->setIcon(QIcon("fermer2.png"));

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

     //gestionnaire des coordonnées
     gestionnaire = new QPushButton("Gestionnaire GPS");
     gestionnaire->setToolTip("Afficher ou non le gestionnaire GPS");
     gestionnaire->setIcon(QIcon("gps.png"));
     gestionnaire->setEnabled(false);
     toolbar->addWidget(gestionnaire);
     toolbar->addSeparator();

     // penser a faire le connecte et les fonctions de modifications ...



     /********************************************************************/
                                 //DOCK

    dock = new QDockWidget(trUtf8("Gestion des coordonnées :"), this);
    //dock->setStyleSheet("border : 1px; background-color : gray");
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QWidget * contenuDock = new QWidget;
    dock->setWidget(contenuDock);
    //dock->setStyleSheet("border-top :1px solid black");
    QVBoxLayout* VdockLayout1 = new QVBoxLayout();
    QVBoxLayout* VdockLayout2 = new QVBoxLayout();
    QVBoxLayout* VdockLayout3 = new QVBoxLayout();

    QHBoxLayout* HdockLayout1 = new QHBoxLayout();
    QHBoxLayout* HdockLayout2 = new QHBoxLayout();
    QHBoxLayout* HdockLayout3 = new QHBoxLayout();
    QHBoxLayout* HdockLayout4 = new QHBoxLayout();

    //zone coordonnées décimales
    QLabel *titre = new QLabel (trUtf8("En décimal :"));
    VdockLayout1->addWidget(titre);
    //Lattitude
    QLabel *lat = new QLabel ("Latitude : ");
    VdockLayout1->addWidget(lat);
    la = new QDoubleSpinBox (dock);
    VdockLayout1->addWidget(la);
    la->setFixedHeight(20);
    la->setFixedWidth(150);

    la1 = new QDoubleSpinBox (dock);
    VdockLayout1->addWidget(la1);
    la1->setFixedHeight(20);
    la1->setFixedWidth(150);

    //longitude
    QLabel *lon = new QLabel ("Longitude : ");
    VdockLayout1->addWidget(lon);
    lo = new QDoubleSpinBox (dock);
    VdockLayout1->addWidget(lo);
    lo->setFixedHeight(20);
    lo->setFixedWidth(150);


    lo1 = new QDoubleSpinBox (dock);
    VdockLayout1->addWidget(lo1);
    lo1->setFixedHeight(20);
    lo1->setFixedWidth(150);

    QPushButton *valider1 = new QPushButton("Valider");
    VdockLayout1->addWidget(valider1);



    //zone coordonnées sexgésimales
    QLabel *titre2 = new QLabel (trUtf8("En sexagésimal :"));
    VdockLayout2->addWidget(titre2);

    QLabel *DMS1 = new QLabel (trUtf8("Latitude en degrée minute seconde :"));
    VdockLayout2->addWidget(DMS1);

    d1 = new QSpinBox(dock);
    d1->setFixedHeight(20);
    d1->setFixedWidth(75);

    dd1 = new QSpinBox(dock);
    dd1->setFixedHeight(20);
    dd1->setFixedWidth(75);

    m1 = new QSpinBox(dock);
    m1->setFixedHeight(20);
    m1->setFixedWidth(60);

    mm1 = new QSpinBox(dock);
    mm1->setFixedHeight(20);
    mm1->setFixedWidth(60);

    s1 = new QSpinBox(dock);
    s1->setFixedHeight(20);
    s1->setFixedWidth(60);

    ss1 = new QSpinBox(dock);
    ss1->setFixedHeight(20);
    ss1->setFixedWidth(60);


    HdockLayout1->addWidget(d1);
    HdockLayout1->addWidget(m1);
    HdockLayout1->addWidget(s1);

    HdockLayout2->addWidget(dd1);
    HdockLayout2->addWidget(mm1);
    HdockLayout2->addWidget(ss1);

    VdockLayout2->addLayout(HdockLayout1);
    VdockLayout2->addLayout(HdockLayout2);

    QLabel *DMS2 = new QLabel (trUtf8("Longitude en degrée minute seconde :"));
    VdockLayout2->addWidget(DMS2);

    d2 = new QSpinBox(dock);
    d2->setFixedHeight(20);
    d2->setFixedWidth(75);

    dd2 = new QSpinBox(dock);
    dd2->setFixedHeight(20);
    dd2->setFixedWidth(75);

    m2 = new QSpinBox(dock);
    m2->setFixedHeight(20);
    m2->setFixedWidth(60);

    mm2 = new QSpinBox(dock);
    mm2->setFixedHeight(20);
    mm2->setFixedWidth(60);

    s2 = new QSpinBox(dock);
    s2->setFixedHeight(20);
    s2->setFixedWidth(60);

    ss2 = new QSpinBox(dock);
    ss2->setFixedHeight(20);
    ss2->setFixedWidth(60);


    HdockLayout3->addWidget(d2);
    HdockLayout3->addWidget(m2);
    HdockLayout3->addWidget(s2);

    HdockLayout4->addWidget(dd2);
    HdockLayout4->addWidget(mm2);
    HdockLayout4->addWidget(ss2);

    VdockLayout2->addLayout(HdockLayout3);
    VdockLayout2->addLayout(HdockLayout4);

    QPushButton *valider2 = new QPushButton("Valider");
    VdockLayout2->addWidget(valider2);

    VdockLayout3->addLayout(VdockLayout1);
    VdockLayout3->addLayout(VdockLayout2);

    QPushButton *reinit = new QPushButton(trUtf8("réinitialiser"));
    VdockLayout3->addWidget(reinit);
    contenuDock->setLayout(VdockLayout3);
    dock->setVisible(false);


     /********************************************************************/
                                //LAYOUTS
    mainLayout= new QHBoxLayout(w);
    mainLayout->addWidget(image);


    /********************************************************************/
                                 //CONNECT
     QAction * var = dock->toggleViewAction();//permet de récupérer la fermeture du dock

     QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
     QObject::connect(ouvrir, SIGNAL(triggered()),this, SLOT(telechargerImage()));
     QObject::connect(affich_dock, SIGNAL(triggered()),this, SLOT(afficher_dock()));
     QObject::connect(var, SIGNAL(triggered()),this, SLOT(afficher_dock()));

     QObject::connect(valider1, SIGNAL(clicked()),this, SLOT(valider_dec()));
     QObject::connect(valider2, SIGNAL(clicked()),this, SLOT(valider_sexa()));
     QObject::connect(gestionnaire, SIGNAL(clicked()),this, SLOT(afficher_dock()));

     QObject::connect(effacer, SIGNAL(triggered()),image, SLOT(fermerProjet()));
     QObject::connect(zoom_in, SIGNAL(triggered()),image, SLOT(augmenter_zoom()));
     QObject::connect(zoom_out, SIGNAL(triggered()),image, SLOT(diminuer_zoom()));

     QObject::connect(reinit, SIGNAL(clicked()),image, SLOT(setNbpoint()));

     QObject::connect(image, SIGNAL(ChangeRes()),this, SLOT(setCouleur()));
}




    /********************************************************************/
                                 // SLOTS



    void fenetre::telechargerImage()
    {
        QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");

           //MessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);

           // QMessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);
           save->setEnabled(true);
           save_as->setEnabled(true);
           effacer->setEnabled(true);
           zoom_in->setEnabled(true);
           zoom_out->setEnabled(true);
           affich_dock->setEnabled(true);
           exp->setEnabled(true);
           dock->setVisible(false);
           gestionnaire->setEnabled(true);
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
       // image->setCoordDec(lo,la,lo1,la1);
       float a = la->value();
       float b = la1->value();
       float c = lo->value();
       float d = lo1->value();

       image->setCoordDec(a,b,c,d);


    }

    void fenetre::valider_sexa()
    {
        int a = d1->value();
        int b = m1->value();
        int c = s1->value();
        int d = dd1->value();
        int e = mm1->value();
        int f = ss1->value();
        int g = d2->value();
        int h = m2->value();
        int i = s2->value();
        int j = dd2->value();
        int k = mm2->value();
        int l = ss2->value();

        image->setCoordSeg(a,b,c,d,e,f,g,h,i,j,k,l);

    }

    void fenetre::ignor()
    {
        affich_dock->setEnabled(true);
        dock->setVisible(false);
        image->setFlags(1);

    }

    void fenetre::afficher_dock()
    {
        if (flag_dock==false) {
                     dock->setVisible(true);
                     if (image->getFlags()==1)
                                image->setFlags(2);

                      flag_dock=true;

        } else if (flag_dock==true) {
                            dock->setVisible(false);
                            if (image->getFlags()==2)
                                       image->setFlags(1);

                            flag_dock=false;
                }
    }


