#include <conio.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "constantes.h"
#include "keyWrapper.h"
using namespace std;



int main()
{
    int c;
    bool encore;
    // Time mesurement
    vector<chrono::time_point<chrono::high_resolution_clock>> times;
    while (encore) {
        c = _getch();
        times.push_back(chrono::high_resolution_clock::now());
        string key = keyWrapper(c, encore);
        cout << key;
    }
    // Compture the times and key combinaisons
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente = times[0];
    for (int i = 0; i< times.size(); i++){
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = times[i];
        chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle-tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;
        // TODO Processing the duration - key pair combinaison
    }
    return 0;
}
