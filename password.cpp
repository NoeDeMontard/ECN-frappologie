#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "password.h"
#include "settings.h"
#include "language.h"

using namespace std;

Password::Password()
{
	password = "";
	times;
	timesDeviations;
	showPassword = false;
	userExists = false;
}

Password::Password(const string filename)
{
	userExists = false;
	ifstream passwordFile;

	passwordFile.open(filename);

	if (passwordFile)
	{
		userExists = true;
	}

	string currentSection;
	showPassword = false;
	while (passwordFile)
	{
		string line;
		long long int line2int;
		getline(passwordFile, line);
		if (VERBOSITY >= 4)
		{
			cout << currentSection << endl;
		}
		if (VERBOSITY >= 6)
		{
			cout << line << endl;
		}
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
	passwordFile.close();
}

bool Password::checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals)
{
	bool useTimesDeviations = true; // Enable / disable the better timing check

	if (VERBOSITY >= 8)
	{
		cout << "Password : " << password << endl;
	}
	if (VERBOSITY >= 6)
	{
		cout << "Password attempt : " << passwordAttempt << endl;
	}

	// Check user existance
	if (!userExists)
	{
		// if (VERBOSITY >= 3){cout << "User invalid" << endl;}
		if (VERBOSITY >= 3)
		{
			cout << language->failure << " " << language->user << " " << language->invalid << endl;
		}
		return false;
	}

	// Check password
	if (passwordAttempt != password)
	{
		// if (VERBOSITY >= 3){cout << "Password failure" << endl;}
		if (VERBOSITY >= 3)
		{
			cout << language->failure << " " << language->password << " " << language->invalid << endl;
		}
		return false;
	}

	// Check number of time intervals
	if (timeIntervals.size() != times.size())
	{
		// Sould never be reached in normal usage: it the size is not the same, the password shoudln't be the same.
		// It can be reached if a password contain a special caracter coded on multiple char in the string though.
		// if (VERBOSITY >= 3){cout << "Size failure" << endl;}
		if (VERBOSITY >= 3)
		{
			cout << language->failure << " " << language->size << " " << language->invalid << endl;
		}
		if (VERBOSITY >= 5)
		{
			cout << "Size of timing input" << timeIntervals.size() << endl;
		}
		if (VERBOSITY >= 7)
		{
			cout << "Size of timing reference" << times.size() << endl;
		}
		return false;
	}

	// Check presence and length of deviation vector
	if (timesDeviations.size() != timeIntervals.size())
	{
		// if ((VERBOSITY >= 2) && timesDeviations.empty()){cout << "Warning : legacy time checking method used." << (useTimesDeviations?" Anomalous usage. User should re registrate his password":"") << endl;}
		if ((VERBOSITY >= 2) && timesDeviations.empty())
		{
			cout << language->legacyWarning << " " << (useTimesDeviations ? language->registerAgain : "") << endl;
		}
		useTimesDeviations = false;
	}

	// Check time intervals
	for (int i = 0; i < timeIntervals.size(); i++)
	{
		auto timeInterval = timeIntervals[i];
		bool timingFailure;
		if (useTimesDeviations)
		{
			timingFailure = timeInterval > times[i] + 1 * timesDeviations[i] || timeInterval < times[i] - 1 * timesDeviations[i]; // 2*deviation for 95% of success with the gaussian distribution hypothesis
		}
		else
		{
			timingFailure = times[i] > 3 * timeInterval || timeInterval > 3 * times[i];
		}
		if (timingFailure)
		{
			// if (VERBOSITY >= 3){cout << "Timing failure" << endl;}
			if (VERBOSITY >= 3)
			{
				cout << language->failure << " " << language->timing << " " << language->invalid << endl;
			}
			if (VERBOSITY >= 8)
			{
				for (int j = 0; j < min(timeIntervals.size(), times.size()); j++)
				{
					cout << "Mesure: " << timeIntervals[j] << "; Reference: " << times[j] << "; " << (useTimesDeviations ? (timeInterval - times[i]) : (timeIntervals[j] / (times[j] + 1))) << endl;
				}
			}
			return false;
		}
	}
	return true;
}

void Password::printPassword()
{
	if (showPassword)
	{
		cout << password << endl;
	}
}

bool Password::shouldDisplay()
{
	return showPassword;
}