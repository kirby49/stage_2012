#ifndef COORD_SEXAGESIMAL_H
#define COORD_SEXAGESIMAL_H

class coord_sexagesimal
{
private:
    int degree;
    int minute;
    int seconde;

    int degree1;
    int minute1;
    int seconde1;


public:
    coord_sexagesimal();

    //geteurs
    int getDegree();
    int getMinute();
    int getSeconde();

    int getDegree1();
    int getMinute1();
    int getSeconde1();

    //seteurs
    void setDegree(int d);
    void setMinute(int m);
    void setSeconde(int s);

    void setDegree1(int d);
    void setMinute1(int m);
    void setSeconde1(int s);

    void toDecimal(int d,int m,int s);

};

#endif // COORD_SEXAGESIMAL_H
