#include "carte.h"
#include "iostream"

carte::carte():point(0,0),point_click(0,0),coul(255255255)
{
    //global= new QVBoxLayout(this);

    this->setMinimumSize(1500,650);



    //m_image = QImage(QSize(100,100), QImage::Format_RGB32);


}

carte::~carte(){

}
void carte::paintEvent(QPaintEvent *event)
{
    //clearImage();
    QPainter painter(this);
    painter.drawImage(point,*image);
}

void carte::afficherImage(QString chemin){


    if (!chemin.isNull()) {
    echelle= 1.0;
    image= new QImage(chemin);

    //scroll= new QScrollArea;
    //scroll->setBackgroundRole(QPalette::Dark);
    //scroll->setWidget(image);
    //global->addWidget(scroll);
    painter= new QPainter(this);
    painter->drawImage(QPoint(0,0), *image);
    update();
    //painter.drawImage(QPoint(0, 0), image);


    /*label->setPixmap(QPixmap::fromImage(*image));

    //SizePolicy ignored permet de mettre à n'importe quelle échelle l'image quand FIt to Window (pas encore implémenté) est mis  sur on
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //Scaled contents à true permet de zoomer le QLabel et l'image ensemble et pas uniquement le QLabel
    label->setScaledContents(true);
    label->adjustSize();   // label->adjustSize();






    zom= new QPushButton("zoom");
    QObject::connect(zom, SIGNAL(clicked()), this, SLOT(augmenter_zoom()));
    dezoom=new QPushButton("dezoom");
    QObject::connect(dezoom, SIGNAL(clicked()), this, SLOT(diminuer_zoom()));
    valeurZoom= new QLabel("valeur: ");
    valeurZoom->setText(QString::number(echelle) );
    global->addWidget(valeurZoom);
    global->addWidget(zom);
    global->addWidget(dezoom);*/



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
    if (label->pixmap()!=0){
        QRgb pt ;
        if (event->button() == Qt::LeftButton)
            {
            pt = image->pixel(event->pos());
            setCouleur(pt);
            //update();
             }
       // std::cout<<"point : "<<event->x()<<" "<<event->y()<<std::endl;
    }
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{
    if (label->pixmap()!=0){
    QColor c = c.fromRgb(getCouleur());
    QString r,g,b;
    if (event->button() == Qt::LeftButton)
        {
           r= QString::number(qRed(getCouleur()));g=QString::number(qGreen(getCouleur())); b=QString::number(qBlue(getCouleur()));
           setCouleur_rgb("background-color: rgb("+r+","+g+","+b+");");
           emit ChangeRes();
        }
    // std::cout<<"couleur : "<<getCouleur_rgb().toStdString()<<std::endl;


    }
}
