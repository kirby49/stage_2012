// VIVIER Romain
#include "mainWindow.h"


MainWindow::MainWindow()
{
    m_frame = new QVBoxLayout(this);
    m_globalLayout = new QHBoxLayout();
    m_westLayout = new QHBoxLayout();
    m_widget = new MyWidget();
    m_eastLayout = new QVBoxLayout();
    m_action = new QPushButton("Quitter");

    m_eastLayout->addWidget(m_action,Qt::AlignJustify);
    m_westLayout->addWidget(m_widget);
    m_globalLayout->addLayout(m_westLayout);
    m_globalLayout->addLayout(m_eastLayout);
    m_frame->addLayout(m_globalLayout);

    m_eastLayout->setAlignment(Qt::AlignTop);

    connect(m_action, SIGNAL(clicked()),qApp,SLOT(quit()));
    //QObject::connect(m_addColumn, SIGNAL(clicked()),m_table,SLOT(addColumn()));

}

MainWindow::~MainWindow()
{
}
