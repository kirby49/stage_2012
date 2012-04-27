#include "directory.h"

directory::directory()
{

nom= new QLineEdit(this);

liste = new QComboBox(this);

QString cheminDuRepertoire = "/home/etudiant/";
QDir repertoire(cheminDuRepertoire);

QStringList strOp(repertoire.entryList());
liste->insertItems(0,strOp);

QObject::connect(nom, SIGNAL( changeEvent(QString) ), this, SLOT( updateNom(QString) ));


}


void directory::updateNom(QString str)
{
  name = str;
}
