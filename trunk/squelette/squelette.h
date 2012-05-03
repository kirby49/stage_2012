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
        void mouseMoveEvent ( QMouseEvent * event );//est appelé chaque fois que la souris se déplace avec l'un de ses boutons maintenu enfoncé
        void wheelEvent ( QWheelEvent * event );//utiliser pour la molette de la souris
        void moveEvent(QMoveEvent * event); // est appelé quand le widget a été déplacé, relativement à son parent ;
        //QPoint QWidget::mapFromGlobal ( const QPoint & pos ) const// permet de recupéré les coordonné de la souris dans le widget

        /*//utile si on a plusieurs sous fenetre ce qui permet de faire un traitement uniquement dans la fenetre voulu
        void enterEvent(QEvent * event);// est appelé quand la souris entre dans l'espace de l'écran du widget, cela inclut l'espace de l'écran détenu par tout enfant de ce widget ;
        void leaveEvent();// est appelé quand la souris quitte l'espace de l'écran du widget ; si la souris entre dans un widget enfant, cela ne causera pas un leaveEvent() ;
        */

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
