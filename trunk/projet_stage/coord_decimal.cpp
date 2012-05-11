#include "coord_decimal.h"

coord_decimal::coord_decimal():longitude(0),latitude(0)
{
}



//accesseurs
float coord_decimal::getLatitude()
{
    return latitude;
}

float coord_decimal::getLongitude()
{
    return longitude;
}


//muttateurs
void coord_decimal::setLatitude(float la)
{
    latitude = la;
}

void coord_decimal::setLongitude(float lo)
{
    longitude = lo;
}
