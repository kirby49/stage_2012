#ifndef TABLEUR_H
#define TABLEUR_H

#include "cell.h"
#include <iostream>

using namespace std;

class Tableur : public QWidget
{
    Q_OBJECT

    public :
        Tableur(QWidget * parent = 0);
        ~Tableur();
        void calculateCellSize();
        void setLign(int lign);
        void setColumn(int column);
        void selectClickedCell(QPoint point);

    public slots:
        void mousePressEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void clearImage();
        void drawGrid();
        void showSelectedCell();
        void addLign();
        void addColumn();
        void addCell();

    signals :

    private :
        QGridLayout m_grid;
        QImage m_image;
        QLineEdit *m_textZone;
        QSize m_cellSize;
        int m_lign;
        int m_column;
        QPoint m_cellSelected;
        QList<Cell> m_cellList;



};

#endif // TABLEUR_H
