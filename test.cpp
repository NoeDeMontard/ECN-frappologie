#include <iostream>
#include <string>
using namespace std;

int main()
{
	string test;

	cout << "Test de la fonction getline" << endl << endl << endl;
	getline(std::cin, test);
	cout << endl << endl << test << endl;

	return 0;
}

