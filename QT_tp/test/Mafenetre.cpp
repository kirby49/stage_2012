#include "Mafenetre.h"


Mafenetre::Mafenetre() : QWidget()
{
    //initialisation des widgets utilisés
    m_layout = new QHBoxLayout(this);
    m_spinb1 = new QSpinBox();
    m_spinb2 = new QSpinBox();
    m_combo = new QComboBox();
    m_button = new QPushButton("=");
    m_lcd = new QLCDNumber();

    //ajout des items de la combo box
    m_combo->addItem("+");
    m_combo->addItem("-");
    m_combo->addItem("*");
    m_combo->addItem("/");

    //manager de widgets
    m_layout->addWidget(m_spinb1);
    m_layout->addWidget(m_combo);
    m_layout->addWidget(m_spinb2);
    m_layout->addWidget(m_button);
    m_layout->addWidget(m_lcd);

    QObject::connect(m_button, SIGNAL(clicked()),this,SLOT(afficherRes()));
    QObject::connect(m_spinb1, SIGNAL(valueChanged(int)),this,SLOT(spin1Res(int)));
    QObject::connect(m_spinb2, SIGNAL(valueChanged(int)),this,SLOT(spin2Res(int)));
    QObject::connect(m_combo, SIGNAL(currentIndexChanged(QString)),this,SLOT(comboRes(QString)));

}

Mafenetre::~Mafenetre()
{
}

void Mafenetre::afficherRes()
{

    QString signe = m_combo->currentText();
    int val;
    bool ok = true;

    if(signe == "+") val = m_spinb1->value() + m_spinb2->value();
    if(signe == "-") val = m_spinb1->value() - m_spinb2->value();
    if(signe == "*") val = m_spinb1->value() * m_spinb2->value();
    if(signe == "/")
    {
        if(m_spinb2->value()!=0) val = m_spinb1->value() / m_spinb2->value();
        else
        {
            ok = false;
            m_lcd->display("err");
        }
    }

    if(ok)
    {
        m_lcd->display(val);
    }
}

void Mafenetre::spin1Res(int i)
{
    QString signe = m_combo->currentText();
    int val;
    bool ok = true;

    if(signe == "+") val = i + m_spinb2->value();
    if(signe == "-") val = i - m_spinb2->value();
    if(signe == "*") val = i * m_spinb2->value();
    if(signe == "/")
    {
        if(m_spinb2->value()!=0) val = i / m_spinb2->value();
        else
        {
            ok = false;
            m_lcd->display("err");
        }
    }

    if(ok)
    {
        m_lcd->display(val);
    }
}

void Mafenetre::spin2Res(int i)
{
    QString signe = m_combo->currentText();
    int val;
    bool ok = true;

    if(signe == "+") val = m_spinb1->value() + i;
    if(signe == "-") val = m_spinb1->value() - i;
    if(signe == "*") val = m_spinb1->value() * i;
    if(signe == "/")
    {
        if(i!=0) val = m_spinb1->value() / i;
        else
        {
            ok = false;
            m_lcd->display("err");
        }
    }

    if(ok)
    {
        m_lcd->display(val);
    }
}

void Mafenetre::comboRes(QString index)
{
    QString signe = index;
    int val;
    bool ok = true;

    if(signe == "+") val = m_spinb1->value() + m_spinb2->value();
    if(signe == "-") val = m_spinb1->value() - m_spinb2->value();
    if(signe == "*") val = m_spinb1->value() * m_spinb2->value();
    if(signe == "/")
    {
        if(m_spinb2->value()!=0) val = m_spinb1->value() / m_spinb2->value();
        else
        {
            ok = false;
            m_lcd->display("err");
        }
    }

    if(ok)
    {
        m_lcd->display(val);
    }
}
