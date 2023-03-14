#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include <memory>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "TypKolizji.hh"
#include "ObrysXY.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class ObiektGeom
{
  private:

    std::string _NazwaPliku_BrylaWzorcowa;
    std::string _NazwaPliku_BrylaRysowana;
    std::string _NazwaObiektu;
    
    int _KolorID;
    Wektor3D polozenie;
    Wektor3D skala;
    Wektor3D przes;
    Macierz3D rotacja;
    double kat_zadany;
    ObrysXY obrys;

  public:

    ObrysXY getObrys() const { return obrys;};
    ObrysXY &setObrys()      { return obrys;};

    virtual TypKolizji CzyKolizja();

    bool przeciecie_wspolrzednych(ObrysXY obrys_obiektu);
    
    virtual char SprawdzTyp()=0;

    
    /**
     * @brief Construct a new Obiekt Geom object
     * 
     */
    ObiektGeom()
    {
      for (int i = 0; i < 3; ++i)
      {
        rotacja[i][i] = 1;
      }
    }


   /**
    * @brief Set the skala object
    *  Metoda zwraca oryginal zmiennej skala do zmiany
    * @return zwraca referencje skali typu Wektor3D
    */
    Wektor3D &set_skala() { return skala; }
    
    
  

   /**
    * @brief Get the skala object
    *  Metoda zwraca skale
    * @return zwraca skale typu Wektor3D
    */
    Wektor3D get_skala() const { return skala; }


    

   /**
    * @brief Set the wspolrzedne object
    * 
    * @return zwraca wspolrzedne typu Wektor3D 
    */
    Wektor3D &set_wspolrzedne() { return polozenie; }


    
    /**
     * @brief Get the wspolrzedne object
     * 
     * @return zwraca wspolrzedne typu Wektor3D
     */
    Wektor3D get_wspolrzedne() const { return polozenie; }


    
   /**
    * @brief Set the rotacja object
    *  Metoda zwraca oryginal zmiennej rotacja do zmiany
    * @return zwraca referencje rotacji typu Wektor3D 
    */
    Macierz3D &set_rotacja() { return rotacja; }


    /**
    *  \brief Funkcja dostepowa rotacji
    *
    * Metoda zwraca macierz rotacji
    * \return zwraca rotacje typu Macierz3D
    */


   /**
    * @brief Get the rotacja object
    * Metoda zwraca macierz rotacji
    * @return zwraca rotacje typu Macierz3D 
    */
    Macierz3D get_rotacja() { return rotacja; }


   /**
    * @brief Set the kat zadany object
    * Metoda zwraca oryginal zmiennej kat_zadany do zmiany
    * @return zwraca referencje zadanego kata typu double 
    */
    double &set_kat_zadany() { return kat_zadany; }


  

   /**
    * @brief Construct a new Obiekt Geom object
    * Metoda ustawiajaca glowne parametry obiektu do wyrysowania
    * @param sNazwaPliku_BrylaWzorcowa  przyjmuje wskaznik na lancuch znakow
    * @param sNazwaObiektu  przyjmuje wskaznik na lancuch znakow
    * @param KolorID id koloru
    */
    ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID);


   /**
    * @brief Funkcja dostepowa ID koloru
    * Metoda zwraca ID koloru
    * @return zwraca ID koloru
    */
    int WezKolorID() const { return _KolorID; }


   /**
    * @brief Funkcja WezNazweObiektu
    * Metoda pobierajaca nazwe obiektu
    * @return nazwa obiektu
    */
    const std::string &WezNazweObiektu() const { return _NazwaObiektu; }


   /**
    * @brief Funkcja WezNazwePliku_BrylaWysowana
    * 
    * Metoda pobierajaca nazwe pliku bryly rysowanej
    * @return strin nazwa pliku do rysowania
    */
    const std::string &WezNazwePliku_BrylaRysowana() const
    {
      return _NazwaPliku_BrylaRysowana;
    }



   /**
    * @brief Funkcja Przelicz_i_Zapisz_Wierzchołki
    * 
    *  Metoda przeliczajaca i zapisujaca wierzcholki
    * @param StrmWy referencja strumienia wyjsciowego
    * @param StrmWe referencja strumienia wejsciowego
    * @return true 
    * @return false 
    */
    bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);



   /**
    * @brief  Funkcja Przelicz_i_Zapisz_Wierzchołki
    * 
    * Metoda przeliczajaca i zapisujaca wierzcholki
    * 
    * @return true 
    * @return false 
    */
    bool Przelicz_i_Zapisz_Wierzcholki();



   /**
    * @brief Get the polozenie object
    * 
    * Metoda zwraca aktualne polozenie
    * @return  zwraca polozenie typu Wektor3D
    */
    Wektor3D get_polozenie() const { return przes; }


   /**
    * @brief Set the polozenie object
    * 
    * @return Metoda zwraca aktualne polozenie
    */
    Wektor3D &set_polozenie() { return przes; }


   /**
    * @brief Set the przes object
    * Metoda zwraca przesuniecie
    * @return zwraca referencje przesuniecia typu Wektor3D
    */
    Wektor3D &set_przes() { return przes; }
};

#endif
