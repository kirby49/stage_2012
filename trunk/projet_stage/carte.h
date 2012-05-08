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

    QMouseEvent *event;
    QPoint point;
    QPoint point_click;
    //QRgb couleur;
    QColor coul;

    QLabel* valeurZoom;
    //float largeur;
    //float longueur;
    float echelle;


public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(float valeur);

    QPoint getPoint();
    QPoint getPoint_click();
    void setPoint(QPoint p);
    void setPoint_click(QPoint p);

    QColor getCouleur();
    void setCouleur(QRgb c);// pour encode le rgb sans l'alpha

signals:


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // CARTE_H
