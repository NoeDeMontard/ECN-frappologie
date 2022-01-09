#include <windows.h> // Used by CreateDirectory
#include <math.h>
#include <cstdio>    // Used by remove in c++<17
#include <filesystem>
#include <iostream>
#include <string>

#include "settings.h"
#include "language.h"
#include "lib.h"

using namespace std;
// void CreateDirectory(const char*, int*);

int main(int argc, char* argv[])
{
    const string passwordFileName = "passwordFile";
    const string passwordFolderPath = "passwords";
    bool accessGranted = true;


    // Create the passwordFolder if it doesn't exists
    CreateDirectory(passwordFolderPath.c_str(), NULL);
    //filesystem::create_directory(passwordFolderPath);// If c++17, more portable
    // Both fail if the passwordFolderPath use a path with a missing parent directory


    cout << language.welcome << endl;
    cout << language.developpers << endl;
    cout << language.registrationOrAuthentification << endl;    string choice;
    cin >> choice;
    if (choice == "r" || choice == "R") {
        string user;
        cout << language.usernameInput << endl;
        cin >> user; // TODO : sanitise username to excape folder navigation capability
        // THE PASSWORD FILE INITIALISATION METHOD
        registerPasswordTimes(passwordFolderPath + "/" + user + "." + passwordFileName); 
    }
    else {
        string user;
        cout << language.usernameInput << endl;
        cin >> user;
        // THE PASSWORD CHECKING METHOD
        accessGranted = testPasswordTimes(passwordFolderPath + "/" + user + "." + passwordFileName);

        if (VERBOSITY>=1){
            cout << (accessGranted ? language.success : language.failure) << endl;
        }
    }


    return (accessGranted?0:3);
}
