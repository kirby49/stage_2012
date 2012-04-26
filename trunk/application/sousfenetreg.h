#ifndef SOUSFENETREG_H
#define SOUSFENETREG_H
#include <QApplication>
#include <QtGui>

class SOUSFENETREG : public QWidget
{
public:
    SOUSFENETREG();

private:
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
    QPushButton *bouton5;

    QGridLayout *layout;
};

#endif // SOUSFENETREG_H
