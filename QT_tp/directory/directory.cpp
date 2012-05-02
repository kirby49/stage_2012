#include "directory.h"


Directory::Directory()
{
    m_dir = new Ma_ComboBox(this);


    QObject::connect(m_dir, SIGNAL(activated(QString)),m_dir,SLOT(cd(QString)));
    QObject::connect(m_dir, SIGNAL(directoryChanged()),m_dir,SLOT(ls()));
}

Directory::~Directory()
{
}
