#include "coord_sexagesimal.h"

coord_sexagesimal::coord_sexagesimal():degree(0),minute(0),seconde(0)
{
}

//accesseurs
int coord_sexagesimal::getDegree()
{
    return degree;
}

int coord_sexagesimal::getMinute()
{
    return minute;
}

int coord_sexagesimal::getSeconde()
{

   return seconde;
}

int coord_sexagesimal::getDegree1()
{
    return degree1;
}

int coord_sexagesimal::getMinute1()
{
    return minute1;
}

int coord_sexagesimal::getSeconde1()
{

   return seconde1;
}

//mutateurs
void coord_sexagesimal::setDegree(int d)
{
    degree=d;
}

void coord_sexagesimal::setMinute(int m)
{
    minute=m;
}

void coord_sexagesimal::setSeconde(int s)
{
    seconde=s;
}


void coord_sexagesimal::setDegree1(int d)
{
    degree1=d;
}

void coord_sexagesimal::setMinute1(int m)
{
    minute1=m;
}

void coord_sexagesimal::setSeconde1(int s)
{
    seconde1=s;
}
