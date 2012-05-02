// VIVIER Romain
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    public :
        MainWindow();
        ~MainWindow();

    private slots:

    private :
        MyWidget *m_widget;
        QHBoxLayout *m_globalLayout;
        QLabel *m_label;



};

#endif // MAINWINDOW_H
