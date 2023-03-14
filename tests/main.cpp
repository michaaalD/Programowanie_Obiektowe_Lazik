#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Scena.hh"
#include "Lazik.hh"
#include "Macierz3D.hh"
#include "Wektor3D.hh"
#include "ObiektGeom.hh"
#include "PowierzchniaMarsa.hh"
#include "size.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("Set i Get Odleglosci dla Lazika")
{
    Lazik L;

    L.set_Odleglosc() = 20;
    CHECK(L.get_Odleglosc() == 20);
}

TEST_CASE("Set i Get Szybkosci dla Lazika")
{
    Lazik L;

    L.set_szybkosc() = 10;
    CHECK(L.get_szybkosc() == 10);
}


TEST_CASE("Ruch lazika do przodu")
{
    Scena temp;
    Wektor3D Polozenie = temp.polozenie_akt();
    temp.Ruch(0,1,1);
    Wektor3D Akt = temp.polozenie_akt();

    CHECK((Polozenie[1] + 1) == ( Akt[1]));
}

TEST_CASE("Obrot lazika")
{
    Scena temp;
    double x = temp.kat_aktualny();
    
    temp.Ruch(1,0,0);
    CHECK((x+1) == temp.kat_aktualny());
}

TEST_CASE("Wybor lazika")
{
    Scena temp;
    temp.wybor(1);

    CHECK(temp.nazwa_akt() == "SFR");
}


TEST_CASE("Sprawdzenie Typu obiektu")
{
    Lazik *L = new Lazik();
    CHECK(L->SprawdzTyp() == 'L');
}



