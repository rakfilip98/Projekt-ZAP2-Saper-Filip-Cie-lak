#include "gra.h"
using namespace std;
void wyswietlanie(Komorka **a, int w, int k, int poz_x,int poz_y)
{
    system ("cls");

    for (int i = 0; i<w; i++)
    {
        for (int j = 0; j<k; j++)
        {
            if (j==poz_x && i==poz_y)
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x02);
                if(a[j][i].wartosc==9)
                    cout<<"B";
                if(a[j][i].wartosc==0)
                    cout<<" ";
                if((a[j][i].wartosc!=0)&&(a[j][i].wartosc!=9))
                    cout<<a[j][i].wartosc;
            }
            else
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x07);



            if (a[j][i].odkryte==true)
                {
                    if (a[j][i].wartosc==0)
                        cout << " ";
                    else
                        cout << a[j][i].wartosc;

                }

                if (a[j][i].odkryte==false)
                    cout << "#";
            }
        }
     SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
        cout << endl;
    }

    cout << "\nWspolrzednie poprzedniego strzalu:\n";
    cout << "X: " << poz_x << endl;
    cout << "Y: " << poz_y << endl;
}


void odkrywanie(Komorka **a,int w, int k,int x1, int y1)
{
    if (x1<0 || x1>w-1) return;
    if (y1<0 || y1>k-1) return;
    if (a[x1][y1].odkryte==true) return;

    if(a[x1][y1].wartosc!=9 && a[x1][y1].odkryte==false)
        a[x1][y1].odkryte=true;

    if (a[x1][y1].wartosc!=0) return;

    odkrywanie(a,w,k,x1-1,y1-1);
    odkrywanie(a,w,k,x1-1,y1);
    odkrywanie(a,w,k,x1-1,y1+1);
    odkrywanie(a,w,k,x1+1,y1-1);
    odkrywanie(a,w,k,x1+1,y1);
    odkrywanie(a,w,k,x1+1,y1+1);
    odkrywanie(a,w,k,x1,y1-1);
    odkrywanie(a,w,k,x1,y1);
    odkrywanie(a,w,k,x1,y1+1);
}

bool sprawdzanie(Komorka **a, int w, int k,int ilosc)
{
    int miny = 0;
    for (int i = 0; i<w; i++)
    {
        for (int j = 0; j<k; j++)
        {
            if(a[i][j].odkryte==false)
                miny++;
        }
    }
    if (miny==ilosc) return true;
    return false;
}

int strzelanie(Komorka **a, int w, int k, int poz_x, int poz_y,int &koniec)//int o_poz_x,int o_poz_y,int koniec)
{

    cout<<"Podaj wspolrzedne strzalu:";
        cin>>poz_x>>poz_y;
        if (a[poz_x][poz_y].wartosc==9)
            koniec=2;



        odkrywanie(a,w,k,poz_x, poz_y);
        wyswietlanie(a,w,k,poz_x,poz_y);
        return 3;



}
