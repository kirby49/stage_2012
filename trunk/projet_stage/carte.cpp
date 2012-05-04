#include "carte.h"


carte::carte()

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
    label->adjustSize();

    scroll= new QScrollArea;
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(label);
    global->addWidget(scroll);

    zom= new QPushButton("zoom");
    QObject::connect(zom, SIGNAL(clicked()), this, SLOT(augmenter_zoom()));
    dezoom=new QPushButton("dezoom");
    QObject::connect(zom, SIGNAL(clicked()), this, SLOT(diminuer_zoom()));
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

void carte::zoom(double valeur){
    echelle = (valeur * echelle);
    label->resize(echelle * label->pixmap()->size());
}

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


void carte::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint p=getPoint_click();
    if (event->button() == Qt::LeftButton)
        {
        QRgb pt = image->pixel(p);
        }
    setPoint(pt);
}
