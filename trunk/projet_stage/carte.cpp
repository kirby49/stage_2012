#include "carte.h"
#include "iostream"
#include "math.h"


//constructeur
carte::carte():point_click(0,0),point1(0,0),point2(0,0),coul(255255255),nbpoint(0),flags(0)
{

    largeur= QApplication::desktop()->width()-100;
    hauteur = QApplication::desktop()->height()-100;
    this->setMinimumSize(largeur,hauteur);
    imageCarte = new QImage();
    carteDessiner=false;
    tracerChemin= new QImage();

    QObject::connect(this, SIGNAL(ChangeZoomIn()),this, SLOT(augmenter_zoom()));
    QObject::connect(this, SIGNAL(ChangeZoom()),this, SLOT(diminuer_zoom()));

    QObject::connect(this, SIGNAL(signalDessinerChemin(QPoint)),this, SLOT(dessinerChemin(QPoint)));
    QObject::connect(this, SIGNAL(changeRes2(QPoint)),this, SLOT(attributCouleur(QPoint)));
    QObject::connect(this,SIGNAL(SignalFlag(QPoint)),this,SLOT(placerFlag1(QPoint)));
    QObject::connect(this,SIGNAL(SignalFlag(QPoint)),this,SLOT(placerFlag2(QPoint)));
}

//destructeur
carte::~carte(){}

//accesseur
bool carte::getCarteDessiner(){return carteDessiner;}

QPoint carte::getPoint() {return point_click;}

int carte::getFlags() {return flags;}

QRgb carte::getCouleur() {return coul;}

QPoint carte::getPoint1() {return point1;}

QPoint carte::getPoint2() {return point2;}

coord_decimal carte::getCoordDec() {return dec;}

coord_decimal carte::getCoordDec1() {return dec1;}

coord_sexagesimal carte::getCoordSeg() {return sexa;}

coord_sexagesimal carte::getCoordSeg1() {return sexa1;}

//mutateur
void carte::setCartedessiner(bool choix) {carteDessiner= choix;}

void carte::setFlags(int f) {flags=f;}

void carte::setCouleur(QRgb c) {coul = c;}

void carte::setPoint(QPoint p) {point_click=p;}

void carte::setPoint1(QPoint p) {point1=p;}

void carte::setPoint2(QPoint p) {point2=p;}

void carte::setCoordDec(float la,float lo,float la1,float lo1)
{
    if ((la!=0)||(lo!=0)||(la1!=0)||(lo1!=0)) {
            dec.setLatitude(la);
            dec.setLongitude(lo);

            dec1.setLatitude(la1);
            dec1.setLongitude(lo1);
            std::cout<<"dec : "<<dec.getLatitude()<<std::endl;
    } else QMessageBox::critical(this, "Attention", trUtf8("Vous devez entrer des coordonnées"));


}

void carte::setCoordSeg(int d1, int m1,int s1,int dd1, int mm1,int ss1,int d2, int m2, int s2,int dd2, int mm2, int ss2)
{
    if ((d1!=0)&&(m1!=0)&&(s1!=0)&&(dd1!=0)&&(mm1!=0)&&(ss1!=0)&&(d2!=0)&&(m2!=0)&&(s2!=0)&&(dd2!=0)&&(mm2!=0)&&(ss2!=0)) {
            sexa.setDegree(d1);
            sexa.setDegree1(dd1);
            sexa.setMinute(m1);
            sexa.setMinute1(mm1);
            sexa.setSeconde(s1);
            sexa.setSeconde1(ss1);

            sexa1.setDegree(d2);
            sexa1.setDegree1(dd2);
            sexa1.setMinute(m2);
            sexa1.setMinute1(mm2);
            sexa1.setSeconde(s2);
            sexa1.setSeconde1(ss2);
    } else QMessageBox::critical(this, "Attention", trUtf8("Vous devez entrer des coordonnées"));
}

