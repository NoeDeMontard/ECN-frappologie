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
    
    // Password and time related variables
    string passwordAttempt;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    vector<long long int> timeIntervals;
    // Old version of getting the values of the password and time related variables
    //const string ps = "c'est un coin de verdure ou coule une riviere\n";
    //const string ps = "c'est un coin\n"; // de verdure ou coule une riviere\n";
    //cout << ps;

    //vector<long long int> passwordTimeIntervals = initializeTimeIntervals(ps); // used for some tests
    //Password passwordControler(ps, passwordTimeIntervals);
    // New method
    Password passwordControler("passwordFile.ignore");
    //string ps = passwordControler.getPassword();
    passwordControler.printPassword();

    // The password and times capture
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
    bool accessGranted = passwordControler.checkPasswordAttempt(passwordAttempt, timeIntervals);
    cout << ( accessGranted ? "Success" : "Failure") << endl;
    return 0;
}
