#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>


class fenetre : public QWidget
{

    Q_OBJECT
public:
    fenetre();

private:
    QPushButton *m_boutonDialogue;
};

#endif // FENETRE_H