//fonctions
void carte::afficherCarte(QString chemin){

    if (!chemin.isNull()) {
    echelle= 1.0;
    imageCarte= new QImage(chemin);
    int width= imageCarte->width();
    int height=imageCarte->height();

    if (width>largeur){
    QImage newImage= (imageCarte->scaled(largeur,hauteur,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    imageCarte=new QImage(newImage);
    largeur=imageCarte->width();
    hauteur=imageCarte->height();
    }
    else if (height>hauteur){
    QImage newImage= (imageCarte->scaled(largeur,hauteur,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    imageCarte=new QImage(newImage);
    largeur=imageCarte->width();
    hauteur=imageCarte->height();
    }

    carteDessiner=true;
    tracerChemin=new QImage(largeur,hauteur,QImage::Format_ARGB32);
    p1=new QImage("gps2.png");
    p2=new QImage("gps2.png");
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
    direction= QPoint(point_click.x()+directionX,point_click.y()+directionY);
    std::cout<<"pas a: "<<directionX<<" pas b: "<<directionY<<std::endl;
    std::cout<<"point de base: "<<point_click.x()<<" "<<point_click.y()<<std::endl;
    std::cout<<"direction "<<direction.x()<<" "<<direction.y()<<std::endl;
    if((directionX>=0)&&(directionY>=0))
    {
        for (int i=point_click.x();i<=direction.x();i++){
           for (int j=point_click.y();j<=direction.y();j++){
                if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true) tracerChemin->setPixel(QPoint(i,j),0xFF00FF00);
           }
        }
    }
    else
        if((directionX>=0)&&(directionY<0))
        {
            for (int i=point_click.x();i<=direction.x();i++){
               for (int j=point_click.y();j>=direction.y();j--){
                    if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true) tracerChemin->setPixel(QPoint(i,j),0xFF00FF00);
               }
            }
        }
        else
            if((directionX<0)&&(directionY>=0))
            {
                for (int i=point_click.x();i>=direction.x();i--){
                   for (int j=point_click.y();j<=direction.y();j++){
                        if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true) tracerChemin->setPixel(QPoint(i,j),0xFF00FF00);
                   }
                }
            }
            else
                {
                    for (int i=point_click.x();i>=direction.x();i--){
                       for (int j=point_click.y();j>=direction.y();j--){
                           if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true) tracerChemin->setPixel(QPoint(i,j),0xFF00FF00);
                       }
                    }
                }


   /*for (int i=0;i<largeur;i++){
     for (int j=0; j<hauteur;j++){
         if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true)
            {imageCarte->setPixel(QPoint(i,j),255255255);}
       // std::cout<<"couleur : "<<coul<<std::endl;}
         //imageCarte->setPixel(QPoint(i,j),coul);
     }
 }
*/

update();
}

double carte::longueur(QPoint pt, QPoint pt1)
{

int res1 = ((pt1.x()-pt.x())*(pt1.x()-pt.x()));
int res2 = ((pt1.y()-pt.y())*(pt1.y()-pt.y()));
int res3 = res1 + res2;

double resultat = qSqrt(res3);
return resultat;
}

double carte::angleA(QPoint pt, QPoint pt1, QPoint pt3)
{
    int ab,bc,ac;
    ab=longueur(pt,pt1);
    bc=longueur(pt1,pt3);
    ac=longueur(pt,pt3);

    double res = acos( ((ab*ab)+(ac*ac)-(bc*bc))/(2*(bc)*(ac)));
    return res;

}

double carte::angleB(QPoint pt, QPoint pt1, QPoint pt3)
{
    int ab,bc,ac;
    ab=longueur(pt,pt1);
    bc=longueur(pt1,pt3);
    ac=longueur(pt,pt3);
    double res = acos( ((ab*ab)+(bc*bc)-(ac*ac))/(2*(ab)*(bc)));
    return res;
}

double carte::angleC(QPoint pt, QPoint pt1, QPoint pt3)
{
    int ab,bc,ac;
    ab=longueur(pt,pt1);
    bc=longueur(pt1,pt3);
    ac=longueur(pt,pt3);

    bool res = acos( ((ab*ac)+(ac*ac)-(bc*bc))/(2*(bc)*(ac)));
    return res;
}


//slots
void carte::augmenter_zoom(){
    /*QRectF target(10.0, 20.0, 80.0, 60.0);
     QRectF source(0.0, 0.0, 70.0, 40.0);


     QPainter painter(this);
     painter.drawImage(target, imageCarte, source);*/
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
    pt = imageCarte->pixel(p);
    setCouleur(pt);
}

void carte::fermerProjet(){
  QImage newImage(0,0,QImage::Format_ARGB32);
  //hauteur=0;
  //largeur=0;
  imageCarte= new QImage(newImage);
  tracerChemin= new QImage(newImage);
  p1= new QImage();
  p2= new QImage();
  setFlags(0);
  update();
;
}

void carte::placerFlag1(const QPoint &p)
{
    if (nbpoint==0){
        int x = (p.x()-4);
        int y = (p.y()-(p1->height()));
        QPoint pt(x,y);
        std::cout<<"image 1 : "<<x<<" "<<y<<std::endl;
        nbpoint++;
        setPoint1(pt);

        update();
    }

}

void carte::placerFlag2(const QPoint &p)
{
    if (nbpoint==1){
        int x = (p.x()-4);
        int y = (p.y()-(p2->height()));
        std::cout<<"image 2 : "<<x<<" "<<y<<std::endl;
        QPoint pt(x,y);
        nbpoint++;
        setPoint2(pt);

        update();

    }

}

void carte::setNbpoint()
{
    nbpoint=0;
    update();
}


//gestion des évènements
void carte::paintEvent(QPaintEvent *event)
{
    if ((carteDessiner)&&(flags==1)){
        QPainter painter(this);
        QPoint point (0,0);
        painter.drawImage(point,*imageCarte);
        painter.drawImage(point,*tracerChemin);
    }
    else if ((carteDessiner)&&(flags==2)){
            QPainter painter(this);
            QPoint point (0,0);
            painter.drawImage(point,*imageCarte);
            if (nbpoint==1) {
                 QPainter painter(this);
                 QPoint point (0,0);
                 painter.drawImage(point,*imageCarte);
                 painter.drawImage(getPoint1(),*p1);
                  } else if (nbpoint==2) {
                            QPainter painter(this);
                            QPoint point (0,0);
                            painter.drawImage(point,*imageCarte);
                            painter.drawImage(getPoint1(),*p1);
                            painter.drawImage(getPoint2(),*p2);
                          }
            }
}

void carte::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"click : "<<event->x()<<" "<<event->y()<<std::endl;
    if ((carteDessiner)&&(flags==1)){
           if (event->button() == Qt::LeftButton)
            {
               emit changeRes2(event->pos());
             }
    } else if ((carteDessiner)&&(flags==2)){
        if (nbpoint==0){
                 emit placerFlag1(event->pos());

                 }
        else if (nbpoint==1) {
                 emit placerFlag2(event->pos());

                 }

    }
}



