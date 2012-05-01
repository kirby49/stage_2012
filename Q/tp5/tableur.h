#ifndef TABLEUR_H
#define TABLEUR_H

#include <Qt/QtGui>

class tableur : public QMainWindow
{
    Q_OBJECT

private :
    int nbcolonne;
    int nbligne;
    QFrame *frame;
    QWidget *w;
    QGridLayout *layout;
    QHBoxLayout *vbox;
    QPushButton *box1;
    QPushButton *box2;

public:
    tableur(int l, int c);


public slots:
    void ajoutligne ();
    void ajoutcol();

};

#endif // TABLEUR_H
