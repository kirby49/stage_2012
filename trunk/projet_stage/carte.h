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
    QPoint point_release;
    QRgb coul;
    QLabel* valeurZoom;
    QPainter* painter;
    int flags;
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

    int getFlags();
    void setFlags(int f);//permet de donner un ordre d'exécution au logiciel un déroulé des données: 0 pour le lancement, 2 pour la saisie des points gps, 1 pour la construction du chemin



signals:
    void ChangeRes();
    void changeRes2(const QPoint &p);
    void ChangeZoom();
    void ChangeZoomIn();
    void signalDessinerChemin(const QPoint &p);


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void dessinerChemin(const QPoint &p);
    void attributCouleur(const QPoint &p);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // CARTE_H
