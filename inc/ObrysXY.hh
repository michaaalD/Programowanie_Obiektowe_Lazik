#ifndef OBRYSXY_HH
#define OBRYSXY_HH
#include "Wektor2D.hh"
#include "cmath"

class ObrysXY
{
    private: 
        Wektor2D GornyPrawy;
        Wektor2D DolnyLewy;
    public:
        
        Wektor2D getGornyPrawy() const { return GornyPrawy;};
        Wektor2D getDolnyLewy()  const { return DolnyLewy;};

        Wektor2D &setGornyPrawy()  { return GornyPrawy;};
        Wektor2D &setDolnyLewy()   { return DolnyLewy;};

     
};

#endif