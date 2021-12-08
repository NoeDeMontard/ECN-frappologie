#include <conio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include "constantes.h"
#include "keyWrapper.h"
#include "password.h"
#include "initializeTimeIntervals.h"// A file used for some tests
using namespace std;

#define DEBUG true

int main()
{
    // various vars
    int c;
    bool encore = true;
    string passwordAttempt;
    string passwordAttemptMeasure;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    vector<chrono::time_point<chrono::high_resolution_clock>> timesMeasure; // To get the user data
    vector<long long int> timeIntervals;
    vector<long long int> timeIntervalsMeasure;

    //Reading the password from the file

    fstream passwordFile("passwordFile.ignore", ios::in);
    string ps;
    getline(passwordFile, ps);
    ps += "\n";
    cout << "Le mot de passe est le suivant, veuillez le taper une première fois :" << endl;
    cout << ps;
    passwordFile.close();

    //Rewriting the password and the data in the file

    fstream passwordFile2("passwordFile.ignore", ios::out);
    passwordFile2 << ps << endl;
    //Getting the times at each key pressed
    while (encore) {
        c = _getch();
        timesMeasure.push_back(chrono::high_resolution_clock::now());
        string key = keyWrapper(c, encore);
        passwordAttemptMeasure += key;
        cout << key;
    }
    encore = true;
    //Calculating the intervals between each key pressed
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente = timesMeasure[0];
    for (int i = 0; i < timesMeasure.size(); i++) {
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = timesMeasure[i];
        long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;
        timeIntervalsMeasure.push_back(us);
    }
    //Writing the data in the file
    if (passwordFile2) {
        for (int i = 0; i < timesMeasure.size(); i++) {
            passwordFile2 << timeIntervalsMeasure[i] << endl;
        }
    }
    passwordFile2.close();

    //string ps = "c'est un coin de verdure ou coule une riviere\n";
    //string ps = "c'est un coin\n"; // de verdure ou coule une riviere\n"; // TODO : const
    //vector<long long int> passwordTimeIntervals = initializeTimeIntervals(ps); // used for some tests
    //Password passwordControler(ps, passwordTimeIntervals);
    Password passwordControler("passwordFile.ignore");
    cout << endl << "Veuillez taper le mot de passe une seconde fois pour l'authentification :" << endl;
    while (encore) {
        c = _getch();
        times.push_back(chrono::high_resolution_clock::now());
        string key = keyWrapper(c, encore);
        passwordAttempt += key;
        cout << key;
    }
    // Compture the times and key combinaisons
    tempsTouchePrecedente = times[0];
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
