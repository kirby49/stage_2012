// VIVIER Romain
#include "mainWindow.h"


MainWindow::MainWindow()
{
    m_globalLayout = new QHBoxLayout(this);
    m_widget = new MyWidget();
    m_checkbox = new QCheckBox();

    m_globalLayout->setSpacing(0);
    m_globalLayout->addStretch();
    m_globalLayout->addWidget(m_widget);
    m_globalLayout->addStretch();
    m_globalLayout->addWidget(m_checkbox);
    m_globalLayout->addStretch();

    m_globalLayout->setAlignment(Qt::AlignTop);

    //QObject::connect(m_addLign, SIGNAL(clicked()),m_table,SLOT(addLign()));
    //QObject::connect(m_addColumn, SIGNAL(clicked()),m_table,SLOT(addColumn()));

}

MainWindow::~MainWindow()
{
}

