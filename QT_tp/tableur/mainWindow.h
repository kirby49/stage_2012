#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tableur.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    public :
        MainWindow();
        ~MainWindow();

    private slots:

    private :
        Tableur *m_table;
        QHBoxLayout *m_globalLayout;
        QHBoxLayout *m_westLayout;
        QVBoxLayout *m_eastLayout;
        QVBoxLayout *m_buttonLayout;
        QPushButton *m_addLign;
        QPushButton *m_addColumn;



};

#endif // MAINWINDOW_H
