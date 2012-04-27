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

QObject::connect(nom, SIGNAL( changeEvent(QString) ), this, SLOT( updateNom(QString) ));
QObject::connect(this, SIGNAL( changeRes(int) ), , SLOT( setNum(int) ));

for (int i = 0; i < strOp.size(); ++i) {
     if (strOp.at(i) == name )
         updateChemin("/home/etudiant/"+name);

 }


}


void directory::updateNom(QString str)
{
  name = str;
}


void directory::updateChemin(QString str)
{
    for (int i = 0; i < strOp.size(); ++i) {
         if (strOp.at(i) == name )
             cheminDuRepertoire = str;

     }

}
