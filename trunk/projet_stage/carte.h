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
    double zoom;
   // QPushButton* b;
public:
    carte();
    ~carte();
    void afficherImage(QString chemin);

};

#endif // CARTE_H
