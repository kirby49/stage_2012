#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "ma_ComboBox.h"

class Directory : public QWidget
{
    Q_OBJECT

    public :
        Directory();
        ~Directory();

    private slots:

    private :
        Ma_ComboBox *m_dir;



};

#endif // DIRECTORY_H
