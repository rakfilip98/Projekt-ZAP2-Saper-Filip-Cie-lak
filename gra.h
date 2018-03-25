#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "plansza.h"

void wyswietlanie(Komorka **a, int w, int k, int poz_x,int poz_y);
void odkrywanie(Komorka a,int w, int k,int x1, int y1);
bool sprawdzanie(Komorka **a, int w, int k,int ilosc);
int strzelanie(Komorka **a, int w, int k, int poz_x, int poz_y, int &koniec);//int o_poz_x,int o_poz_y,int koniec);

#endif // GRA_H
