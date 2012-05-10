#include "carte.h"
#include "iostream"


//constructeur
carte::carte():point_click(0,0),coul(255255255),flags(0)
{

    largeur= QApplication::desktop()->width()-100;
    hauteur = QApplication::desktop()->height()-100;
    this->setMinimumSize(largeur,hauteur);
    image = new QImage();
    imageDessiner=false;


    QObject::connect(this, SIGNAL(ChangeZoomIn()),this, SLOT(augmenter_zoom()));
    QObject::connect(this, SIGNAL(ChangeZoom()),this, SLOT(diminuer_zoom()));
    QObject::connect(this, SIGNAL(signalDessinerChemin(QPoint)),this, SLOT(dessinerChemin(QPoint)));
    QObject::connect(this, SIGNAL(changeRes2(QPoint)),this, SLOT(attributCouleur(QPoint)));
}

//destructeur
carte::~carte(){}

//accesseur
bool carte::getImageDessiner(){return imageDessiner;}

QPoint carte::getPoint() {return point_click;}

int carte::getFlags() {return flags;}

QRgb carte::getCouleur() {return coul;}

//mutateur
void carte::setImagedessiner(bool choix) {imageDessiner= choix;}

void carte::setFlags(int f) {flags=f;}

void carte::setCouleur(QRgb c) {coul = c;}

void carte::setPoint(QPoint p) {point_click=p;}

//fonctions
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

void carte::zoom(float valeur){
    echelle = (valeur * echelle);
    valeurZoom->setText(QString::number(echelle) );

}

void carte::dessinerChemin(const QPoint &p){
    point_release=p;
    QPoint direction;
    int directionX=point_release.x()-point_click.x();
    int directionY=point_release.y()-point_click.y();
    if (directionX>directionY){
            if (directionX>0)
                direction=QPoint (point_click.x()+1,point_click.y());
                else
                direction=QPoint (point_click.x()-1,point_click.y());
    }
    else {
        if (directionY>0)
            direction=QPoint (point_click.x(),point_click.y()+1);
            else
            direction=QPoint (point_click.x(),point_click.y()-1);
    }




   while(comparerCouleurAvecMarge( image->pixel(point_click),image->pixel(direction)==true)){
       image->setPixel(direction,255255255);
       std::cout<<"couleur changee "<<std::endl;
      // QPoint direction1,direction2,direction3,direction4;
      QPoint direction1=QPoint(direction.x()+1,direction.y());
      QPoint direction2=QPoint(direction.x()-1,direction.y());
      QPoint direction3=QPoint(direction.x(),direction.y()+1);
      QPoint direction4=QPoint(direction.x(),direction.y()-1);
       if ((comparerCouleurAvecMarge( image->pixel(direction),image->pixel(direction1)==true))){
           point_click=direction;
           direction=direction1;
       }
       else
                   if ((comparerCouleurAvecMarge( image->pixel(direction),image->pixel(direction2)==true))){
                       point_click=direction;
                       direction=direction2;
       }
       else
                   if ((comparerCouleurAvecMarge( image->pixel(direction),image->pixel(direction3)==true))){
                       point_click=direction;
                       direction=direction3;
                   }
       else
                   if ((comparerCouleurAvecMarge( image->pixel(direction),image->pixel(direction4)==true))){
                       point_click=direction;
                       direction=direction4;
                   }

    }



    /*for (int i=0;i<largeur;i++){
        for (int j=0; j<hauteur;j++){
            if (comparerCouleurAvecMarge( image->pixel(i,j),coul)==true)


               {image->setPixel(QPoint(i,j),255255255);}
          // std::cout<<"couleur : "<<coul<<std::endl;}
            //image->setPixel(QPoint(i,j),coul);


        }
    }*/
update();
}


//slots
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

void carte::attributCouleur(const QPoint &p){
     QRgb pt ;
    setPoint(p);
    pt = image->pixel(p);
    setCouleur(pt);
}

void carte::fermerProjet(){
   image= new QImage();

}




//gestion des évènements
void carte::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPoint point (0,0);
    painter.drawImage(point,*image);

}

void carte::mousePressEvent(QMouseEvent *event)
{

    if ((imageDessiner)&&(flags==1)){
           if (event->button() == Qt::LeftButton)
            {
               emit changeRes2(event->pos());
             }
       // std::cout<<"point : "<<event->x()<<" "<<event->y()<<std::endl;
    }
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{
    if ((imageDessiner)&&(flags==1)){

    if (event->button() == Qt::LeftButton)
        {
           emit ChangeRes();
           emit signalDessinerChemin(event->pos());
        }
    //std::cout<<"couleur : "<<getCouleur_rgb().toStdString()<<std::endl;


    }
}


void carte::wheelEvent(QWheelEvent *event)
{
    if ((imageDessiner)&&(flags>0)){
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

/******************* fonction pour l'algo de couleur*********************/


int carte::maximum(int a, int b){
    if(a>b) return a;
        else return b;
}

bool carte::comparerCouleurAvecMarge(QRgb p1, QRgb p2){

    unsigned int differenceRouge = abs(qRed(p1) - qRed(p2));
    unsigned int differenceVert  = abs(qGreen(p1)- qGreen(p2));
    unsigned int differenceBleu  = abs(qBlue(p1)-qBlue(p2));
    int couleurDominante= maximum(differenceBleu,maximum(differenceRouge, differenceVert));
    if(couleurDominante>40) return false;
                 else if ((differenceRouge + differenceVert + differenceBleu)>100) return false;
    else return true;
              //if (somme<10) return true;
}



