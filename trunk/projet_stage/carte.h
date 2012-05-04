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
    double scaleValue;
    QPushButton* zom;
    QPushButton* dezoom;

public:
    carte();
    ~carte();
    void afficherImage(QString chemin);

public slots:
    void zoom();

};

#endif // CARTE_H
