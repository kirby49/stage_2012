// VIVIER Romain
#include "mainWindow.h"


MainWindow::MainWindow()
{
    m_globalLayout = new QHBoxLayout(this);
    m_widget = new MyWidget();
    m_label = new QLabel("0");


    m_globalLayout->addWidget(m_label);
    m_globalLayout->addWidget(m_widget);

    //QObject::connect(m_addLign, SIGNAL(clicked()),m_table,SLOT(addLign()));
    //QObject::connect(m_addColumn, SIGNAL(clicked()),m_table,SLOT(addColumn()));

}

MainWindow::~MainWindow()
{
}

