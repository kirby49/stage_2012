#ifndef FENETRE_H
#define FENETRE_H
#include <QtGui>



class fenetre : public QWidget
{
     Q_OBJECT

private:
int ga;
int dr;
char valop;
QSpinBox *gauche;
QSpinBox *droite;
QComboBox *operateur;
QPushButton *activer;
QLabel *res;

signals :
   void changeRes(int v);


public slots:
    void updateOp1(int v);
    void updateOp2(int v);
    void updateOperateur(const QString & str);
    void calcule();


public:
    fenetre();

};

#endif // FENETRE_H