void carte::mouseReleaseEvent(QMouseEvent *event)
{
    if ((carteDessiner)&&(flags==1)){

    if (event->button() == Qt::LeftButton)
        {
           emit ChangeRes();
           emit signalDessinerChemin(event->pos());
        }

    }
}


void carte::wheelEvent(QWheelEvent *event)
{
    if ((carteDessiner)&&(flags>0)){
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

int carte::minimum(int a, int b){
    if(a<b) return a;
        else return b;
}



bool carte::comparerCouleurAvecMarge(QRgb p1, QRgb p2){

    unsigned int differenceRouge = abs(qRed(p1) - qRed(p2));
    unsigned int differenceVert  = abs(qGreen(p1)- qGreen(p2));
    unsigned int differenceBleu  = abs(qBlue(p1)-qBlue(p2));
    /*int couleurMaxP1= maximum(qRed(p1),maximum(qGreen(p1), qBlue(p1)));
    int couleurMaxP2= maximum(qRed(p2),maximum(qGreen(p2), qBlue(p2)));
    int couleurMin= minimum(qRed(p1),minimum(qGreen(p1), qBlue(p1)));*/
    if ((differenceRouge + differenceVert + differenceBleu)>99) return false;
        else return true;

    /*int couleurDominante= maximum(differenceBleu,maximum(differenceRouge, differenceVert));
    if(couleurDominante>40) return false;   //40
                 else if ((differenceRouge + differenceVert + differenceBleu)>100) return false;  //100
    else return true;*/
              //if (somme<10) return true;
}




/*************************Brouillon  algo******************************************
    if (abs(directionX)>abs(directionY)){
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
//std::cout<<"point 1 "<<point_click.x()<<" "<<point_click.y()<<std::endl;
//std::cout<<"point 2 "<<direction.x()<<" "<<direction.y()<<std::endl;



   while(comparerCouleurAvecMarge( imageCarte->pixel(point_click),imageCarte->pixel(direction)==true)){
       imageCarte->setPixel(direction,255255255);
       std::cout<<"yes"<<std::endl;
      // QPoint direction1,direction2,direction3,direction4;
      QPoint direction1=QPoint(direction.x()+1,direction.y());
      QPoint direction2=QPoint(direction.x()-1,direction.y());
      QPoint direction3=QPoint(direction.x(),direction.y()+1);
      QPoint direction4=QPoint(direction.x(),direction.y()-1);
       if ((comparerCouleurAvecMarge( imageCarte->pixel(direction),imageCarte->pixel(direction1)==true))){
           point_click=direction;
           direction=direction1;
       }
       else
                   if ((comparerCouleurAvecMarge( imageCarte->pixel(direction),imageCarte->pixel(direction2)==true))){
                       point_click=direction;
                       direction=direction2;
       }
       else
                   if ((comparerCouleurAvecMarge( imageCarte->pixel(direction),imageCarte->pixel(direction3)==true))){
                       point_click=direction;
                       direction=direction3;
                   }
       else
                   if ((comparerCouleurAvecMarge( imageCarte->pixel(direction),imageCarte->pixel(direction4)==true))){
                       point_click=direction;
                       direction=direction4;
                   }

    }



      for (int i=0;i<largeur;i++){
        for (int j=0; j<hauteur;j++){
            if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true)


               {imageCarte->setPixel(QPoint(i,j),255255255);}
          // std::cout<<"couleur : "<<coul<<std::endl;}
            //imageCarte->setPixel(QPoint(i,j),coul);


        }
    }


***************************************************************************************/

