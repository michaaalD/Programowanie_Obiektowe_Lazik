#include "Scena.hh"
#define LICZBA_PROBEK 10



/**
     *  @brief Inicjalizacja lacza
     *
     */
void Scena::Inicjalizuj_Lacze()
{
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
    Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
    Lacze.UstawZakresZ(-0, 90);
    Lacze.UstawRotacjeXZ(40, 60); // Tutaj ustawiany jest widok
    Lacze.Inicjalizuj();          // Tutaj startuje gnuplot.
}


/**
     *  @brief Konstruktor sceny
     *  
     */

Scena::Scena()
{
    Wektor3D _przes,_skala,skala_regolitu;
    std::string regolit[] = {"Coulettes","Salette","Dourbes","Robine","Quartier","Bellegarde","Montdenier","Montagnac","Guillaumes","Roubion"};

    _przes[0] = 60;          
    _przes[1] = 60;
    
    _skala[0] = 20;           //ustawienie skali dla lazikow
    _skala[1] = 20;
    _skala[2] = 10;

    skala_regolitu[0] = 4;    // ustawienie skali dla regolitu
    skala_regolitu[1] = 4;
    skala_regolitu[2] = 2;


    Inicjalizuj_Lacze();
    Inicjalizuj_PowierzchnieMarsa(Lacze);
    
    std::shared_ptr<Lazik> Ob1 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "SFR", Kolor_JasnoNiebieski);
    Ob1->set_przes() = _przes;
    Ob1->set_skala() = _skala;
    lista_lazikow.push_back(Ob1);       //dodanie do listy

    std::shared_ptr<Lazik> Ob2 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony);
    Ob2->set_skala() = _skala;
    lista_lazikow.push_back(Ob2);       //dodanie do listy

    std::shared_ptr<Lazik> Ob3 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony);
    _przes[0] = -60;
    _przes[1] = -60;

    Ob3->set_przes() = _przes;
    Ob3->set_skala() = _skala;
    lista_lazikow.push_back(Ob3);

    aktualny_lazik = Ob1;               //ustawienie  SFR jako aktualnego lazika

    for(int i = 0; i < 10; i++)
    {
        _przes[0] = (rand() % 180) - 90;  // polozenie lazika jako losowa liczba od 0 do 180 - 90
        _przes[1] = (rand() % 180) - 90;
        
        std::shared_ptr<ProbkaRegolitu> P = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat", regolit[i].c_str(),Kolor_JasnoNiebieski);
        lista_lazikow.push_back(P);       //dodanie probki do listy
        P->set_polozenie() = _przes;
        P->set_skala() = skala_regolitu;  // ustawienie mniejszej skali dla regolitu
        
    }
    DodajDoListyRysowania();
    Lacze.Rysuj();
}


    /**
     * @brief Funkcja realizujaca ruch lazika
     * 
     * @param kat kat o jaki ma sie obrocic lazik
     * @param droga  droga jaka ma przejechac lazik
     * @param szybkosc szybkosc z jaka ma przejechac lazik
     */
void Scena::Ruch(double kat, double droga, double szybkosc)
{
    aktualny_lazik->set_Odleglosc() = droga;
    aktualny_lazik->set_szybkosc() = szybkosc;
    aktualny_lazik->jazda(Lacze, aktualny_lazik, lista_lazikow);
    aktualny_lazik->set_kat() = kat;
    aktualny_lazik->Obrot(Lacze);
}


/**
 * @brief Funkcja realizujaca testowy przejazd lazika
 * Metoda wykonuje przejazd w ksztalcie "osemki"
 */
void Scena::PrzejazdTestowy()
{
    aktualny_lazik->set_Odleglosc() = 1.0;
    aktualny_lazik->set_szybkosc() = 1.0;
    aktualny_lazik->set_kat() = 1.0;
    for(int i=0; i < 360; i++)
    {
        aktualny_lazik->jazda(Lacze, aktualny_lazik, lista_lazikow);
        aktualny_lazik->Obrot(Lacze);
    }

    aktualny_lazik->set_Odleglosc()=1.0;
    aktualny_lazik->set_szybkosc()=1.0;
    aktualny_lazik->set_kat()=(-1.0);
    
    for(int i=0; i < 360; i++)
    {
        aktualny_lazik->jazda(Lacze, aktualny_lazik, lista_lazikow);
        aktualny_lazik->Obrot(Lacze);
    }
}


/**
     *  @brief Funkcja umozliwiajaca wybor lazika
     *
     *  @param n - zmienna do wyboru lazika
     *  Metoda wybiera jeden lazik i ustawia go jako aktualny
     */
void Scena::wybor(int n)
{
    int j = 0;
    if(n >3 || n < 0)
    {
        std::cout << "Niepoprawna opcja wyboru Lazika" << std::endl;
        std::cout << "Dostepny lazik o numerach 1-3" << std::endl;
    }
    else{
        std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin();
        for (; j < n; ++j, ++i)
        {
        aktualny_lazik = std::dynamic_pointer_cast<Lazik>(*i);       //rzutowanie share_ptr
        }
    }
}


/**
     *  @brief Funkcja dodajaca do listy rysowania
     *
     *  Metoda dodaje laziki do rysowania
     */
void Scena::DodajDoListyRysowania()
{
    PzG::InfoPlikuDoRysowania *wInfoPliku;
    for(std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
    {
        wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
        wInfoPliku->ZmienKolor((*i)->WezKolorID());
    }
}


/**
     *  @brief Funkcja rysujaca laziki
     *
     *  Metoda rysuje laziki
     */
void Scena::Rysuj()
{
    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
    {
        (*i)->Przelicz_i_Zapisz_Wierzcholki();
    }
    Lacze.Rysuj();
}


/**
     *  @brief Funkcja wypiiujaca lazik
     *
     *  Metoda wypisuje aktualny laziki
     */

void Scena::wypisz()
{
    int j = 0;
    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
    {
        ++j;
        if(j <= 3){
        std::cout << "Lazik nr "<< j << '-'<< (*i)->WezNazweObiektu() << "  | Polozenie: " << (*i)->get_polozenie() << std::endl;
        /*if(j == 3){
            std::cout << "***Lista Probki Regolitu***" << std::endl;
            }
        }
        else if(j > 3)                  
        {
            std::cout << "Nr    "<< j << "- "<< (*i)->WezNazweObiektu() << " |  Polozenie: " << (*i)->get_polozenie()  << std::endl;
        }
        */
     }
    }
}

void Scena::wypisz_Probki_Regolitu()
{
    int j = 0;
    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
    {
        ++j;
        if (j > 3)
            std::cout << j-3 << "   Probka " << (*i)->WezNazweObiektu() << " |  Polozenie:    " << (*i)->get_polozenie()  << std::endl;
    }
}

void Scena::ZbierzProbke()
{
    if (aktualny_lazik->WezNazweObiektu() == "SFR")
    {
        for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_lazikow.begin(); i != lista_lazikow.end(); ++i)
        {
            if (aktualny_lazik->CzyKolizja(*i) == PrzejazdNadProbka)
            {
                aktualny_lazik->dodaj_probke(std::dynamic_pointer_cast<ProbkaRegolitu>(*i));
                Lacze.UsunNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
                lista_lazikow.erase(i);
                Rysuj();
                Lacze.Rysuj();
                std::cout << "Probka zebrana" << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "Tylko Lazik SFR może zbierac probki!!!" << std::endl;
    }
}

