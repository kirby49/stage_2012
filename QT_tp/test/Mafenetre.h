#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QLCDNumber>
#include <QString>
#include <iostream>
#include <sstream>

using namespace std;

class Mafenetre : public QWidget
{
    Q_OBJECT

    public :
        Mafenetre();
        ~Mafenetre();

    private slots:
        void afficherRes();
        void spin1Res(int i);
        void spin2Res(int i);
        void comboRes(QString index);

    private :
        QHBoxLayout *m_layout;
        QSpinBox *m_spinb1;
        QSpinBox *m_spinb2;
        QComboBox *m_combo;
        QPushButton *m_button;
        QLCDNumber *m_lcd;

};
#endif // MAFENETRE_H
