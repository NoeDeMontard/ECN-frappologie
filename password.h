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
	Password(string filename);
	Password(string _password, vector<long long int> _times);
	bool checkPasswordAttempt(string passwordAttempt, vector<long long int> timeIntervals);
	
};
