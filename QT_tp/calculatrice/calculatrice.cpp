#include "calculatrice.h"


Calculatrice::Calculatrice() : QWidget()
{
    //initialisation des widgets utilisés
    m_layoutPrinc = new QVBoxLayout(this);
    m_layoutNord = new QVBoxLayout();
    m_layoutSud = new QHBoxLayout();
    m_layoutOuest = new QGridLayout();
    m_layoutEst = new QGridLayout();
    m_1 = new QPushButton("1");
    m_2 = new QPushButton("2");
    m_3 = new QPushButton("3");
    m_4 = new QPushButton("4");
    m_5 = new QPushButton("5");
    m_6 = new QPushButton("6");
    m_7 = new QPushButton("7");
    m_8 = new QPushButton("8");
    m_9 = new QPushButton("9");
    m_0 = new QPushButton("0");
    m_virgule = new QPushButton(",");
    m_plus = new QPushButton("+");
    m_less = new QPushButton("-");
    m_times = new QPushButton("*");
    m_divide = new QPushButton("/");
    m_bracketL = new QPushButton("(");
    m_bracketR = new QPushButton(")");
    m_square = new QPushButton("^2");
    m_equal = new QPushButton("=");
    m_clear = new QPushButton("Clear");
    m_lineEqu = new QLineEdit();
    m_lineRes = new QLineEdit();

    //manager de widgets principal
    m_layoutPrinc->addLayout(m_layoutNord);
    m_layoutPrinc->addLayout(m_layoutSud);

    //manager de widget nord
    m_layoutNord->addWidget(m_lineEqu);
    m_layoutNord->addWidget(m_lineRes,0,Qt::AlignRight);

    //manager de widgets sud
    m_layoutSud->addLayout(m_layoutOuest);
    m_layoutSud->addLayout(m_layoutEst);

    //manager de widget Oeust
    m_layoutOuest->addWidget(m_0,4,1,1,2);
    m_layoutOuest->addWidget(m_virgule,4,3);
    m_layoutOuest->addWidget(m_1,3,1);
    m_layoutOuest->addWidget(m_2,3,2);
    m_layoutOuest->addWidget(m_3,3,3);
    m_layoutOuest->addWidget(m_4,2,1);
    m_layoutOuest->addWidget(m_5,2,2);
    m_layoutOuest->addWidget(m_6,2,3);
    m_layoutOuest->addWidget(m_7,1,1);
    m_layoutOuest->addWidget(m_8,1,2);
    m_layoutOuest->addWidget(m_9,1,3);
    m_layoutOuest->setSpacing(0);
    m_layoutOuest->setAlignment(Qt::AlignJustify);

    //manager de widget Est
    m_layoutEst->addWidget(m_square,5,1);
    m_layoutEst->addWidget(m_equal,5,2);
    m_layoutEst->addWidget(m_bracketL,4,1);
    m_layoutEst->addWidget(m_bracketR,4,2);
    m_layoutEst->addWidget(m_times,3,1);
    m_layoutEst->addWidget(m_divide,3,2);
    m_layoutEst->addWidget(m_plus,2,1);
    m_layoutEst->addWidget(m_less,2,2);
    m_layoutEst->addWidget(m_clear,1,1,1,2);
    m_layoutEst->setSpacing(0);
    m_layoutEst->setAlignment(Qt::AlignJustify);

    //Gestion des QlineEdit
    m_lineEqu->setAlignment(Qt::AlignRight);
    m_lineRes->setAlignment(Qt::AlignCenter);
    m_lineRes->setFixedWidth(40);
    m_lineEqu->setReadOnly(true);
    m_lineRes->setReadOnly(true);
    m_lineEqu->setStyleSheet("background: lightgreen");
    m_lineRes->setStyleSheet("background: lightgreen");

    //initialisation moteur
    moteur = new Moteur();

    //connections signal slot
    QObject::connect(m_1, SIGNAL(clicked()),moteur,SLOT(add1()));
    QObject::connect(m_2, SIGNAL(clicked()),moteur,SLOT(add2()));
    QObject::connect(m_3, SIGNAL(clicked()),moteur,SLOT(add3()));
    QObject::connect(m_4, SIGNAL(clicked()),moteur,SLOT(add4()));
    QObject::connect(m_5, SIGNAL(clicked()),moteur,SLOT(add5()));
    QObject::connect(m_6, SIGNAL(clicked()),moteur,SLOT(add6()));
    QObject::connect(m_7, SIGNAL(clicked()),moteur,SLOT(add7()));
    QObject::connect(m_8, SIGNAL(clicked()),moteur,SLOT(add8()));
    QObject::connect(m_9, SIGNAL(clicked()),moteur,SLOT(add9()));
    QObject::connect(m_0, SIGNAL(clicked()),moteur,SLOT(add0()));
    QObject::connect(m_virgule, SIGNAL(clicked()),moteur,SLOT(dot()));
    QObject::connect(m_plus, SIGNAL(clicked()),moteur,SLOT(plus()));
    QObject::connect(m_less, SIGNAL(clicked()),moteur,SLOT(less()));
    QObject::connect(m_times, SIGNAL(clicked()),moteur,SLOT(times()));
    QObject::connect(m_divide, SIGNAL(clicked()),moteur,SLOT(divide()));
    QObject::connect(m_square, SIGNAL(clicked()),moteur,SLOT(square()));
    QObject::connect(moteur, SIGNAL(valueChanged(QString)),this,SLOT(afficher(QString)));
    QObject::connect(moteur, SIGNAL(opChanged(QString)),this,SLOT(afficherOp(QString)));
}

Calculatrice::~Calculatrice()
{
}

void Calculatrice::afficher(QString value)
{
    m_lineEqu->setText(value);
}

void Calculatrice::afficherOp(QString value)
{
    m_lineRes->setText(value);
}

void Calculatrice::plus()
{
    m_lineRes->setText("+");
    m_lineEqu->setText("");
}

void Calculatrice::less()
{
    m_lineRes->setText("-");
    m_lineEqu->setText("");
}

void Calculatrice::times()
{
    m_lineRes->setText("*");
    m_lineEqu->setText("");
}

void Calculatrice::divide()
{
    m_lineRes->setText("/");
    m_lineEqu->setText("");
}


void Calculatrice::square()
{
    m_lineRes->setText("^2");
}

void Calculatrice::clear()
{
    m_lineEqu->setText("");
}


