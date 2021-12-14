#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "password.h"
#include "debug.h"

using namespace std;


Password::Password(){
	password = "";
	times;
	timesDeviations;
}

Password::Password(const string filename){
	// First line : the password
	// Then the time intervals
	// Then a blank line
	// Then the associated standard deviations
	 vector<string> timesStrings;
	 ifstream passwordFile;
	 
	 passwordFile.open(filename);
	 if (passwordFile.is_open() && passwordFile.good()){
	 	// First line : the password
		getline(passwordFile, password);
		//password += "\n";
		while (passwordFile) {
			// Then the time intervals
			string currentTimeString;
			long long int currentTime;
			getline(passwordFile, currentTimeString);
			if (currentTimeString == ""){ // a blank line, then the associated standard deviations
				break;
			} else {
				if(DEBUG >= 3){cout << currentTimeString << endl;}
				currentTime = stoll(currentTimeString, nullptr, 10); // String TO Long Long
				times.push_back(currentTime);
			}
		}
		while (passwordFile) {
			// Then the associated standard deviations
			string currentTimeString;
			long long int currentTime;
			getline(passwordFile, currentTimeString);
			if (currentTimeString == ""){ // a blank line might appear at the end of the file
				break;
			} else {
				if(DEBUG >= 3){cout << currentTimeString << endl;}
				currentTime = stoll(currentTimeString, nullptr, 10); // String TO Long Long
				timesDeviations.push_back(currentTime);
			}
		}
	}
	passwordFile.close();
}

Password::Password(const string _password, vector<long long int> _times){
	 password = _password;
	 times = _times;
	 timesDeviations;
}

bool Password::checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals){
	//TODO : better timing checks
	bool useTimesDeviations = true; // Enable / disable the better timing check
	
	if (DEBUG >= 2){
		cout << "---" << endl;
		cout << password << endl;
		cout << passwordAttempt << endl;
		cout << "---" << endl;
	}
	
	// Check password
	if (passwordAttempt != password) {
		if (DEBUG){cout << "Password failure" << endl;}
		return false;
	}
	
	// Check number of time intervals
	if (timeIntervals.size() != times.size()) {
		// Sould never be reached in normal usage: it the size is not the same, the password shoudln't be the same.
		// It can be reached if a password contain a special caracter coded on multiple char in the string though.
		if (DEBUG){cout << "Size failure : " << timeIntervals.size() << "; " << times.size() << endl;}
		if (DEBUG >= 2) {
			for (int i = 0; i < min(timeIntervals.size(), times.size()) ; i++){
				cout << timeIntervals[i] << "; " << times[i] << endl;
			}
		}
		return false;
	}
	
	// Check presence and length of deviation vector 
	if (timesDeviations.size() != timeIntervals.size()) {
		if (DEBUG && timesDeviations.empty()){cout << "Warning : legacy time checking method used." << (useTimesDeviations?" Anomalous usage. User should re registrate his password":"") << endl;}
		useTimesDeviations = false;
	}
	
	// Check time intervals
	for (int i = 0; i <  timeIntervals.size(); i++){
		auto timeInterval = timeIntervals[i];
		bool timingFailure;
		if (useTimesDeviations) {
			timingFailure = timeInterval > times[i] + 2*timesDeviations[i] || timeInterval < times[i] - 2*timesDeviations[i]; //2*deviation for 95% of success with the gaussian distribution hypothesis
		} else {
			timingFailure = times[i]>3*timeInterval || timeInterval>3*times[i];
		}
		if (timingFailure) {
			if (DEBUG){cout << "Timing failure" << endl;}
			if (DEBUG >= 2){
				for (int j = 0; j < min(timeIntervals.size(), times.size()) ; j++){
					cout << "Mesure: " << timeIntervals[j] << "; Reference: " << times[j] << "; " << (useTimesDeviations? (timeInterval - times[i]) : (timeIntervals[j]/(times[j]+1)) ) << endl;
				}
			}
			return false;
		}
	}
	return true;
}

string Password::getPassword(){
	return password;
}
void Password::printPassword(){
	cout << password << endl;
}
