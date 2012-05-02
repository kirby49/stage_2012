#include "ma_ComboBox.h"

Ma_ComboBox::Ma_ComboBox(QWidget * parent):QComboBox(parent)
{
    m_dir = QDir::current();
    ls();
}

Ma_ComboBox::~Ma_ComboBox()
{
}


void Ma_ComboBox::ls()
{
    m_dir.setFilter(QDir::AllEntries);
    m_dir.setSorting(QDir::Name);
    m_list = m_dir.entryList();

    this->clear();
    this->addItems(m_list);
}

void Ma_ComboBox::cd(QString dir)
{
    if(m_dir.exists(dir) && m_dir.isReadable()) m_dir.cd(dir);
    else std::cout << "le repertoire n'existe pas ou n'est pas lisible";

    emit directoryChanged();
}
