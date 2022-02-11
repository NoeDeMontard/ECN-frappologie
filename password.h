#pragma once
#include <string>
#include <vector>

using namespace std;

///
/// \class Password
///	\brief Gère le mot de passe de l'utilisateur
///
class Password
{
private:
	bool userExists;
	bool showPassword;
	string password;
	vector<long long int> times;
	vector<long long int> timesDeviations;

public:
	///
	/// \fn Password()
	///	\brief Constructeur par défaut de la classe Password.
	///
	Password();

	///
	/// \fn Password(const string filename)
	/// \param filename fichier de mot de passe
	///	\brief Constructeur depuis un fichier de mot de passe de la classe Password.
	///
	Password(const string filename);

	// Déprécié
	Password(string _password, vector<long long int> _times);

	///
	/// \fn bool checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals)
	/// \param passwordAttempt chaine de caractère du mot de passe tempté
	/// \param timeIntervals vecteur des entiers des durées entre les touches en milisecondes
	/// \return l'acceptation ou le rejet de l'authentification
	///	\brief Vérifie si une tentative d'accès est valide
	///
	bool checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals);

	void printPassword();

	bool shouldDisplay();
};
