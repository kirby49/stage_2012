#ifndef MA_COMBOBOX_H
#define MA_COMBOBOX_H

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <iostream>

using namespace std;

class Ma_ComboBox : public QComboBox
{
    Q_OBJECT

    public :
        Ma_ComboBox(QWidget * parent = 0);
        ~Ma_ComboBox();

    public slots:
        void ls();
        void cd(QString dir);
    signals :
        void directoryChanged();

    private :
        QDir m_dir;
        QStringList m_list;




};

#endif // MA_COMBOBOX_H
