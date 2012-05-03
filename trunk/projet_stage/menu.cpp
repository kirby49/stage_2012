#include "menu.h"

MENU::MENU(QWidget * parent):QMenu(parent)
{

    menuFichier = this->addMenu("&Fichier");
    menuEdition = this->addMenu("&Edition");


    QAction *ouvrir = menuFichier->addAction("Ouvrir");
    ouvrir->setShortcut(QKeySequence("Ctrl+o"));

    //QObject::connect(ouvrir, SIGNAL(triggered()), , SLOT(telechargerImage()));
}


void MENU::telechargerImage()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
      // QMessageBox::information(this, "Fichier", "Vous avez selectionne :\n" + fichier);
       image->afficherImage(fichier);
}
