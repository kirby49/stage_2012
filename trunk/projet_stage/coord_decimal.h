#ifndef COORD_DECIMAL_H
#define COORD_DECIMAL_H

class coord_decimal
{
private:
    double latitude;
    double longitude;


public:
    coord_decimal();
    // getteurs
    double getLatitude();
    double getLongitude();


    //seteurs
    void setLatitude(double la);
    void setLongitude(double lo);

    void toSexagesimal(double la,double lo);




};

#endif // COORD_DECIMAL_H
