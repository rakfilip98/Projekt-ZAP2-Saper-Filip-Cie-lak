#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "plansza.h"
#include "gra.h"

using namespace std;













int main(){
    int x2,y2,liczba2,ilosc2=0,koniec2=0;
    int wiersze,kolumny;
    int wspolrzedna_x=0 , wspolrzedna_y=0 ;
    Komorka **tablica;

    srand(time(0));
    cout << "Gra saper autorstwa Filip Cieslak" << endl;
    cout<<"Podaj rozmiar planszy"<<endl;
    cin>>wiersze;
    //cout<<"Podaj ile kolumn ma zawierac plansza"<<endl;
    //cin>>kolumny;
    kolumny=wiersze;//Narazie na kwadratowej, bo w prostokatnej tablicy czasem wyskakuja bledy
    cout<<endl<<endl<<endl;
    tablica=new Komorka*[wiersze];
    for(int i=0;i<wiersze;i++){
        tablica[i]=new Komorka[kolumny];
    }
    tworzenie(tablica,wiersze,kolumny);
    //drukujtablice(tablica,wiersze,kolumny);
    do{
    cout<<"Podaj ilosc min, ktora bedzie wystepowala na planszy"<<endl;
    cin>>liczba2;
    } while(liczba2>(wiersze*kolumny));
    ilosc2=liczba2;

    ustawianiebomb(tablica,wiersze,kolumny,x2,y2,liczba2);
    //drukujtablice(tablica,wiersze,kolumny);

    while(koniec2==0)
    {
        Sleep(60);
        strzelanie(tablica,wiersze,kolumny, wspolrzedna_x,wspolrzedna_y,koniec2);
        if(tablica[wspolrzedna_x][wspolrzedna_y].wartosc==9)
            koniec2=2;

        if (sprawdzanie(tablica,wiersze,kolumny,ilosc2)==true) koniec2=1;
    }

    if (koniec2==1) cout << "Wygrana"<<endl;
    if (koniec2==2) cout << "Mina! Porazka"<<endl;
    system ("pause >nul");
    for(int i=0;i<wiersze;i++){
        delete [] tablica[i];
    }
    delete []tablica;




    return 0;
}

