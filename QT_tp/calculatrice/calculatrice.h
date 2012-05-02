#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "moteur.h"
#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <iostream>

using namespace std;

class Calculatrice : public QWidget
{
    Q_OBJECT

    public :
        Calculatrice();
        ~Calculatrice();

    private slots:
        void plus();
        void less();
        void times();
        void divide();
        void square();
        void clear();
        void afficher(QString value);
        void afficherOp(QString op);

    private :
        QVBoxLayout *m_layoutPrinc;
        QVBoxLayout *m_layoutNord;
        QHBoxLayout *m_layoutSud;
        QGridLayout *m_layoutOuest;
        QGridLayout *m_layoutEst;
        QPushButton *m_1;
        QPushButton *m_2;
        QPushButton *m_3;
        QPushButton *m_4;
        QPushButton *m_5;
        QPushButton *m_6;
        QPushButton *m_7;
        QPushButton *m_8;
        QPushButton *m_9;
        QPushButton *m_0;
        QPushButton *m_virgule;
        QPushButton *m_plus;
        QPushButton *m_less;
        QPushButton *m_times;
        QPushButton *m_divide;
        QPushButton *m_bracketL;
        QPushButton *m_bracketR;
        QPushButton *m_square;
        QPushButton *m_equal;
        QPushButton *m_clear;
        QLineEdit *m_lineEqu;
        QLineEdit *m_lineRes;
        Moteur *moteur;


};

#endif // CALCULATRICE_H
