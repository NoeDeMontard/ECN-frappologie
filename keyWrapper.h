///
/// \file keyWrapper.h
///	\brief Header de keyWrapper, permattant de lier le code d'une touche à sa valeur
///

#pragma once
#include <string>
#include "keyConst.h"

///
/// \fn std::string keyWrapper(int c, bool &encore)
/// \param c entier du code de la touche
/// \param encore booléen de passage par argument indicant si il faut demander une autre touche
/// \return string décrivant la touche pressée
/// \brief Permet de récupérer la touche pressée depuis son code
///
std::string keyWrapper(int c, bool &encore);
