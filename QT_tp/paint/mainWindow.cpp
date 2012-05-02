#include "mainWindow.h"


MainWindow::MainWindow()
{
    m_westLayout = new QHBoxLayout(this);
    m_dessin = new ZoneDessin();
    m_eastLayout = new QVBoxLayout();
    m_effacer = new QPushButton("Effacer");

    m_eastLayout->addWidget(m_effacer,Qt::AlignRight);
    m_westLayout->addWidget(m_dessin);
    m_westLayout->addLayout(m_eastLayout);

    m_eastLayout->setAlignment(Qt::AlignTop);

    QObject::connect(m_effacer, SIGNAL(clicked()),m_dessin,SLOT(clearImage()));

}

MainWindow::~MainWindow()
{
}

