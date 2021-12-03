#include <string>
#include <vector>
#include <iostream>
#include "password.h"

#define DEBUG true

using namespace std;


Password::Password(){
	password = "";
	times;
}
Password::Password(string filename){
	 // TODO : read from a file for initialisation

}
Password::Password(string _password, vector<long long int> _times){
	 password = _password;
	 times = _times;
}

bool Password::checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals){
	//TODO
	if (DEBUG){
		cout << "---" << endl;
		cout << password;
		cout << passwordAttempt;
		cout << "---" << endl;
	}
	if (passwordAttempt != password) {
		if (DEBUG){cout << "Password failure" << endl;}
		return false;
	}
	if (timeIntervals.size() != times.size()) {
		// Sould never be reached in normal usage: it the size is not the same, the password shoudln't be the same.
		// It can be reached if a password contain a special caracter coded on pultiple char in the string though.
		if (DEBUG){
			cout << "Size failure : " << timeIntervals.size() << "; " << times.size() << endl;
			for (int i = 0; i < min(timeIntervals.size(), times.size()) ; i++){
				cout << timeIntervals[i] << "; " << times[i] << endl;
			}
		}
		return false;
	}
	for (int i = 0; i <  timeIntervals.size(); i++){
		auto timeInterval = timeIntervals[i];
		if (times[i]>20*timeInterval || timeInterval>20*times[i]) {
			if (DEBUG){
				cout << "Timing failure" << endl;
				for (int j = 0; j < min(timeIntervals.size(), times.size()) ; j++){
					cout << timeIntervals[j] << "; " << times[j] << "; " << timeIntervals[j]/(times[j]+1) << endl;
				}
			}
			return false;
		}
	}
	return true;
}
