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
		void EnterVoterMenu();
		void Update();
		string updateZipCode();
		string updateUserid();
		bool LoggedIn();
		void Password();
		void View();
		void Donate(float amount);
		void Report();
		string toString();
};
