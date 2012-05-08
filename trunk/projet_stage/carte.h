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
    //float largeur;
    //float longueur;
    float echelle;


public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(float valeur);

    QRgb getCouleur();
    void setCouleur(QRgb c);
    void setCouleur_rgb(QString str);
    QString getCouleur_rgb();

signals:
    void ChangeRes();

public slots:
    void augmenter_zoom();
    void diminuer_zoom();
    void fermerProjet();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // CARTE_H
