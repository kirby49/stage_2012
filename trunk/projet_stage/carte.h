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
    QString couleur;
    QRgb coul;

    QLabel* valeurZoom;
    QPainter* painter;
    //float largeur;
    //float longueur;
    float echelle;


public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(float valeur);

    QRgb getCouleur();
    void setCouleur(QRgb c);// pour encode le rgb sans l'alpha
    QString getCouleur_rgb();
    void setCouleur_rgb(QString str);


signals:


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // CARTE_H
