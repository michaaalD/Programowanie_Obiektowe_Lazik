#include "Lazik.hh"



  TypKolizji Lazik::CzyKolizja(std::shared_ptr<ObiektGeom> ob)
  {
    if (przeciecie_wspolrzednych((*ob).getObrys()))
    {
      if(ob->SprawdzTyp() == 'P'){
        return PrzejazdNadProbka;
      }
      else if(ob->SprawdzTyp() == 'L'){
        return Kolizja;
      }
    }
    return BrakKolizji;
  }
  
  void Lazik::dodaj_probke(std::shared_ptr<ProbkaRegolitu> ob)
  {
    lista_probek_regolitu.push_back(ob);
  }
  /**
   *  @brief Funkcja obrotu o dany kat
   *
   * Metoda do zmiany kata o 1
   */
  void Lazik::obrot()
  {
    KatOrientacji += 1;
    set_rotacja() = Rotacja(KatOrientacji);
    if (KatOrientacji == 360)
    {
      KatOrientacji = 0;
    }
  }


  /**
   *  @brief Funkcja obrotu o ujemne katy
   *
   * Metoda do zmiany kata o 1
   */
  void Lazik::_obrot()
  {
    KatOrientacji -= 1;
    set_rotacja() = Rotacja(KatOrientacji);
    if (KatOrientacji == -360)
    {
      KatOrientacji = 0;
    }
  }


  /**
   *  @brief Funkcja jazdy lazika
   *  Metoda realizujaca przemieszczenie lazika w linii prostej
   * 
   *  @param[in] lacze - referencja zbioru plikow do gnuplota
   */
  void Lazik::jazda(PzG::LaczeDoGNUPlota &lacze,std::shared_ptr<Lazik> aktualny_lazik, std::list<std::shared_ptr<ObiektGeom>> &lista_lazikow)
  {
    Wektor3D V;
    V[1] = Szybkosc;
    if(Szybkosc>0){
    for (double i = 0; i < Odleglosc; i += Szybkosc)
    {
      for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
      {
        if ( aktualny_lazik != (std::dynamic_pointer_cast<Lazik>(*i)))
        {
          if (CzyKolizja((*i)) == Kolizja)
          {
            std::cout << std::endl
                      << "***Kolizja! Lazik nie moze przejechac***" << std::endl;
            return;
          }
        }
      }
      set_polozenie() = get_polozenie() + (Rotacja(KatOrientacji) * V);
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }
    }
  }


 /**
   *  @brief Funkcja obrotu lazika
   *  Metoda realizujaca przemieszczenie lazika pod danym katem
   * 
   *  @param[in] lacze - referencja zbioru plikow do gnuplota
   */
  void Lazik::Obrot(PzG::LaczeDoGNUPlota &lacze)
  {
    for (int i = 0; i < Kat; ++i)
    {
      obrot();
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }
    for (int i = Kat; i < 0; ++i)
    {
      _obrot();
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }
  }
  
  

