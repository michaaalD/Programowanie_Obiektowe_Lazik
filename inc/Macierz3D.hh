#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include "Macierz.hh"
#include <cmath>

typedef Macierz <double,3> Macierz3D;


/**
 * @brief funkcja rotujaca macierz o zadany kat
 * 
 * @param kat kat o jaki ma sie obrocic macierz
 * @return Macierz3D 
 */
Macierz3D Rotacja(double kat);

#endif