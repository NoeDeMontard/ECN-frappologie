#include <windows.h> // Used by CreateDirectory
#include <math.h>
#include <cstdio>    // Used by remove in c++<17
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>

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
    string user;
    cout << language.usernameInput << endl;
    cin >> user;
    std::size_t found = user.find_first_of("/\\");
    while (found!=string::npos)
    {
        user[found]='_';
        found=user.find_first_of("/\\",found+1);
    }
    if (*find(language.registration.begin(), language.registration.end(), choice) == choice) {
        // THE PASSWORD FILE INITIALISATION METHOD
        registerPasswordTimes(passwordFolderPath + "/" + user + "." + passwordFileName); 
    }
    else {
        // THE PASSWORD CHECKING METHOD
        accessGranted = testPasswordTimes(passwordFolderPath + "/" + user + "." + passwordFileName);

        if (VERBOSITY>=1){
            cout << (accessGranted ? language.success : language.failure) << endl;
        }
    }


    return (accessGranted?0:3);
}
