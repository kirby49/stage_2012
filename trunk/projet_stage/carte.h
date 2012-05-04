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
    double echelle;
    QPushButton* zom;
    QPushButton* dezoom;
    QMouseEvent *event;
    QPoint point;
    QPoint point_click;
    QRgb couleur;

public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(double valeur);

    QPoint getPoint();
    QPoint getPoint_click();
    void setPoint(QPoint p);
    void setPoint_click(QPoint p);




public slots:
    void augmenter_zoom();
    void diminuer_zoom();


protected:
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // CARTE_H
