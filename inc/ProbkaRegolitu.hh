#ifndef PROBKA_REGOLITU_HH
#define PROBKA_REGOLITU_HH

#include "ObiektGeom.hh"


class ProbkaRegolitu : public ObiektGeom
{
    public:
        ProbkaRegolitu(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID) : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID){}
    virtual TypKolizji CzyKolizja()
    { 
        return BrakKolizji;
    }
    char SprawdzTyp()
    {
        return 'P';
    }
};

#endif