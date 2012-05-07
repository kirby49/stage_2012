#include "carte.h"
#include "iostream"

carte::carte():point(0,0),point_click(0,0)
{
    global= new QVBoxLayout(this);

    this->setMinimumSize(500,500);

    //m_image = QImage(QSize(100,100), QImage::Format_RGB32);


}

carte::~carte(){

}

void carte::afficherImage(QString chemin){

    if (!chemin.isNull()) {

    image= new QImage(chemin);
    label= new QLabel();
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

    zoom(1.25);
}

void carte::diminuer_zoom(){
    zoom(0.8);
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
QPoint carte::getPoint_click()
{
    return point_click;
}

QPoint carte::getPoint()
{
    return point;
}

void carte::setPoint_click(QPoint p)
{
    point_click = p;
}


void carte::setPoint(QPoint p)
{
    point = p;
}

QColor carte::getCouleur()
{
    return coul;
}

void carte::setCoul(QRgb c)
{
    coul = coul.fromRgb(c);// a retravailler
}




//gestion des évènements

void carte::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"ouverture de l event click"<<std::endl;
    if (event->button() == Qt::LeftButton)
        {
         setPoint_click(event->pos());
        }
    std::cout<<"point : "<<event->x()<<" "<<event->y()<<std::endl;
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{

    QPoint p=getPoint_click();
    QRgb pt ;
    if (event->button() == Qt::LeftButton)
        {
         pt = image->pixel(p);
        }
    setCoul(pt);
    //std::cout<<"couleur : "<<pt<<" "<<coul<<std::endl;
    //std::cout<<"fermeture de l event click"<<std::endl;
}
