#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <vector>
#include <iostream>

template <typename T, int SIZE>
class Wektor
{
private:

    T coord[SIZE];
   
public:
   
    T get_vect(int i) const { return coord[i]; }              //getter wektora
    
    T &set_vect(int i) { return coord[i]; }                   //setter wektora
    
    T operator[](unsigned int i) const { return coord[i]; }   //dostep do wartosci 
   
    T &operator[](unsigned int i) { return coord[i]; }
    
    Wektor<T, SIZE> operator + (Wektor<T, SIZE> V);        //suma wektorow
   
    Wektor<T, SIZE> operator - (Wektor<T, SIZE> V);         //roznica wektorow
    
    T operator * (Wektor<T, SIZE> V);                      //iloczyn razy wektor
    
    Wektor<T, SIZE> operator & (Wektor<T, SIZE> V);        //iloczyn Wektorowy
    
    Wektor<T, SIZE> operator / (T liczba);                     //iloraz Wektor przez liczbe
    
    Wektor<T, SIZE> operator * (T liczba);                     //iloczyn wektor razy liczba
    
    Wektor<T, SIZE>();
   
    Wektor(std::vector<T> &tmp)                                 // Konstruktor Wektora
    {
        for (int i = 0; i < SIZE; i++)
        {
            coord[i] = tmp[i];
        }
    }

    T &operator = (std::vector<T> &tmp)
    {
        for (int i = 0; i < SIZE; i++)
        {
            coord[i] = tmp[i];
        }
    }
};

/**
 * @brief Szablon przeciążenia operatora >>
 *
 * Opis wczytywania wektora
 * @param Strm - Referencja zmiennej typu istream
 * @param tmp - Referencja zmiennej typu wektor
 * @return Zwraca strumień danych
 */
template <typename T, int SIZE>
std::istream &operator >> (std::istream &Strm, Wektor<T, SIZE> &tmp)
{
    for (int i = 0; i < SIZE; i++)
    {
        Strm >> tmp[i];
    }
    return Strm;
}


/**
 * @brief Szablon przeciążenia operatora <<
 *
 * Opis wyswietlania wektora
 * @param Strm - Referencja zmiennej typu ostream
 * @param tmp - Referencja zmiennej typu wektor
 * @return Zwraca strumień danych
 */
template <typename T, int SIZE>
std::ostream &operator << (std::ostream &Strm, const Wektor<T, SIZE> &tmp)
{
    for (int i = 0; i < SIZE; i++)
    {
        Strm << tmp[i] << "  ";
    }
    return Strm;
}


/**
 * @brief Szablon przeciążenia operatora +
 *
 * Opis dodawania wektora
 * @param V - Zmienna typu wektor
 * @return Zwraca wynik dodawania
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Wektor<T, SIZE>::operator + (Wektor<T, SIZE> V)
{
    Wektor<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coord[i] + V[i];
    }
    return result;
}


/**
 * @brief Szablon przeciążenia operatora -
 *
 * Opis odejmowania wektora
 * @param V - Zmienna typu wektor
 * @return Zwraca wynik odejmowania
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Wektor<T, SIZE>::operator - (Wektor<T, SIZE> V)
{
    Wektor<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coord[i] - V[i];
    }
    return result;
}


/**
 * @brief Szablon przeciążenia operatora *
 *
 * Opis mnozenia wektora przez wektor
 * @param V - Zmienna typu wektor
 * @return Zwraca wynik mnozenia typu T
 */
template <typename T, int SIZE>
T Wektor<T, SIZE>::operator * (Wektor<T, SIZE> V)
{
    T result = 0;
    for (int i = 0; i < SIZE; i++)
    {
        result += coord[i] * V[i];
    }
    return result;
}

/**
 * @brief Iloczyn wektorowy
 * 
 * @tparam T 
 * @tparam SIZE 
 * @param V 
 * @return Wektor<T, SIZE> 
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Wektor<T, SIZE>::operator & (Wektor<T, SIZE> V)
{
    Wektor<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coord[i] * V[i];
    }
    return result;
}


/**
 * @brief Szablon przeciążenia operatora /
 *
 * Opis dzielenia wektora przez liczbe
 * @param liczba - zmienna typu T
 * @return Zwraca wynik dzielenia typu T
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Wektor<T, SIZE>::operator / (T liczba)
{
    Wektor<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coord[i] / liczba;
    }
    return result;
}


/**
 * @brief Szablon przeciążenia operatora *
 *
 * Opis mnozenia wektora przez liczbe
 * @param liczba - zmienna typu T
 * @return Zwraca wynik mnozenia typu T
 */
template <typename T, int SIZE>
Wektor<T, SIZE> Wektor<T, SIZE>::operator * (T liczba)
{
    Wektor<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coord[i] * liczba;
    }
    return result;
}


template <typename T, int SIZE>
Wektor<T, SIZE>::Wektor()
{
    for (int i = 0; i < SIZE; i++)
    {
        coord[i] = 0;
    }
}


#endif
