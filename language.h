#pragma once
#include <string>
#include <vector>

using namespace std;

struct Language
{
	const string welcome;
	const string developpers;
	const string registrationOrAuthentification;
	const string usernameInput;
	const string success;
	const string failure;
	const string userExist;
	const string registerAgainChoice;
	const string authentificationFailure;
	const string registrationSuccess;
	const string registrationFailure;
	const string secretPasswordChoice;
	const string enterPassword;
	const string enterNewPassword;
	const string enterNewPasswordAgain;
	const string wrongPasswordTryAgain;
	const vector<string> yes;
	const vector<string> no;
	const vector<string> registration;
	const vector<string> authentification;
	// TODO : VERBOSITY > 1 strings
};

extern const Language french;
extern const Language english;
extern const Language * language;
