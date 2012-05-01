#include "directory.h"



directory::directory()
{

//nom= new QLineEdit(this);
name = "";
liste = new QComboBox(this);

cheminDuRepertoire = "/home/etudiant/";
QDir repertoire(cheminDuRepertoire);

QStringList strOp(repertoire.entryList());
liste->insertItems(0,strOp);

QObject::connect(liste, SIGNAL( currentText(QString) ), this, SLOT( updateNom(QString) ));


for (int i = 0; i < strOp.size(); ++i) {
     if (strOp.at(i) == name )
         updateChemin("/home/etudiant/"+name);

 }

QObject::connect(this, SIGNAL( ChangeRes(QString) ),liste, SLOT( insertItems(0,name)));
}


void directory::updateNom(QString str)
{
  name = str;
}


void directory::updateChemin(QString str)
{
    cheminDuRepertoire = str;
    emit ChangeRes (cheminDuRepertoire);


}
