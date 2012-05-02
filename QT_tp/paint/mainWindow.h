#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "zoneDessin.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    public :
        MainWindow();
        ~MainWindow();

    private slots:

    private :
        ZoneDessin *m_dessin;
        QHBoxLayout *m_westLayout;
        QVBoxLayout *m_eastLayout;
        QVBoxLayout *m_buttonLayout;
        QPushButton *m_effacer;



};

#endif // MAINWINDOW_H
