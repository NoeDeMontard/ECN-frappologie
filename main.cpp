#include <conio.h>
#include <iostream>
#include "constantes.h"
#include "affichage.h"
using namespace std;



int main()
{
    int c;
    int encore = 1;
    while (encore == 1) {
        c = _getch();
        affichage(c, encore);
    }
    return 0;
}
