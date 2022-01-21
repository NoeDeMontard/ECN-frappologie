#pragma once
#include <string>
#include <vector>

using namespace std;

class Password
{
private:
	bool userExists;
	bool showPassword;
	string password;
	vector<long long int> times;
	vector<long long int> timesDeviations;

public:
	Password();
	Password(const string filename);
	Password(string _password, vector<long long int> _times);
	bool checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals);
	void printPassword();
	bool shouldDisplay();
};
