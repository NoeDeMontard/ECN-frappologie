///
/// \file language.h
///	\brief Header de la structure language permettant la traduction et déclaration des languages
///

#pragma once
#include <string>
#include <vector>

using namespace std;

///
/// \struct Language
/// \brief Définit les chaines de caractère utilisées pour l'affichage du programme
///
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

	const string password;
	const string testedPassword;
	const string user;
	const string invalid;
	const string size;
	const string timing;
	const string legacyWarning;
	const string registerAgain;

	// TODO : VERBOSITY > 3 strings
};

extern const Language french;
extern const Language english;
extern const Language *language;
