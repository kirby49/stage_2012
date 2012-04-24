#ifndef MAFENETRE_H
#define MAFENETRE_H


#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class MaFenetre : public QWidget
{
    Q_OBJECT

        public:
        MaFenetre();

        public slots:
        void ouvrirDialogue();

        private:
        QPushButton *m_boutonDialogue;

};

#endif // MAFENTRE_H
