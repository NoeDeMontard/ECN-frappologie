#pragma once
#include <vector>
#include <string>
#include "language.h"

using namespace std;

void moyenneEcartType(vector<vector<long long int>> data, vector<long long int> &moyennes, vector<long long int> &ecartsType);

bool testPasswordTimes(const string passwordFilePath);

void registerPasswordTimes(const string passwordFilePath);
