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
