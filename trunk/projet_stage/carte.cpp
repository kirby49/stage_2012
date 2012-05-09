#include "carte.h"
#include "iostream"

carte::carte():point_click(0,0),coul(255255255)
{

    largeur= QApplication::desktop()->width()-100;
    hauteur = QApplication::desktop()->height()-100;
    this->setMinimumSize(largeur,hauteur);
    image = new QImage();
    imageDessiner=false;


    QObject::connect(this, SIGNAL(ChangeZoomIn()),this, SLOT(augmenter_zoom()));
    QObject::connect(this, SIGNAL(ChangeZoom()),this, SLOT(diminuer_zoom()));
    QObject::connect(this, SIGNAL(signalDessinerChemin()),this, SLOT(dessinerChemin()));

}

carte::~carte(){

}
void carte::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPoint point (0,0);
    painter.drawImage(point,*image);

}

void carte::afficherImage(QString chemin){

    std::cout<<"afficher image"<<std::endl;
    if (!chemin.isNull()) {
    echelle= 1.0;
    image= new QImage(chemin);
    int width= image->width();
    int height=image->height();

    if (width>largeur){
    QImage newImage= (image->scaled(largeur,hauteur,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    image=new QImage(newImage);
    largeur=image->width();
    hauteur=image->height();
    }
    else if (height>hauteur){
    QImage newImage= (image->scaled(largeur,hauteur,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    image=new QImage(newImage);
    largeur=image->width();
    hauteur=image->height();
    };

    imageDessiner=true;

    update();
    }
}

bool carte::getImageDessiner(){
    return imageDessiner;
}

void carte::setImagedessiner(bool choix){
    imageDessiner= choix;
}

void carte::augmenter_zoom(){
    /*QRectF target(10.0, 20.0, 80.0, 60.0);
     QRectF source(0.0, 0.0, 70.0, 40.0);


     QPainter painter(this);
     painter.drawImage(target, image, source);*/
    std::cout<<"zoom in"<<std::endl;
    //zoom(1.25);

}

void carte::diminuer_zoom(){
    std::cout<<"zoom out"<<std::endl;
    //zoom(0.8);

}

void carte::fermerProjet(){
   image= new QImage();

}

void carte::zoom(float valeur){
    echelle = (valeur * echelle);
    valeurZoom->setText(QString::number(echelle) );

}

// gestion de points de cliques et de couleurs


QRgb carte::getCouleur()
{
    return coul;
}

void carte::setCouleur(QRgb c)
{
    coul = c;
}

QPoint carte::getPoint()
{
return point_click;
}


void carte::setPoint(QPoint p)
{

    point_click=p;
}

//gestion des évènements

void carte::mousePressEvent(QMouseEvent *event)
{
    if (imageDessiner){
        QRgb pt ;
        if (event->button() == Qt::LeftButton)
            {

            setPoint(event->pos());
            pt = image->pixel(event->pos());
            setCouleur(pt);
            //update();
             }
       // std::cout<<"point : "<<event->x()<<" "<<event->y()<<std::endl;
    }
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{
    if (imageDessiner){

    if (event->button() == Qt::LeftButton)
        {
           emit ChangeRes();
           emit signalDessinerChemin();
        }
    //std::cout<<"couleur : "<<getCouleur_rgb().toStdString()<<std::endl;


    }
}


void carte::wheelEvent(QWheelEvent *event)
{
    if (imageDessiner){
        if (event->delta()>0){
            emit ChangeZoomIn();
            update();
        }
        else   {
            emit ChangeZoom();
            update();
        }
    }
}
int carte::maximum(int a, int b){
    if(a>b) return a;
        else return b;
}

bool carte::comparerCouleurAvecMarge(QRgb p1, QRgb p2){

    unsigned int differenceRouge = abs(qRed(p1) - qRed(p2));
    unsigned int differenceVert  = abs(qGreen(p1)- qGreen(p2));
    unsigned int differenceBleu  = abs(qBlue(p1)-qBlue(p2));
    int couleurDominante= maximum(differenceBleu,maximum(differenceRouge, differenceVert));
    if(couleurDominante>50) return false;
              unsigned int somme= differenceRouge + differenceVert + differenceBleu;
              if (somme<10) return true;
}

void carte::dessinerChemin(){

    for (int i=0;i<largeur;i++){
        for (int j=0; j<hauteur;j++){
            if (comparerCouleurAvecMarge( image->pixel(i,j),coul)==true)


               {image->setPixel(QPoint(i,j),255255255);}
          // std::cout<<"couleur : "<<coul<<std::endl;}
            //image->setPixel(QPoint(i,j),coul);


        }
    }
update();
}


