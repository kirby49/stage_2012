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
        QVBoxLayout *m_frame;
        QHBoxLayout *m_globalLayout;
        QHBoxLayout *m_westLayout;
        QVBoxLayout *m_eastLayout;
        QPushButton *m_action;

};

#endif // MAINWINDOW_H
