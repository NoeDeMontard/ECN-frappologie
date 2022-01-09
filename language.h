#pragma once
#include <string>
#include <vector>

using namespace std;

struct Language
{
	const string welcome;
	const string developpers;
	const string registrationOrAuthentification;
	const vector<string> registration;		// TODO
	const vector<string> authentification;	// TODO
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
};
const Language french = {
	.welcome		= "Bienvenue dans notre authenitification par frappologie",
	.developpers 	= "Developpe par Noe de Montard & Clement Naudet",
	.registrationOrAuthentification = "Souhaitez vous enregistrer un nouvel utilisateur (r) ou vous authentifier (A) ?",
	.usernameInput	= "Entrer votre nom d'utilisateur :",
	.success		= "Succes",
	.failure		= "Echec",
	.userExist		= "L'utilisateur existe deja",
	.registerAgainChoice		= "Voulez vous re-enregistrer le mot de passe ? (o/N)",
	.authentificationFailure	= "Echec de l'authentification",
	.registrationSuccess		= "Enregistrement effectue avec succes",
	.registrationFailure		= "L'enregistrement a echoue",
	.secretPasswordChoice		= "Voulez vous que votre mot de passe soit secret ? (o/N)",
	.enterPassword				= "Entrer votre mot de passe",
	.enterNewPassword			= "Entrer votre nouveau mot de passe",
	.enterNewPasswordAgain		= "Entrer votre nouveau mot de passe une nouvelle fois",
	.wrongPasswordTryAgain		= "Le mot de passe rentre est errone, veuillez reessayer",
	.yes	= {"o", "O", "oui", "Oui", "OUi"," OUI", "oUI", "ouI", "oUi", "OuI"},
	.no		= {"n", "N", "non", "Non", "NON"} // could be more or less exaustive
};
const Language english = {
	.welcome		= "Welcome in our 'Frappologie' authentification",
	.developpers	= "Developed by Noe de Montard & Clement Naudet",
	.registrationOrAuthentification = "Would you like to register a new user (r) or to authentificate (A) ?",
	.usernameInput	= "Enter user name",
	.success		= "Success",
	.failure		= "Failure",
	.userExist		= "The user alredy exists",
	.registerAgainChoice		= "Would you like to register again? (y/N)",
	.authentificationFailure	= "Authentification Failure",
	.registrationSuccess		= "Registration is a success",
	.registrationFailure		= "Registration is a failure",
	.secretPasswordChoice		= "Would you like you password to be secret? (y/N)",
	.enterPassword				= "Enter your password",
	.enterNewPassword			= "Enter your new password",
	.enterNewPasswordAgain		= "Enter your new password again",
	.wrongPasswordTryAgain		= "The password is wrong, try again",
	.yes	= {"y", "Y", "yes", "Yes", "YES"},
	.no		= {"n","N","No","NO","nO"}
};

const Language language = french; // TODO : Better language switching

/*
welcome = "Welcome in our 'Frappologie' authentification";
developpers = "Developed by Noe de Montard & Clement Naudet";
registrationOrAuthentification = "Would you like to register a new user (r) or to authentificate (A) ?";
usernameInput = "Enter user name";
success = "Success";
failure = "Failure";

*/