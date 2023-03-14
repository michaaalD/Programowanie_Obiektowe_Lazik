#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <algorithm>
#include <iostream>
#include "size.hh"
        
template <typename T, int SIZE>
class Macierz
{
    private:
        Wektor<T, SIZE> coord[SIZE];                          // Wartosci macierzy
        T det;                                                // wyznacznik
        
    public:

        Wektor<T, SIZE> get_wekt(int i) const { return coord[i]; }       //getter Macierzy do wartosci o zadanym indeksie
        
        Wektor<T, SIZE> &set_wekt(int i) { return coord[i]; }            //setter Macierzy do wartosci o zadanym indeksie
        
        Wektor<T, SIZE> operator [] (int i) const { return coord[i]; } 
        
        Wektor<T, SIZE> &operator [] (int i) { return coord[i]; }
       
        Wektor<T, SIZE> operator * (Wektor<T, SIZE> V);                    // operator mnozenia macierzy przez wektor
        
        void Wyznacznik() ;
    
};

/**
 * @brief Metoda wczytujaca do macierzy
 * 
 * @tparam T typ danej
 * @tparam SIZE rozmiar macierzy
 * @param in strumien wej
 * @param mat macierz
 * @return  strumien 
 */
template <typename T, int SIZE>
std::istream &operator >> (std::istream &in, Macierz<T, SIZE> &mat)
{
    for (int i = 0; i < SIZE; i++)
    {
        in >> mat[i];
    }
    return in;
}

/**
 * @brief Metoda wypisujaca macierz
 * 
 * @tparam T typ danej
 * @tparam SIZE rozmiar macierzy
 * @param in strumien wyj
 * @param mat macierz
 * @return  strumien 
 */
template <typename T, int SIZE>
std::ostream &operator << (std::ostream &out, const Macierz<T, SIZE> &mat)
{
    for (int i = 0; i < SIZE; i++)
    {
        out << mat[i] << std::endl;
    }
    return out;
}

/**
 * @brief Metoda mnozaca maceirz przez wektor
 * 
 * @tparam T typ danej
 * @tparam SIZE rozmiar macierzy
 * @param V wektor przez ktory mnozymy
 * @return Wektor<T, SIZE> zwraca wektor 
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Macierz<T, SIZE>::operator * (Wektor<T, SIZE> V)
{
    Wektor<T, SIZE> wynik;
    for (int k = 0; k < SIZE; k++)
        for (int w = 0; w < SIZE; w++)
            wynik[k] = wynik[k] + coord[w][k] * V[w];
    return wynik;
}



#endif
