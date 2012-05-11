#ifndef COORD_SEXAGESIMAL_H
#define COORD_SEXAGESIMAL_H

class coord_sexagesimal
{
private:
    int degree;
    int minute;
    int seconde;


public:
    coord_sexagesimal();

    //geteurs
    int getDegree();
    int getMinute();
    int getSeconde();

    //seteurs
    void setDegree(int d);
    void setMinute(int m);
    void setSeconde(int s);

    void toDecimal(int d,int m,int s);

};

#endif // COORD_SEXAGESIMAL_H
