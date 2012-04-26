#ifndef CALCUL_H
#define CALCUL_H

#include "QtGui"

class calcul : public QWidget
{
    Q_OBJECT

public:
    calcul();
private :
 QComboBox  *liste;
 QSpinBox *g;
 QSpinBox *d;
 QPushButton *bouton;
 QLineEdit *res;

public slots:
  int calculer(int x, QString c, int y);

};

#endif // CALCUL_H
