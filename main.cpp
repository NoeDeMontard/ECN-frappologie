#include <conio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include "constantes.h"
#include "keyWrapper.h"
#include "password.h"
#include "debug.h"
//#include "initializeTimeIntervals.h"// A file used for some tests
using namespace std;

void moyenneEcartType(vector<vector<long long int>> data, vector<long long int> moyennes, vector<long long int> ecartsType) {
    int nbrEssais = data.size();
    int nbrTouches = data[0].size();

    for (int i = 0; i < nbrEssais; i++) {
        for (int j = 0; j < nbrTouches; j++) {
            moyennes[j] += data[i][j];
            ecartsType[j] += data[i][j] * data[i][j];
        }
    }
    for (int j = 0; j < nbrTouches; j++) {
        moyennes[j] /= nbrEssais;
        ecartsType[j] /= nbrEssais;
        ecartsType[j] -= moyennes[j];
    }
}

void registerPasswordTimes(const string passwordFilePath) {
    // TODO : verifier qu'on ecrase pas un autre utilisateur
    // Various vars
    int c;
    bool encore = true;
    int nbrDataPoints = 5;

    // Password and time related variables
    vector<vector<long long int>> timeIntervalsMeasure(nbrDataPoints);


    ////Reading the password from the file

    //fstream passwordFile(passwordFilePath, ios::in);
    string ps;
    //getline(passwordFile, ps);
    //cout << "Le mot de passe est le suivant, veuillez le taper une premiere fois :" << endl;
    //cout << ps << endl;
    //passwordFile.close();

    cout << "Merci de rentrer le mot de passe (non secret)" << endl;
    while (encore) {
        c = _getch();
        string key = keyWrapper(c, encore);
        ps += key;
        cout << key;
    }
    cout << endl;
    //Rewriting the password and the data in the file

    fstream passwordFile2(passwordFilePath, ios::out);
    passwordFile2 << ps << endl;

    //TODO : afficher 1 seul fois le mot de passe à taper
    int j = 0;
    while (j < nbrDataPoints) {
        string passwordAttemptMeasure;
        vector<chrono::time_point<chrono::high_resolution_clock>> timesMeasure; // To get the user data
        encore = true;
        cout << "Le mot de passe est le suivant, veuillez le taper :" << endl;
        cout << ps << endl;

        // Getting the times at each key pressed
        while (encore) {
            c = _getch();
            timesMeasure.push_back(chrono::high_resolution_clock::now());
            string key = keyWrapper(c, encore);
            passwordAttemptMeasure += key;
            cout << key;
        }
        cout << endl;
        encore = true;
        
        if (ps == passwordAttemptMeasure) {
            // Calculating the intervals between each key pressed
            chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente = timesMeasure[0];
            for (int i = 0; i < timesMeasure.size(); i++) {
                chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = timesMeasure[i];
                long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
                tempsTouchePrecedente = tempsToucheActuelle;
                timeIntervalsMeasure[j].push_back(us);
            }
            j += 1;
        }
        else {
            cout << "Le mot de passe rentre est errone, veuillez reessayer" << endl;
        }
        
    }
    vector<long long int> moyennes(timeIntervalsMeasure.size(), 0);
    vector<long long int> ecartsType(timeIntervalsMeasure.size(), 0);
    //vector<long long int> moyennes;
    //vector<long long int> ecartsType;
    moyenneEcartType(timeIntervalsMeasure, moyennes, ecartsType);

    // Writing the data in the file
    if (passwordFile2) {
        for (int i = 0; i < moyennes.size(); i++) {
            passwordFile2 << moyennes[i] << endl;
        }
    }
    passwordFile2.close();
}

bool testPasswordTimes(const string passwordFilePath) {
    // Various vars
    int c;
    bool encore = true;

    // Password and time related variables

    string passwordAttempt;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente;
    vector<long long int> timeIntervals;


    Password passwordControler(passwordFilePath);


    cout << endl << "Veuillez taper le mot de passe pour l'authentification :" << endl;
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
    cout << endl;

    // Compture the times and key combinaisons
    tempsTouchePrecedente = times[0];
    for (int i = 0; i < times.size(); i++) {
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = times[i];
        //chrono::microseconds us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente); // nanoseconds, microseconds, milliseconds
        long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;
        timeIntervals.push_back(us);
        if (DEBUG >= 2) { cout << us << endl; }
    }
    bool accessGranted = passwordControler.checkPasswordAttempt(passwordAttempt, timeIntervals);
    return accessGranted;
}



int main()
{
    const string passwordFilePath = "passwordFile.ignore";

    //vector<long long int> moyennes(nbrTouches, 0);
    //vector<long long int> ecartsType(nbrTouches, 0);
    
    cout << "Welcome in our 'Frappologie' authentification" << endl;
    cout << "Developed by Noe de Montard & Clement Naudet" << endl;
    cout << "Would you like to register a new user (r) or to authentificate (A) ?" << endl;
    string choice;
    cin >> choice;
    if (choice == "r" || choice == "R") {
        string user;
        cout << "Enter user name" << endl;
        cin >> user;
        // THE PASSWORD FILE INITIALISATION METHOD
        registerPasswordTimes(user + "." +  passwordFilePath); // TODO : excape folder navigation capability
    }
    else {
        string user;
        cout << "Enter user name" << endl;
        cin >> user;
        // THE PASSWORD CHECKING METHOD
        bool accessGranted = testPasswordTimes(user + "." + passwordFilePath); // TODO : excape folder navigation capability

        cout << ( accessGranted ? "Success" : "Failure") << endl;
    }


    return 0;
}
