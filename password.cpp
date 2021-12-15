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
	showPassword = false;
}

Password::Password(const string filename){
	ifstream passwordFile;

	passwordFile.open(filename);

	string currentSection;
	showPassword = false;
	while (passwordFile)
	{
		string line;
		long long int line2int;
		getline(passwordFile, line);
		if (DEBUG >= 3){cout << currentSection << " " << line << endl;}
		if (!line.empty())
		{
			if (line[0] == '[')
			{
				currentSection = line;
			}
			else
			{
				if (currentSection == "[Password]")
				{
					password = line;
				}
				else if (currentSection == "[Time Intervals]")
				{
					line2int = stoll(line, nullptr, 10); // String TO Long Long
					times.push_back(line2int);
				}
				else if (currentSection == "[Time Deviations]")
				{
					line2int = stoll(line, nullptr, 10); // String TO Long Long
					timesDeviations.push_back(line2int);
				}
				else if (currentSection == "[Show Password]")
				{
					showPassword = (line == "1");
				}
			}
		}
	}
	if (DEBUG >= 3){cout << password << endl;}
	passwordFile.close();
}

Password::Password(const string _password, vector<long long int> _times){
	 password = _password;
	 times = _times;
	 timesDeviations;
	 showPassword = false;
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
			timingFailure = timeInterval > times[i] + 1*timesDeviations[i] || timeInterval < times[i] - 1*timesDeviations[i]; //2*deviation for 95% of success with the gaussian distribution hypothesis
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

void Password::printPassword(){
	if (showPassword) {
		cout << password << endl;
	}
}
