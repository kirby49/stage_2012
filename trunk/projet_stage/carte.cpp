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
   // b= new QPushButton("ibibi");
    //global->addWidget(b);

    image= new QImage(chemin);


    label= new QLabel();
    label->setPixmap(QPixmap::fromImage(*image));
    global->addWidget(label);
    //scaleFactor = 1.0;
    //label->show();
    //scroll= new QScrollArea;
    //scroll->setWidget(label);

}
