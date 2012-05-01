#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QDir>
#include "QtGui"

class directory : public QWidget
{
    Q_OBJECT

public:
    directory();

public slots:
  //void repository(const QString & str);
  void updateNom(QString str);
  void updateChemin (QString str);
signals :
    void ChangeRes(QString str);


private:

    QComboBox *liste;
    QLineEdit *nom;

    QString cheminDuRepertoire;
    QString name;
};

#endif // DIRECTORY_H
