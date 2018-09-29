#ifndef VOTER_H
#define VOTER_H
#include <string>
using namespace std;
class Voter{
	public:
		string LastName;
		string FirstName;
		string Userid;
		string user_password;
		int Age;
		int StreetNumber;
		string StreetName;
		string Town;
		string ZipCode;
		float AmountDonated;
		Voter();
		Voter(string& line);
		bool EnterVoterMenu();
		void Update();
		string updateZipCode();
		string updateUserid();
		string setUserid(string UserID );
		bool LoggedIn();
		void Password();
		void View();
		void Donate(float amount);
		void setNewPassword();
		void Report();
};
#endif
