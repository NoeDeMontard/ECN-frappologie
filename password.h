#pragma one
#include <string>
#include <vector>

using namespace std;

class Password{
private:
	string password;
	vector<long long int> times;
public:
	Password();
	Password(const string filename);
	Password(string _password, vector<long long int> _times);
	bool checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals);
	string getPassword(); // NOTE : Should not be public in case of a secret password instead of a shared one
	void printPassword(); // NOTE : Should not be public in case of a secret password instead of a shared one
};
