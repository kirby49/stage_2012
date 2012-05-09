#ifndef COORD_DECIMAL_H
#define COORD_DECIMAL_H

class coord_decimal
{
private:
    float latitude;
    float longitude;


public:
    coord_decimal();
    // getteurs
    float getLatitude();
    float getLongitude();


    //seteurs
    void setLatitude(float la);
    void setLongitude(float lo);

    void toSexagesimal(int la,int lo);




};

#endif // COORD_DECIMAL_H
