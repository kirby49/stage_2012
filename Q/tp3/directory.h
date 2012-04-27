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
  void updateNom(QString v);

signals :
    void changeRes(int v);


private:

    QComboBox *liste;
    QLineEdit *nom;
    QString name;
};

#endif // DIRECTORY_H
