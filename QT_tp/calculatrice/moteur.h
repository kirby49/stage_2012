#ifndef MOTEUR_H
#define MOTEUR_H

#include <QtCore/QtCore>
#include <iostream>
#include <QtGui/QtGui>

using namespace std;

class Moteur : public QObject
{
    Q_OBJECT

public:
    Moteur();
    ~Moteur();
    void calculateOrder(QString sign);
    void calculate(QString sign);
    int getPriority(QString sign);
    void echoVector();

private:
    QStack<QString> m_stack_nbr;
    QStack<QString> m_stack_op;
    QVector<QString> test;
    QString m_number;

public slots:
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void add0();
    void dot();
    void plus();
    void less();
    void times();
    void divide();
    void bracketL();
    void bracketR();
    void square();
    void clear();
    void afficheEqu();

signals:
    void valueChanged(QString);
    void opChanged(QString);


};

#endif // MOTEUR_H
