#include "carte.h"
#include "iostream"
#include "math.h"


//constructeur
carte::carte():point_click(0,0),point_depart(0,0),coul(255255255),nbpoint(0),flags(0)
{

    //largeur= QApplication::desktop()->width()-100;
    //hauteur = QApplication::desktop()->height()-100;
    this->setMinimumSize(largeur,hauteur);
    imageCarte = new QImage();
    imageAffichage= new QImage();
    tracerChemin= new QImage();
    copieTailleNormale= new QImage();
    etendueZone=5;
    carteDessiner=false;

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

QPoint carte::getPoint1() {return point1_gps;}

QPoint carte::getPoint2() {return point2_gps;}

coord_decimal carte::getCoordDec() {return dec;}

coord_decimal carte::getCoordDec1() {return dec1;}

coord_sexagesimal carte::getCoordSeg() {return sexa;}

coord_sexagesimal carte::getCoordSeg1() {return sexa1;}

//mutateur
void carte::setCartedessiner(bool choix) {carteDessiner= choix;}

void carte::setFlags(int f) {flags=f;}

void carte::setCouleur(QRgb c) {coul = c;}

void carte::setPoint(QPoint p) {point_click=p;}

void carte::setPoint1(QPoint p) {point1_gps=p;}

void carte::setPoint2(QPoint p) {point2_gps=p;}

void carte::setCoordDec(float la,float lo,float la1,float lo1)
{
    if ((la!=0)||(lo!=0)||(la1!=0)||(lo1!=0)) {
            dec.setLatitude(la);
            dec.setLongitude(lo);

            dec1.setLatitude(la1);
            dec1.setLongitude(lo1);

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
    std::cout<<"image: "<<chemin.toStdString()<<std::endl;
    int width= imageCarte->width();
    int height=imageCarte->height();

    if (width>height){
    QImage newImage= (imageCarte->scaledToWidth(1201,Qt::SmoothTransformation));
    imageCarte=new QImage(newImage);
    imageAffichage= new QImage(newImage);
    copieTailleNormale= new QImage(newImage);
    //std::cout<<"you piss off"<<std::endl;
    }
    else {
    QImage newImage= (imageCarte->scaledToHeight(651,Qt::SmoothTransformation));
    imageCarte=new QImage(newImage);
    imageAffichage= new QImage(newImage);
    copieTailleNormale= new QImage(newImage);
     //std::cout<<"you piss off"<<std::endl;
    }
     //std::cout<<"ça passe"<<std::endl;
    largeur=imageCarte->width();
    hauteur=imageCarte->height();
    carteDessiner=true;
    tracerChemin=new QImage(largeur,hauteur,QImage::Format_ARGB32);


    p1=new QImage("gps2.png");
    p2=new QImage("gps2.png");
    //std::cout<<"hauteur : "<<hauteur<<std::endl;
    //std::cout<<"largeur : "<<largeur<<std::endl;
    update();
    }
}

void carte::zoom(float valeur){
    echelle = (valeur * echelle);
    valeurZoom->setText(QString::number(echelle) );


}

void carte::dessinerChemin(const QPoint &p){

    //parcours entier de la carte
    //parcoursImageAffichage();

    // capture point de release souris
    point_release=p;

     // tracer départ du chemin
    tracerZone(point_click,coul);
    //int i=tracerZone(point_click,coul);
    //std::cout<<"zone : "<<i<<std::endl;

    // calcul orientation (release devient l'orientation)
    if (abs(point_release.x())>abs(point_release.y())){
            if (point_release.x()>0)
                point_release=QPoint (point_click.x()+etendueZone,point_click.y());
                else
                point_release=QPoint (point_click.x()-etendueZone,point_click.y());
    }
    else {
        if (point_release.y()>0)
            point_release=QPoint (point_click.x(),point_click.y()+etendueZone);
            else
            point_release=QPoint (point_click.x(),point_click.y()-etendueZone);
    }

   // std::cout<<"point de base: "<<point_click.x()<<" "<<point_click.y()<<std::endl;
   // std::cout<<"point release "<<point_release.x()<<" "<<point_release.y()<<std::endl;
   QPoint resultat=directionChemin();

   // trace suite chemin jusqu'à sortie de chemin
   while(resultat!=QPoint(0,0)&&
         (resultat.x()<=largeur)&&
         (resultat.x()>=0)&&
         (resultat.y()>=0)&&
         (resultat.y()<=hauteur))
   {
      std::cout<<"resultat: "<<resultat.x()<<" "<<resultat.y()<<std::endl;

      point_release.setX(resultat.x()+(resultat.x()-point_click.x()));
      point_release.setY(resultat.y()+(resultat.y()-point_click.y()));

      point_click.setX(resultat.x());
      point_click.setY(resultat.y());
      resultat=directionChemin();
  //      std::cout<<"new point  de base: "<<point_click.x()<<" "<<point_click.y()<<std::endl;
  //      std::cout<<"new release x: "<<point_release.x()<<" new release y: "<<point_release.y()<<std::endl;
    }
update();
}



QPoint carte::directionChemin(){
    int margeErreur=2;
    int choix=0;
    //0: arret   1: gauche   2:haut    3:droite   4: bas
    QPoint ancienneOrientation (point_release.x()-point_click.x(),point_release.y()-point_click.y());
    if (ancienneOrientation==QPoint(-etendueZone,0)) choix=1;
    else if (ancienneOrientation==QPoint(0,-etendueZone)) choix=2;
        else if (ancienneOrientation==QPoint(etendueZone,0)) choix=3;
            else if (ancienneOrientation==QPoint(0,etendueZone)) choix=4;
        std::cout<<"ancienne DIrection: "<<ancienneOrientation.x()<<"  "<<ancienneOrientation.y()<<std::endl;

    switch (choix){
    //gauche
            case (1):
    {
                 int gauche=(tracerZone(QPoint(point_click.x()-etendueZone,point_click.y()),coul));
                //int droite=(tracerZone(QPoint(point_click.x()+etendueZone,point_click.y()),coul));
                int haut=(tracerZone(QPoint(point_click.x(),point_click.y()-etendueZone),coul));
                int bas=(tracerZone(QPoint(point_click.x(),point_click.y()+etendueZone),coul));
                int nouvelleOrientation=maximum(gauche,maximum(haut,bas));

                std::cout<<"nouvelle DIrection: "<<nouvelleOrientation<<std::endl;
                if (nouvelleOrientation>margeErreur){
                     //std::cout<<"nouvelle DIrection2: "<<nouvelleOrientation <<std::endl;
                   // return QPoint(point_click.x()-etendueZone,point_click.y());

                    if (nouvelleOrientation == gauche) return QPoint(point_click.x()-etendueZone,point_click.y());
                    else if (nouvelleOrientation == haut) return QPoint(point_click.x(),point_click.y()-etendueZone);
                              else if (nouvelleOrientation == bas) return QPoint(point_click.x(),point_click.y()+etendueZone);

                }
                return QPoint(0,0);
    }
                break;

    //haut
            case (2):
    {
                int gauche=(tracerZone(QPoint(point_click.x()-etendueZone,point_click.y()),coul));
                int droite=(tracerZone(QPoint(point_click.x()+etendueZone,point_click.y()),coul));
                int haut=(tracerZone(QPoint(point_click.x(),point_click.y()-etendueZone),coul));
                //int bas=(tracerZone(QPoint(point_click.x(),point_click.y()+etendueZone),coul));
                int nouvelleOrientation=maximum(haut,maximum(gauche,droite));

                std::cout<<"nouvelle DIrection 3: "<<nouvelleOrientation <<std::endl;
                if (nouvelleOrientation>margeErreur){
                    if (nouvelleOrientation == gauche) return QPoint(point_click.x()-etendueZone,point_click.y());
                    else if (nouvelleOrientation == haut) return QPoint(point_click.x(),point_click.y()-etendueZone);
                         else if (nouvelleOrientation == droite) return QPoint(point_click.x()+etendueZone,point_click.y());
                   // std::cout<<"nouvelle DIrection 4: "<<nouvelleOrientation <<std::endl;
                    //return QPoint(point_click.x(),point_click.y()-etendueZone);

                }
                return QPoint(0,0);
      }
                break;

    //droite
            case (3):
    {
                //int gauche=(tracerZone(QPoint(point_click.x()-etendueZone,point_click.y()),coul));
                int droite=(tracerZone(QPoint(point_click.x()+etendueZone,point_click.y()),coul));
                int haut=(tracerZone(QPoint(point_click.x(),point_click.y()-etendueZone),coul));
                int bas=(tracerZone(QPoint(point_click.x(),point_click.y()+etendueZone),coul));
                int nouvelleOrientation=maximum(droite,maximum(haut,bas));
               std::cout<<"nouvelle DIrection 5: "<<nouvelleOrientation <<std::endl;
                if (nouvelleOrientation>margeErreur){
                     if (nouvelleOrientation == haut) return QPoint(point_click.x(),point_click.y()-etendueZone);
                         else if (nouvelleOrientation == droite) return QPoint(point_click.x()+etendueZone,point_click.y());
                              else if (nouvelleOrientation == bas) return QPoint(point_click.x(),point_click.y()+etendueZone);
                    //std::cout<<"nouvelle DIrection 6: "<<nouvelleOrientation <<std::endl;
                   // return QPoint(point_click.x()+etendueZone,point_click.y());

                }
                return QPoint(0,0);
      }
                break;

    //bas
            case (4):
    {
                int gauche=(tracerZone(QPoint(point_click.x()-etendueZone,point_click.y()),coul));
                int droite=(tracerZone(QPoint(point_click.x()+etendueZone,point_click.y()),coul));
                //int haut=(tracerZone(QPoint(point_click.x(),point_click.y()-etendueZone),coul));
                int bas=(tracerZone(QPoint(point_click.x(),point_click.y()+etendueZone),coul));
                int nouvelleOrientation=maximum(bas,maximum(gauche,droite));

std::cout<<"nouvelle DIrection 7: "<<nouvelleOrientation <<std::endl;
                if (nouvelleOrientation>margeErreur){
                    if (nouvelleOrientation == gauche) return QPoint(point_click.x()-etendueZone,point_click.y());
                         else if (nouvelleOrientation == droite) return QPoint(point_click.x()+etendueZone,point_click.y());
                              else if (nouvelleOrientation == bas) return QPoint(point_click.x(),point_click.y()+etendueZone);

                   //std::cout<<"nouvelle DIrection 8: "<<nouvelleOrientation <<std::endl;
                    //return QPoint(point_click.x(),point_click.y()+etendueZone);
                }
                return QPoint(0,0);
     }
                break;
}
     return QPoint(0,0);
}

void carte::parcoursImageAffichage(){

    //parcourir toute la carte
    for (int i=0;i<largeur;i++){
         for (int j=0; j<hauteur;j++){
             if (comparerCouleurAvecMarge( imageCarte->pixel(i,j),coul)==true)
                {imageCarte->setPixel(QPoint(i,j),0xFF00FF00);}
            // else {imageAffichage->setPixel(QPoint(i,j),0xFFFFFF);}
           // std::cout<<"couleur : "<<coul<<std::endl;}
             //imageCarte->setPixel(QPoint(i,j),coul);
         }
     }

}

//première version :
/*
double carte::longueur(QPoint pt, QPoint pt1)

{

double res1 = ((pt1.x()-pt.x())*(pt1.x()-pt.x()));
double res2 = ((pt1.y()-pt.y())*(pt1.y()-pt.y()));
double res3 = res1 + res2;

double resultat = qSqrt(res3);
return resultat;
}

double carte::angleA(QPoint a, QPoint b, QPoint c)
{
    double ab,bc,ac,res;
    ab=longueur(a,b);
    bc=longueur(b,c);
    ac=longueur(a,c);

    res = acos( ((ab*ab)+(ac*ac)-(bc*bc))/(2*(bc)*(ac)));
    return res;

}

double carte::angleB(QPoint a, QPoint b, QPoint c)
{
    double ab,bc,ac;
    ab=longueur(a,b);
    bc=longueur(b,c);
    ac=longueur(a,c);
    double res = acos( ((ab*ab)+(bc*bc)-(ac*ac))/(2*(ab)*(bc)));
    return res;
}

double carte::angleC(QPoint a, QPoint b, QPoint c)
{
    double ab,bc,ac;
    ab=longueur(a,b);
    bc=longueur(b,c);
    ac=longueur(a,c);

    bool res = acos( ((ab*ac)+(ac*ac)-(bc*bc))/(2*(bc)*(ac)));
    return res;
}

double carte::aire(QPoint a, QPoint b, QPoint c)
{
    double ab,bc,ac,ai;
    ab=longueur(a,b);
    bc=longueur(b,c);
    ac=longueur(a,c);

    int s = ((ab+ac+bc)/2);
    ai = qSqrt(s*((s-ab)*(s-bc)*(s-ac)));
    return ai;
}

double carte::H(coord_decimal pt, coord_decimal pt1, double a)
{
    double b,h;
    QPoint p,p1;

    p.setX(pt.getLatitude());
    p.setY(pt.getLongitude());
    p1.setX(pt1.getLatitude());
    p1.setY(pt1.getLongitude());

    b=longueur(p,p1);
    h=((2*a)/b);
    return h;

}*/

point_gps carte::pt_gps(QPoint a, QPoint b, QPoint c)
{
    //première version :
   /* QPoint p;
    double angle, cos_angle, h, ai, x, y, ac, ab;
    ai = aire(a,b,c);
    h= H(dec,dec1,ai);
    angle = angleC(a,b,c);
    cos_angle=cos(angle);
    ac=cos_angle*h;
    ab=(((ac)*(ac))-((h)*(h)));
    x=((dec.getLatitude())+ab);
    y=((dec.getLongitude())+ac);

    p.setX(x);
    p.setY(y);
    return p;*/

    point_gps res;
    double x1 = (b.x()-a.x());
    double y1 = (b.y()-a.y());

    double x2 = (c.x()-a.x());
    double y2 = (c.y()-a.y());

    double y_gps = (dec1.getLatitude()-dec.getLatitude());
    double x_gps = (dec1.getLongitude()-dec.getLongitude());

    double var = ((x2*x_gps)/x1);
    double var2 = ((y2*y_gps)/y1);

    double res_x = dec.getLongitude()+var;
    double res_y = dec.getLatitude()+var2;

    res.setX(res_x);
    res.setY(res_y);

    return res;
}


//slots
void carte::augmenter_zoom(){
    std::cout<<"zoom in"<<std::endl;
    //zoom(1.25);
    echelle*=1.25;
    /*QImage newImage= (copieTailleNormale->scaled(largeur*echelle,hauteur*echelle));
    //QImage newImage2= (imageAffichage->scaled(largeur*echelle,hauteur*echelle));
    //QImage newImage3= (tracerChemin->scaled(largeur*echelle,hauteur*echelle));


    imageCarte=new QImage(newImage);
    //imageAffichage=new QImage(newImage2);
    //tracerChemin=new QImage(newImage3);
    largeur=imageCarte->width();
    hauteur=imageCarte->height();*/
    update();
}

void carte::diminuer_zoom(){
    std::cout<<"zoom out"<<std::endl;
    //zoom(0.8);
    echelle*=0.8;
   /* QImage newImage= (copieTailleNormale->scaled(largeur*echelle,hauteur*echelle));
    //QImage newImage2= (imageAffichage->scaled(largeur*echelle,hauteur*echelle));
    //QImage newImage3= (tracerChemin->scaled(largeur*echelle,hauteur*echelle));

    imageCarte=new QImage(newImage);
    //imageAffichage=new QImage(newImage2);
    //tracerChemin=new QImage(newImage3);
    largeur=imageCarte->width();
    hauteur=imageCarte->height();*/
    update();
}

void carte::attributCouleur(const QPoint &p){
    QRgb pt ;
    setPoint(p);
    pt = imageCarte->pixel(p);
    point_depart=p;
    setCouleur(pt);
}

void carte::fermerProjet(){

  QImage newImage(0,0,QImage::Format_ARGB32);
  hauteur=0;
  largeur=0;
  imageCarte= new QImage(newImage);
  tracerChemin= new QImage(newImage);
  imageAffichage=new QImage(newImage);
  copieTailleNormale=new QImage(newImage);
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
        //painter.drawImage(point,*imageCarte);
        painter.drawImage(point,*imageAffichage);
        //painter.drawImage(point,*tracerChemin);
        point_gps p = pt_gps(point1_gps,point2_gps,point_depart);
        std::cout<<"point : "<<point_depart.x()<<" "<<point_depart.y()<<" coord gps :"<<p.X()<<" "<<p.Y()<<std::endl;
    }
    else if ((carteDessiner)&&(flags==2)){
            QPainter painter(this);
            QPoint point (0,0);
            painter.drawImage(point,*imageAffichage);
            if (nbpoint==1) {
                 QPainter painter(this);
                 QPoint point (0,0);
                 painter.drawImage(point,*imageAffichage);
                 painter.drawImage(getPoint1(),*p1);
                  } else if (nbpoint==2) {
                            QPainter painter(this);
                            QPoint point (0,0);
                            painter.drawImage(point,*imageAffichage);
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
    if ((differenceRouge + differenceVert + differenceBleu)>100) return false;
        else return true;

    /*int couleurDominante= maximum(differenceBleu,maximum(differenceRouge, differenceVert));
    if(couleurDominante>40) return false;   //40
                 else if ((differenceRouge + differenceVert + differenceBleu)>100) return false;  //100
    else return true;*/
              //if (somme<10) return true;
}


int carte::tracerZone(const QPoint &p,const QRgb &color){
    int nbPixel=0;
    for (int i=p.x()-etendueZone; i<p.x()+etendueZone;i++){
        for (int j=p.y()-etendueZone; j<p.y()+etendueZone;j++){
            if((i<=largeur)&&(i>=0)&&(j>=0)&&(j<=hauteur)){
            if ( comparerCouleurAvecMarge(color,imageAffichage->pixel(QPoint(i,j)))) {
                imageAffichage->setPixel(QPoint(i,j),255255255);
                tracerChemin->setPixel(QPoint(i,j),255255255);
                nbPixel++;
            }
            }
        }
    }
   return nbPixel;
}






/*************************Brouillon  algo******************************************




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





    //tracer diagonale et parcourir rectangle
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
                }*/

   /*


***************************************************************************************/

