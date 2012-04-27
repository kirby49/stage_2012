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
 QLabel *labelRes;

 int gauche;
 int droite;
 char op;

public slots:
  void calculer();
  void updateOp1(int v);
  void updateOp2(int v);
  void updateOperateur(const QString & str);

signals :
    void changeRes(int v);
};

#endif // CALCUL_H
