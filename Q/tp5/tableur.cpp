#include "tableur.h"

tableur::tableur()
{

    QFrame *frame = new QFrame(this);
       frame->setFrameShape(QFrame::StyledPanel);
       frame->setGeometry(100, 100, 500, 500);


       QLabel *frame1 = new QLabel(this);
       frame1->setGeometry(0, 0, 15, 15);
       frame1->setFrameShape(QFrame::Box);

       QLabel *frame2 = new QLabel(this);
       frame2->setGeometry(0, 0, 15, 15);
       frame2->setFrameShape(QFrame::Box);

       QLabel *frame3 = new QLabel(this);
       frame3->setGeometry(0, 0, 15, 15);
       frame3->setFrameShape(QFrame::Box);

       QLabel *frame4 = new QLabel(this);
       frame4->setGeometry(0, 0, 15, 15);
       frame4->setFrameShape(QFrame::Box);


       QGridLayout *layout = new QGridLayout;
       layout->addWidget(frame1, 0, 0);
       layout->addWidget(frame2, 1, 0);
       layout->addWidget(frame3, 0, 1);
       layout->addWidget(frame4, 1, 1);
       layout->setHorizontalSpacing(0);
       layout->setVerticalSpacing(0);

       frame->setLayout(layout);

    /*QGridLayout *grid = new QGridLayout(this);
    QPushButton *b1 = new QPushButton("Un", this);
    QPushButton *b2 = new QPushButton("Deux", this);
    QPushButton *b3 = new QPushButton("Trois", this);
    grid->addWidget(b1,0,0);
    grid->addWidget(b2,0,1);
    grid->addWidget(b3,1,0,1,2);


  /*  QVBoxLayout *vbox = new QVBoxLayout(this);
    QPushButton *box1 = new QPushButton("Inserer une ligne", this);
    QPushButton *box2 = new QPushButton("Inserer une colonne", this);

    vbox->addWidget(box1);
    vbox->addWidget(box2);*/



}
