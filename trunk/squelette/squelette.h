#ifndef SQUELETTE_H
#define SQUELETTE_H

#include <QtGui/QtGui>

class squelette: public QWidget
{

    Q_OBJECT
public:
        squelette(QWidget * parent = 0);
        ~squelette();

    public slots:
        void mousePressEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
       // void grabMouse();// attention pas virutel !! agit qd le bouton de la souris est maintenu il agit sur cursor (type QCursor) setcursor permet de le modifié
        void mouseReleaseEvent(QMouseEvent * event );// agit qd le bouton de la souris est relaché
        void  mouseMoveEvent ( QMouseEvent * event );

    signals :

    private :
        QGridLayout m_grid;
        QImage m_image;
        QLineEdit *m_textZone;
        QSize m_cellSize;

        QPoint m_cellSelected;
        QList<Cell> m_cellList;



};


#endif // SQUELETTE_H
