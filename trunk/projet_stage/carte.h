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

public:
    carte();
    ~carte();
    void afficherImage(QString chemin);
    void zoom(double valeur);

public slots:
    void augmenter_zoom();
    void diminuer_zoom();

};

#endif // CARTE_H
