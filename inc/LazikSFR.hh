#include "Lazik.hh"
#ifndef LAZIKSFR_HH
#define LAZIKSFR



class LazikSFR : Lazik
{
    public: 
    TypKolizji CzyKolizja(std::shared_ptr<ObiektGeom> ob){
        if(przeciecie_wspolrzednych((ob->getObrys())))
        {
            if( ob->SprawdzTyp() == 'P'){
                return PrzejazdNadProbka;
            }
            else if(ob->SprawdzTyp() == 'L')
            {
                return Kolizja;
            }
        }
        return BrakKolizji;
    }
};
#endif