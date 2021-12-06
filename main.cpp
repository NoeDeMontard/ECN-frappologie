#include <conio.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "constantes.h"
#include "keyWrapper.h"
#include "password.h"
//#include "initializeTimeIntervals.h"// A file used for some tests
using namespace std;

#define DEBUG true

int main()
{
    // various vars
    int c;
    bool encore = true;
    //
    string passwordAttempt;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    vector<long long int> timeIntervals;
    //string ps = "c'est un coin de verdure ou coule une riviere\n";
    string ps = "c'est un coin\n"; // de verdure ou coule une riviere\n"; // TODO : const
    //vector<long long int> passwordTimeIntervals = initializeTimeIntervals(ps); // used for some tests
    //Password passwordControler(ps, passwordTimeIntervals);
    Password passwordControler("passwordFile.ignore");
    cout << ps;
    while (encore) {
        c = _getch();
        times.push_back(chrono::high_resolution_clock::now());
        string key = keyWrapper(c, encore);
        passwordAttempt += key;
        cout << key;
    }
    // Compture the times and key combinaisons
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente = times[0];
    for (int i = 0; i < times.size(); i++) {
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = times[i];
        //chrono::microseconds us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente); // nanoseconds, microseconds, milliseconds
        long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;        
        timeIntervals.push_back(us);
        cout << us << endl;
    }
    cout << (passwordControler.checkPasswordAttempt(passwordAttempt, timeIntervals) ? "Success" : "Failure") << endl;
    return 0;
}
