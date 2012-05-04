#ifndef CARTE_H
#define CARTE_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>

class carte: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* global;
    QImage* image;
    QLabel* label;
    QScrollArea* scroll;
    QPushButton* zom;
    QPushButton* dezoom;
    QLabel* valeurZoom;
    //float largeur;
    //float longueur;
    float echelle;

public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(float valeur);

public slots:
    void augmenter_zoom();
    void diminuer_zoom();

};

#endif // CARTE_H
