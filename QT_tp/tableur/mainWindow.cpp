#include "mainWindow.h"


MainWindow::MainWindow()
{
    m_globalLayout = new QHBoxLayout(this);
    m_westLayout = new QHBoxLayout();
    m_table = new Tableur();
    m_eastLayout = new QVBoxLayout();
    m_addLign = new QPushButton("Ajouter une ligne");
    m_addColumn = new QPushButton("Ajouter une colonne");

    m_eastLayout->addWidget(m_addLign);
    m_eastLayout->addWidget(m_addColumn);
    m_westLayout->addWidget(m_table);
    m_globalLayout->addLayout(m_westLayout);
    m_globalLayout->addLayout(m_eastLayout);

    m_eastLayout->setAlignment(Qt::AlignTop);

    QObject::connect(m_addLign, SIGNAL(clicked()),m_table,SLOT(addLign()));
    QObject::connect(m_addColumn, SIGNAL(clicked()),m_table,SLOT(addColumn()));

}

MainWindow::~MainWindow()
{
}

