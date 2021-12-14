#include <conio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <filesystem>
#include "constantes.h"
#include "keyWrapper.h"
#include "password.h"
#include "debug.h"
//#include "initializeTimeIntervals.h"// A file used for some tests
using namespace std;

void moyenneEcartType(vector<vector<long long int>> data, vector<long long int>& moyennes, vector<long long int>& ecartsType) {
    int nbrEssais = data.size();
    int nbrTouches = data[0].size();

    for (int i = 0; i < nbrEssais; i++) {
        for (int j = 0; j < nbrTouches; j++) {
            if(DEBUG >= 3){cout << "data[i][j]" << data[i][j] << endl;}
            moyennes[j] += data[i][j];
            ecartsType[j] += data[i][j] * data[i][j];
        }
    }
    for (int j = 0; j < nbrTouches; j++) {
        if(DEBUG >= 3){cout << "moyennes[j] initial " << moyennes[j]  << endl;}
        if(DEBUG >= 3){cout << "ecartsType[j] initial " << ecartsType[j]  << endl;}
        moyennes[j] /= nbrEssais;
        ecartsType[j] /= nbrEssais;
        ecartsType[j] -= moyennes[j];
        ecartsType[j] = sqrt (ecartsType[j]);
        if(DEBUG >= 3){cout << "moyennes[j] " << moyennes[j]  << endl;}
        if(DEBUG >= 3){cout << "ecartsType[j] " << ecartsType[j]  << endl;}
    }
}

bool testPasswordTimes(const string passwordFilePath); // TODO : réorganiser pour éviter d'avoir besoin de cette ligne

void registerPasswordTimes(const string passwordFilePath) {
    // Check if user exist, if he does, ask for if the user whant to overwrite the old password take (with a password verification in case of overwriting)
    if (filesystem::exists(passwordFilePath)) {
        cout << "L'utilisateur existe deja" << endl;
        cout << "Voulez vous re-enregistrer le mot de passe ? (o/N)" << endl;
        string changePasswordInput;
        cin >> changePasswordInput;
        if (changePasswordInput != "o" && changePasswordInput != "O") {
            return;
        } else {
            bool accessGranted = testPasswordTimes(passwordFilePath); // TODO : excape folder navigation capability
            if (!accessGranted) {
                cout << "Echec de l'authentification" << endl;
                cout << "L'enregistrement a echoue" << endl;
                return;
            }
        }
    }

    // User should be registered (again)

    // Various vars
    int c; // the current character code
    bool encore = true; // get a new character
    int nbrDataPoints = 5; // number of password take

    // Password and time related variables
    vector<vector<long long int>> timeIntervalsMeasure(nbrDataPoints);


    // Reading the password to use
    string ps;
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
                if(DEBUG >= 3){cout << us << endl;}
                timeIntervalsMeasure[j].push_back(us);
            }
            j += 1;
        }
        else {
            cout << "Le mot de passe rentre est errone, veuillez reessayer" << endl;
        }
        
    }

    vector<long long int> moyennes(timeIntervalsMeasure[0].size(), 0);
    vector<long long int> ecartsType(timeIntervalsMeasure[0].size(), 0);

    moyenneEcartType(timeIntervalsMeasure, moyennes, ecartsType);

    // Writing the data in the file
    if (passwordFile2) {
        for (int i = 0; i < moyennes.size(); i++) {
            if(DEBUG >= 3){cout << "moyennes[i] " << moyennes[i]  << endl;}
            passwordFile2 << moyennes[i] << endl;
        }
        passwordFile2 << endl;
        for (int i = 0; i < ecartsType.size(); i++) {
            if(DEBUG >= 3){cout << "ecartsType[i] " << ecartsType[i]  << endl;}
            passwordFile2 << ecartsType[i] << endl;
        }
        cout << "Enregistrement effectue avec succes" << endl;
    }
    passwordFile2.close();
}

bool testPasswordTimes(const string passwordFilePath) {
    // Var used for input
    int c; // the current character code
    bool encore = true; // get a new character

    // Password and time related variables
    string passwordAttempt;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente;
    vector<long long int> timeIntervals;


    Password passwordControler(passwordFilePath);


    cout << endl << "Veuillez entrer le mot de passe pour l'authentification :" << endl;
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
