#include "coord_decimal.h"

coord_decimal::coord_decimal():longitude(0),latitude(0)
{
}



//accesseurs
double coord_decimal::getLatitude()
{
    return latitude;
}

double coord_decimal::getLongitude()
{
    return longitude;
}


//muttateurs
void coord_decimal::setLatitude(double la)
{
    latitude = la;
}

void coord_decimal::setLongitude(double lo)
{
    longitude = lo;
}
