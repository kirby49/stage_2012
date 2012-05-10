#ifndef CARTE_H
#define CARTE_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>

class carte: public QWidget
{
    Q_OBJECT

private:

    QImage* image;
    QImage* tracer_chemin;
    //QImage* smiley;
    QImage* p1;
    QImage* p2;
    QMouseEvent *event;
    QPoint point_click;
    QPoint point_release;
    QPoint point1;
    QPoint point2;
    QRgb coul;
    QLabel* valeurZoom;
    bool imageDessiner;
    float echelle;
    int nbpoint;
    int hauteur;
    int largeur;
    int flags;


public:
    carte();
    ~carte();
    bool getImageDessiner();
    void setImagedessiner(bool choix);
    void afficherImage(QString chemin);
    void zoom(float valeur);

    QRgb getCouleur();
    void setCouleur(QRgb c);

    QPoint getPoint1();
    QPoint getPoint2();
    void setPoint1(QPoint p);
    void setPoint2(QPoint p);

    QPoint getPoint();
    void setPoint(QPoint p);
    bool comparerCouleurAvecMarge(QRgb p1, QRgb p2);
    int maximum(int a, int b);
    int minimum(int a, int b);

    int getFlags();
    void setFlags(int f);//permet de donner un ordre d'exécution au logiciel un déroulé des données: 0 pour le lancement, 2 pour la saisie des points gps, 1 pour la construction du chemin




signals:
    void ChangeRes();
    void changeRes2(const QPoint &p);
    void ChangeZoom();
    void ChangeZoomIn();
    void signalDessinerChemin(const QPoint &p);
    void SignalFlag(const QPoint &p);


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void setNbpoint ();
    void dessinerChemin(const QPoint &p);
    void attributCouleur(const QPoint &p);
    void placerFlag1(const QPoint &p);
    void placerFlag2(const QPoint &p);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // CARTE_H
