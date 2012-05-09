#ifndef CARTE_H
#define CARTE_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>

class carte: public QWidget
{
    Q_OBJECT

private:

    QImage* image;
    QMouseEvent *event;
    QPoint point_click;
    QRgb coul;
    QLabel* valeurZoom;
    QPainter* painter;

    bool imageDessiner;
    float echelle;
    int hauteur;
    int largeur;


public:
    carte();
    ~carte();
    bool getImageDessiner();
    void setImagedessiner(bool choix);
    void afficherImage(QString chemin);
    void zoom(float valeur);

    QRgb getCouleur();
    void setCouleur(QRgb c);

    QPoint getPoint();
    void setPoint(QPoint p);
    bool comparerCouleurAvecMarge(QRgb p1, QRgb p2);
    int maximum(int a , int b);



signals:
    void ChangeRes();
    void test(const QPoint &p);
    void ChangeZoom();
    void ChangeZoomIn();
    void signalDessinerChemin();


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void dessinerChemin();
    void attributCouleur(const QPoint &p);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // CARTE_H
