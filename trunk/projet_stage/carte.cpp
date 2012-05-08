#include "carte.h"
#include "iostream"

carte::carte():point(0,0),point_click(0,0),coul(255255255)
{
    global= new QVBoxLayout(this);

    this->setMinimumSize(1500,650);
    label= new QLabel();


    //m_image = QImage(QSize(100,100), QImage::Format_RGB32);


}

carte::~carte(){

}

void carte::afficherImage(QString chemin){


    if (!chemin.isNull()) {

    image= new QImage(chemin);

    label->setPixmap(QPixmap::fromImage(*image));
    echelle= 1.0;
    //SizePolicy ignored permet de mettre à n'importe quelle échelle l'image quand FIt to Window (pas encore implémenté) est mis  sur on
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //Scaled contents à true permet de zoomer le QLabel et l'image ensemble et pas uniquement le QLabel
    label->setScaledContents(true);
    label->adjustSize();   // label->adjustSize();
    scroll= new QScrollArea;
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(label);
    global->addWidget(scroll);




    zom= new QPushButton("zoom");
    QObject::connect(zom, SIGNAL(clicked()), this, SLOT(augmenter_zoom()));
    dezoom=new QPushButton("dezoom");
    QObject::connect(dezoom, SIGNAL(clicked()), this, SLOT(diminuer_zoom()));
    valeurZoom= new QLabel("valeur: ");
    valeurZoom->setText(QString::number(echelle) );
    global->addWidget(valeurZoom);
    global->addWidget(zom);
    global->addWidget(dezoom);



}
}

void carte::augmenter_zoom(){
 if (label->pixmap()!=0){
    zoom(1.25);
 }
}

void carte::diminuer_zoom(){
  if (label->pixmap()!=0){
    zoom(0.8);
  }
}

void carte::fermerProjet(){
   if (label->pixmap()!=0){
    label->clear();
   }
}
//zoom traitement au niveau du QLabel et non de l'image
void carte::zoom(float valeur){
    echelle = (valeur * echelle);
    valeurZoom->setText(QString::number(echelle) );
   // largeur= image->width();
   //longueur= image->height();
    label->resize(echelle*label->pixmap()->size());
   // image->scaledToWidth(echelle*largeur);
   // image->scaledToHeight(echelle*longueur);
   // largeur = image->width();
   // longueur = image->height();
    //label->adjustSize();
}

// gestion de points de cliques et de couleurs
QString carte::getCouleur_rgb()
{
    return couleur;
}


void carte::setCouleur_rgb(QString str)
{
   couleur = str;
}

QRgb carte::getCouleur()
{
    return coul;
}

void carte::setCouleur(QRgb c)
{
    coul = c;
}


//gestion des évènements

void carte::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"ouverture de l event click"<<std::endl;
    if (label->pixmap()!=0){
        QRgb pt ;
        if (event->button() == Qt::LeftButton)
            {
            pt = image->pixel(event->pos());
            setCouleur(pt);
             }
        std::cout<<"point : "<<event->x()<<" "<<event->y()<<std::endl;
    }
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{
    if (label->pixmap()!=0){
    QColor c = c.fromRgb(getCouleur());
    QString str,r,g,b;
    if (event->button() == Qt::LeftButton)
        {
           r= qRed(getCouleur());g=qGreen(getCouleur()); b=qBlue(getCouleur());
           str = "background-color: rgb("+r+","+g+","+b+");";
           emit setCouleur_rgb(str);
        }
    std::cout<<"couleur"<<str.toStdString()<<std::endl;
    std::cout<<"fermeture de l event click , "<<std::endl;

    }
}
