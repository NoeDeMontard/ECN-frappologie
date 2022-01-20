#include <conio.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <sstream>

#include "lib.h"
#include "settings.h"
#include "password.h"
#include "language.h"
#include "keyWrapper.h"

using namespace std;

void moyenneEcartType(vector<vector<long long int>> data, vector<long long int>& moyennes, vector<long long int>& ecartsType) {
    int nbrEssais = data.size();
    int nbrTouches = data[0].size();

    for (int i = 0; i < nbrEssais; i++) {
        for (int j = 0; j < nbrTouches; j++) {
            if (VERBOSITY >= 6) { cout << "data[i][j]" << data[i][j] << endl; }
            moyennes[j] += data[i][j];
            ecartsType[j] += data[i][j] * data[i][j];
        }
    }
    for (int j = 0; j < nbrTouches; j++) {
        if (VERBOSITY >= 6) { cout << "moyennes[j] initial " << moyennes[j] << endl; }
        if (VERBOSITY >= 6) { cout << "ecartsType[j] initial " << ecartsType[j] << endl; }
        moyennes[j] /= nbrEssais;
        ecartsType[j] /= nbrEssais;
        ecartsType[j] -= moyennes[j];
        ecartsType[j] = sqrt(ecartsType[j]);
        if (VERBOSITY >= 6) { cout << "moyennes[j] " << moyennes[j] << endl; }
        if (VERBOSITY >= 6) { cout << "ecartsType[j] " << ecartsType[j] << endl; }
    }
}

// TODO : if the user want a secret password, don't show the key pressed
void registerPasswordTimes(const string passwordFilePath){
    // Check if user exist, if he does, ask for if the user whant to overwrite the old password take (with a password verification in case of overwriting)
    //if (filesystem::exists(passwordFilePath)) {// If c++17
    ifstream ifile; // if c++<17
    ifile.open(passwordFilePath);
    if (ifile) {
        ifile.close(); // end if c++<17
        cout << language->userExist << endl;
        cout << language->registerAgainChoice << endl;
        string changePasswordInput;
        cin >> changePasswordInput;
        if (!(*find(language->yes.begin(), language->yes.end(), changePasswordInput) == changePasswordInput)) {
            return;
        }
        else {
            bool accessGranted = testPasswordTimes(passwordFilePath);
            if (!accessGranted) {
                cout << language->authentificationFailure << endl;
                cout << language->registrationFailure << endl;
                return;
            }
        }
    }

    // User should be registered (again)

    // Openning the file to overwrite
    stringstream passwordFileBuffer;

    // Does the user want to be remembered his password ?
    string secretPassword;
    cout << language->secretPasswordChoice << endl;
    cin >> secretPassword;
    if (*find(language->yes.begin(), language->yes.end(), secretPassword) == secretPassword) {
        secretPassword = "0";
    }
    else {
        secretPassword = "1";
    }
    passwordFileBuffer << "[Show Password]" << endl;
    passwordFileBuffer << secretPassword << endl;
    passwordFileBuffer << endl;


    // Various vars
    int c; // the current character code
    bool encore = true; // get a new character
    int nbrDataPoints = 5; // number of password take

    // Password and time related variables
    vector<vector<long long int>> timeIntervalsMeasure(nbrDataPoints);


    // Reading the password to use
    string ps;
    cout << language->enterNewPassword << endl;
    while (encore) {
        c = _getch();
        string key = keyWrapper(c, encore);
        ps += key;
        cout << key;
    }
    cout << endl;

    //Rewriting the password and the data in the file
    passwordFileBuffer << "[Password]" << endl;
    passwordFileBuffer << ps << endl;

    int j = 0;
    while (j < nbrDataPoints) {
        string passwordAttemptMeasure;
        vector<chrono::time_point<chrono::high_resolution_clock>> timesMeasure; // To get the user data
        encore = true;
        cout << language->enterNewPasswordAgain << endl;;

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
                if (VERBOSITY >= 6) { cout << us << endl; }
                timeIntervalsMeasure[j].push_back(us);
            }
            j += 1;
        }
        else {
            cout << language->wrongPasswordTryAgain << endl;
        }

    }

    vector<long long int> moyennes(timeIntervalsMeasure[0].size(), 0);
    vector<long long int> ecartsType(timeIntervalsMeasure[0].size(), 0);

    moyenneEcartType(timeIntervalsMeasure, moyennes, ecartsType);

    // Writing the data in the file
    if (passwordFileBuffer) {
        passwordFileBuffer << "[Time Intervals]" << endl;
        for (int i = 0; i < moyennes.size(); i++) {
            if (VERBOSITY >= 6) { cout << "moyennes[i] " << moyennes[i] << endl; }
            passwordFileBuffer << moyennes[i] << endl;
        }
        passwordFileBuffer << endl;
        passwordFileBuffer << "[Time Deviations]" << endl;
        for (int i = 0; i < ecartsType.size(); i++) {
            if (VERBOSITY >= 6) { cout << "ecartsType[i] " << ecartsType[i] << endl; }
            passwordFileBuffer << ecartsType[i] << endl;
        }

		// Move the temporary file to the user file

		//filesystem::copy_file(tmpPasswordFilePath, passwordFilePath, filesystem::copy_options::overwrite_existing); // c++17 // Issue :  Doesn't sems to take into account the overwrite part
		//std::filesystem::remove(tmpPasswordFilePath); // C++17

		// IF c++<17
		// Copy
		std::ofstream dst(passwordFilePath);
		dst << passwordFileBuffer.rdbuf();
		//src.close();
		dst.close();

		//ENDIF c++<17

        cout << language->registrationSuccess << endl;
    }
}

bool testPasswordTimes(const string passwordFilePath){
    // Var used for input
    int c; // the current character code
    bool encore = true; // get a new character

    // Password and time related variables
    string passwordAttempt;
    vector<chrono::time_point<chrono::high_resolution_clock>> times; // Time mesurement
    chrono::time_point<chrono::high_resolution_clock> tempsTouchePrecedente;
    vector<long long int> timeIntervals;


    Password passwordControler(passwordFilePath);

    bool showPassword = passwordControler.shouldDisplay();

    cout << language->enterPassword << endl;
    passwordControler.printPassword();

    // The password and times capture
    while (encore) {
        c = _getch();
        times.push_back(chrono::high_resolution_clock::now());
        string key = keyWrapper(c, encore);
        passwordAttempt += key;
        if (showPassword || key == ""){
            cout << key;
        } else {
            cout << "*";
        }
    }
    cout << endl;

    // Compture the times and key combinaisons
    tempsTouchePrecedente = times[0];
    for (int i = 0; i < times.size(); i++) {
        chrono::time_point<chrono::high_resolution_clock> tempsToucheActuelle = times[i];
        long long int us = chrono::duration_cast<chrono::microseconds>(tempsToucheActuelle - tempsTouchePrecedente).count(); // nanoseconds, microseconds, milliseconds
        tempsTouchePrecedente = tempsToucheActuelle;
        timeIntervals.push_back(us);
        if (VERBOSITY >= 6) { cout << us << endl; }
    }
    bool accessGranted = passwordControler.checkPasswordAttempt(passwordAttempt, timeIntervals);
    return accessGranted;
}
