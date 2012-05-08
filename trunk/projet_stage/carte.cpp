#include "carte.h"
#include "iostream"

carte::carte():point(0,0),point_click(0,0),coul(255255255)
{

    this->setMinimumSize(1500,700);
    image = new QImage();
    imageDessiner=false;

    longueur= 0;
    largeur=0;



    QObject::connect(this, SIGNAL(ChangeZoomIn()),this, SLOT(augmenter_zoom()));
    QObject::connect(this, SIGNAL(ChangeZoom()),this, SLOT(diminuer_zoom()));

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

    std::cout<<"afficher image"<<std::endl;
    if (!chemin.isNull()) {
    echelle= 1.0;
    image= new QImage(chemin);
    int width= image->width();
    int height=image->height();

    if (width>longueur){
    QImage newImage= (image->scaledToWidth(1200,Qt::SmoothTransformation));
    image=new QImage(newImage);
    }
    else if (height>largeur){
    QImage newImage= (image->scaledToHeight(600,Qt::SmoothTransformation));
    image=new QImage(newImage);
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
//zoom traitement au niveau du QLabel et non de l'image
void carte::zoom(float valeur){
    echelle = (valeur * echelle);
    valeurZoom->setText(QString::number(echelle) );

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
    if (imageDessiner){
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
    if (imageDessiner){
    QColor c = c.fromRgb(getCouleur());
    QString r,g,b;
    if (event->button() == Qt::LeftButton)
        {
           r= QString::number(qRed(getCouleur()));g=QString::number(qGreen(getCouleur())); b=QString::number(qBlue(getCouleur()));
           setCouleur_rgb("background-color: rgb("+r+","+g+","+b+");");
           emit ChangeRes();
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
