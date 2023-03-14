#ifndef SCENA_HH
#define SCENA_HH
#include "Lazik.hh"
#include "Kolory.hh"
#include "PowierzchniaMarsa.hh"
#include <list>
#include <memory>
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#include "ProbkaRegolitu.hh"
#include "LazikSFR.hh"
#include "TypKolizji.hh"

class Scena
{
    private:
        PzG::LaczeDoGNUPlota Lacze;
        std::shared_ptr<Lazik> aktualny_lazik;
        std::list<std::shared_ptr<ObiektGeom>> lista_lazikow;
        
        /**
        *  @brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
        *
        *  Inicjalizuje podstawowe parametry "swiata", wymiary,
        *  które będą widoczne jako obszar objęty układem współrzędnych.
        *  Następnie w tle uruchamiany jest program gnuplot.
        *  @param rLacze - nieaktywne łącze do gnuplota.
        */

        void Inicjalizuj_Lacze();
    
public:
    
    Scena();


    /**
     *  @brief Funkcja pobierajaca nazwe aktywnego lazika
     *
     *  Metoda pobiera nazwe aktualnego lazika
     *  @return wskaznik na nazwe lazika
     */
    std::string nazwa_akt()
    {return aktualny_lazik->WezNazweObiektu();}


    /**
     *  @brief Funkcja pobierajaca polozenie aktywnego lazika
     *
     *  Metoda pobiera nazwe aktywnego lazika
     *  @return wskaznik na polozenie lazika typu Wektor3D
     */
    Wektor3D polozenie_akt() 
    {return aktualny_lazik->get_polozenie();}


     /**
     *  @brief Funkcja pobierajaca kat aktywnego lazika
     *
     *  Metoda pobiera kat aktywnego lazika
     *  @return wskaznik na kat lazika
     */
    double kat_aktualny() 
    {return aktualny_lazik->get_kat();}

    void Ruch(double kat, double droga, double szybkosc);
    void PrzejazdTestowy();
    void wybor(int n);
    void DodajDoListyRysowania();
    void Rysuj();
    void wypisz();
    void wypisz_Probki_Regolitu();
    void ZbierzProbke();
    
    
};

#endif