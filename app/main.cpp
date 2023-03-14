#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Scena.hh"
#include "typeinfo"


int main()

{
  /*
  ProbkaRegolitu *L1 = new ProbkaRegolitu();
  ObiektGeom *Ob = L1;
  Ob->SprawdzTyp();
  */
 /*
  Lazik *L1 = new Lazik();

  Lazik *L2 = dynamic_cast<Lazik*>(L1);
  
  if(!L2)
{
  std::cout << "to nie jest obiekt child" << std::endl;
}  
else{
  std::cout << "obiekt dziedziczy"<< std::endl;
}
*/
  
  Scena scena;
  srand (time(NULL));
  scena.Rysuj();
  
  int nr;
  double kat_usera;
  double droga_usera; 
  double szybkosc_usera;
  
  char znak;

/*
  std::cout << std::endl;
  std::cin >> znak;
  std::cout << std::endl;


  std::cout << scena.polozenie_akt();
  scena.Ruch(50,10,1);
  std::cout << scena.polozenie_akt();
  scena.Ruch(1,0,0);
  std::cout << scena.polozenie_akt();
*/

  
  while (znak != 'q')
  {
    std::cout << "**************************" << std::endl;
    std::cout << "< d- jedz                >" << std::endl;
    std::cout << "< o- obroc lazik o kat   >" << std::endl;
    std::cout << "< w- wybor lazika        >" << std::endl;
    std::cout << "< l- lista probek        >" << std::endl;
    std::cout << "< t- test osemka         >" << std::endl;
    std::cout << "< c- zbierz probke       >" << std::endl;
    std::cout << "< m- menu                >" << std::endl;
    std::cout << "< q- wyjdz z programu    >" << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << "Wybor opcji: ";

    std::cout << std::endl;
    std::cin >> znak;
    std::cout << std::endl;
    
    switch (znak)
    {
      case 'd':
        {
          std::cout << "Uzywany lazik" << std::endl;
          std::cout << "Nazwa: " << scena.nazwa_akt() << std::endl;
          std::cout << "Polozenie lazika x,  y,  z: " <<  scena.polozenie_akt() << std::endl;
          std::cout << "Podaj odleglosc jaka ma przejechac lazik" << std::endl;
          std::cin >> droga_usera;
          std::cout << std::endl;
          std::cout << "Podaj szybkosc:" << std::endl;
          std::cin >> szybkosc_usera;
          std::cout << std::endl;
          scena.Ruch(0, droga_usera, szybkosc_usera);
          std::cout << "Polozenie lazika x,  y,  z: " << scena.polozenie_akt() << std::endl;
          std::cout << "Aktualny kat: " << scena.kat_aktualny() << std::endl;
          std::cout << "Wybor opcji: "<< std::endl;
          break;
        }
      case 'o':
        {
          std::cout << "Uzywany lazik" << std::endl;
          std::cout << "Nazwa: " << scena.nazwa_akt() << std::endl;
          std::cout << "Polozenie lazika x,  y,  z: " << '(' << scena.polozenie_akt() << ')' << std::endl;
          std::cout << "Podaj kat: ";
              
          std::cin >> kat_usera;
          std::cout << std::endl;
          scena.Ruch(kat_usera, 0, 0);
          std::cout << "Polozenie lazika x,  y,  z: " << '(' << scena.polozenie_akt() << ')' << std::endl;
          std::cout << "Aktualny kat: " << scena.kat_aktualny() << std::endl;
          std::cout << "Wybor opcji:"<< std::endl;
          break;
        }
      case 'w':
        {
          scena.wypisz();
          std::cout << "Wybor opcji:";
          std::cin >> nr;
          if(typeid(nr) == typeid(int) || typeid(nr) == typeid(float) || typeid(nr) == typeid(double))
          {
            std::cout << std::endl;
            scena.wybor(nr);
            std::cout << "Uzywany lazik" << std::endl;
            std::cout << "Nazwa: " << scena.nazwa_akt() << std::endl;
            std::cout << "Polozenie lazika x,  y,  z: " << '(' << scena.polozenie_akt() << ')' << std::endl;
            std::cout << "Wybor opcji:"<< std::endl;
          }
          else{
            std::cout << "Niepoprawna wartosc kata" << std::endl;
          }
          break;
        }

      case 'l':
        {
          scena.wypisz_Probki_Regolitu();
          std::cout << "Wybor opcji:" << std::endl;
          break;
        }
      case 't':
        {
          
          //std::cout << "Test Lazika " << scena.nazwa_akt() << std::endl;
          //scena.Ruch(180,0,0);
          //scena.Ruch(-90,0,0);
          //for(int i=0; i <360; i++){
          //scena.Ruch(0,1,1);
          //scena.Ruch(1,0,0);
          //}
          //for(int i=0; i < 360; i++){
           // scena.Ruch(0,1,1);
           // scena.Ruch(-1,0,0);
          //}
          //std::cout << "Koniec testu" << std::endl;
          //std::cout << "Wybor opcji:";
          
          std::cout << "Test Lazika " << scena.nazwa_akt() << std::endl;
          std::cout << "Polozenie lazika x,  y,  z: " << '(' << scena.polozenie_akt() << ')' << std::endl;
          scena.PrzejazdTestowy();
          std::cout << "Koniec testu" << std::endl;
          std::cout << "Polozenie lazika x,  y,  z: " << '(' << scena.polozenie_akt() << ')' << std::endl;
          std::cout << "Wybor opcji:" << std::endl;
          break;
        }
      case 'c':
        {
          scena.ZbierzProbke();
          std::cout << "Wybor opcji:" << std::endl;
          break;
        }
      case 'm':
        {
          std::cout << "**************************" << std::endl;
          std::cout << "< d- jedz                >" << std::endl;
          std::cout << "< o- obroc lazik o kat   >" << std::endl;
          std::cout << "< w- wybor lazika        >" << std::endl;
          std::cout << "< l- lista probek        >" << std::endl;
          std::cout << "< t- test osemka         >" << std::endl;
          std::cout << "< c- zbierz probke       >" << std::endl;
          std::cout << "< m- menu                >" << std::endl;
          std::cout << "< q- wyjdz z programu    >" << std::endl;
          std::cout << "**************************" << std::endl;
          std::cout << "Wybor opcji: ";
          break;
        }
      case 'q':
        {
          std::cout << "Koniec pracy programu" << std::endl;
          break;
        }
      default:
        {
          if(znak != 'd' && znak != 't' && znak != 'm' && znak != 'o' && znak != 'w' && znak != 'c'){
            std::cout << "Niepoprawna opcja!" << std::endl;}
          break;
        }
    }
  }
  
 
}
