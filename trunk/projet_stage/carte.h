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
    QPoint point;
    QPoint point_click;
    QString couleur;
    QRgb coul;
    QLabel* valeurZoom;
    QPainter* painter;

    bool imageDessiner;
    float echelle;
    int longueur;
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
    void setCouleur_rgb(QString str);
    QString getCouleur_rgb();

signals:
    void ChangeRes();
    void ChangeZoom();
    void ChangeZoomIn();


public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // CARTE_H
