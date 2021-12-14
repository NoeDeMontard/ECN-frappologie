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

void registerPasswordTimes(const string passwordFilePath){
    // TODO : verifier qu'on ecrase pas un autre utilisateur
    // Various vars
	int c;
    bool encore = true;

    // Password and time related variables
    string passwordAttemptMeasure;
    vector<chrono::time_point<chrono::high_resolution_clock>> timesMeasure; // To get the user data
	vector<long long int> timeIntervalsMeasure;
	
    
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
    encore = true;
    cout << "Le mot de passe est le suivant, veuillez le taper une premiere fois :" << endl;
    cout << ps << endl;

    //Rewriting the password and the data in the file

    fstream passwordFile2(passwordFilePath, ios::out);
    passwordFile2 << ps << endl;
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
    // Calculating the intervals between each key pressed
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente = timesMeasure[0];
    for (int i = 0; i < timesMeasure.size(); i++) {
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = timesMeasure[i];
        long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;
        timeIntervalsMeasure.push_back(us);
    }
    // Writing the data in the file
    if (passwordFile2) {
        for (int i = 0; i < timesMeasure.size(); i++) {
            passwordFile2 << timeIntervalsMeasure[i] << endl;
        }
    }
    passwordFile2.close();
}

bool testPasswordTimes(const string passwordFilePath){
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
        if (DEBUG >= 2) {cout << us << endl;}
    }
    bool accessGranted = passwordControler.checkPasswordAttempt(passwordAttempt, timeIntervals);
    return accessGranted;
}

int main()
{
    const string passwordFilePath = "passwordFile.ignore";
    
    cout << "Would you like to register a new user (r) or to authentificate (A) ?" << endl;
    string choice;
    cin >> choice;
    if (choice == "r" || choice == "R"){
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
