///
/// \file lib.h
///	\brief Header des fonctions sans classes.
///
#pragma once
#include <vector>
#include <string>
#include "language.h"

using namespace std;

///
/// \fn void moyenneEcartType(vector<vector<long long int>> data, vector<long long int> &moyennes, vector<long long int> &ecartsType)
/// \param data Données à analyser statistiquement
/// \param moyennes Retour par argument des moyennes des données
/// \param ecartsType Retour par argument des écart-types des données
/// \brief Calcule moyenne et écart-types des données en entrées. Un vecteur tel que data.size() == 1 retournera moyenne = data[0] et ecartsType vecteur null
///
void moyenneEcartType(vector<vector<long long int>> data, vector<long long int> &moyennes, vector<long long int> &ecartsType);

///
/// \fn bool testPasswordTimes(const string passwordFilePath)
/// \param passwordFilePath chemin du fichier de mot de passe de l'utilisateur
/// \return Booléen représentant si l'authentification a réussie
/// \brief Demande à l'utilisateur de tapper son mot de passe pour l'identifier.
///
bool testPasswordTimes(const string passwordFilePath);

///
/// \fn void registerPasswordTimes(const string passwordFilePath)
/// \param passwordFilePath chemin du futur fichier de mot de passe de l'utilisateur
/// \brief Enregistre l'utilisateur en interragissant avec lui. Vérifie préalablement si il existe ou non et demande que faire si l'utilisateur existe. L'écrasement d'un utilisateur est protégé par son identification préalable.
///
void registerPasswordTimes(const string passwordFilePath);
