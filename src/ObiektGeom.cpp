#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"

/**
 * @brief Virtualna metoda sprawdzajaca kolizje
 * 
 * @return TypKolizji zwraza typ kolizji
 */
TypKolizji ObiektGeom::CzyKolizja()
{
  return BrakKolizji;
}

/**
 * @brief Metoda obliczjaca czy obrysy sie przecinaja
 * 
 * @param obrys_obiektu obrys przeszkody
 * @return true jesli sie przecinaja
 * @return false jesli sie nie przecinaja
 */
bool ObiektGeom::przeciecie_wspolrzednych(ObrysXY obrys_obiektu)
{
    Wektor2D gp1 = obrys.setGornyPrawy();            //obrys obiektu 
    Wektor2D dl1 = obrys.setDolnyLewy();

    Wektor2D gp2 = obrys_obiektu.setGornyPrawy();    // obrys przeszkody
    Wektor2D dl2 = obrys_obiektu.setDolnyLewy();

    if( ( dl1[0] > dl2[0] )&& ( dl1[0] < gp2[0] ) && ( dl1[1] > dl2[1] ) && ( dl1[1] < gp2[1]) )
    {
      return true;
    }
    if( (gp1[0] > dl2[0] ) && ( gp1[0] < gp2[0] ) && ( gp1[1] > dl2[1] ) && ( gp1[1] < gp2[1] ))
    {
      return true;
    }
    if( (dl1[0] > dl2[0] ) && ( dl1[0] < gp2[0] ) && ( gp1[1] > dl2[1] ) && ( gp1[1] < gp2[1] ) ) 
    {
      return true;
    }
    if( (gp1[0] > dl2[0] ) && ( gp1[0] < gp2[0] ) && ( dl1[1] > dl2[1] ) &&  ( dl1[1] < gp2[1] ) ){
      return true;
    }
    
    return false;
    
}

/*
void ObiektGeom::SprawdzTyp()
{
  ObiektGeom *Ob1 = new ObiektGeom();
  
  if(dynamic_cast<ObiektGeom*>(this) == Ob1)
  {
    std::cout << "Obiekt nie jest typu ObiektGeom" << std::endl;
  }
  else {
    std::cout << "Obiekt jest typu ObiektGeom" << std::endl;

  }

}*/


/**
 * @brief Construct a new Obiekt Geom:: Obiekt Geom object
 * 
 * @param sNazwaPliku_BrylaWzorcowa przyjmuje wskaznik na lancuch znakow
 * @param sNazwaObiektu przyjmuje wskaznik na lancuch znakow
 * @param KolorID id koloru
 */
ObiektGeom::ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID) : _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{

  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
  kat_zadany = 0;
  for (int i = 0; i < 3; ++i)
  {
    rotacja[i][i] = 1;
  }
}



/**
 * @brief Metoda przeliczajaca i zapisujaca wierzcholki obiektu
 * 
 * @param StrmWy referencja strumienia wyjsciowego
 * @param StrmWe referencja strumienia wejsciowego
 * @return true 
 * @return false 
 */
bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe)
{
  int Indeks_Wiersza = 0;

  StrmWe >> set_wspolrzedne();

  if (StrmWe.fail())
    return false;

  do
  {
    set_wspolrzedne() = (get_wspolrzedne() & get_skala()) + przes;
    StrmWy << get_wspolrzedne() << std::endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << std::endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> set_wspolrzedne();

  } while (!StrmWe.fail());

  if (!StrmWe.eof())
    return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}


/**
 * @brief unkcja Przelicz_i_Zapisz_Wierzchołki
 * Metoda przeliczajaca i zapisujaca wierzcholki
 * @return true 
 * @return false 
 */
bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  std::ifstream StrmWe(_NazwaPliku_BrylaWzorcowa);
  std::ofstream StrmWy(_NazwaPliku_BrylaRysowana);

  std::vector<double> x;
  std::vector<double> y;

  if (!(StrmWe.is_open() && StrmWy.is_open()))
  {
    std::cerr << std::endl
         << "Nie mozna otworzyc jednego z plikow:" << std::endl
         << "    " << _NazwaPliku_BrylaWzorcowa << std::endl
         << "    " << _NazwaPliku_BrylaRysowana << std::endl
         << std::endl;
    return false;
  }

  int Indeks_Wiersza = 0;

  StrmWe >> set_wspolrzedne();

  if (StrmWe.fail())
  {
    return false;
  }
 
  do
  {
    set_wspolrzedne() = rotacja * get_wspolrzedne();
    set_wspolrzedne() = (get_wspolrzedne() & get_skala()) + przes;
    StrmWy << get_wspolrzedne() << std::endl;
    x.push_back(get_wspolrzedne()[0]);
    y.push_back(get_wspolrzedne()[1]);
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << std::endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> set_wspolrzedne();

  } while (!StrmWe.fail());

  obrys.setDolnyLewy()[0]=*std::min_element(x.begin(), x.end()) - (0.05 * get_skala()[0]);
  obrys.setDolnyLewy()[1]=*std::min_element(y.begin(), y.end()) - (0.05 * get_skala()[1]);
  
  obrys.setGornyPrawy()[0]=*std::max_element(x.begin(), x.end()) + (0.05 * get_skala()[0]);
  obrys.setGornyPrawy()[1]=*std::max_element(y.begin(), y.end()) + (0.05 * get_skala()[1]);

  if (!StrmWe.eof())
  {
    return false;
  }
  kat_zadany = 0;
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
