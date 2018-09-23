#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Voter.h"
using namespace std;

class Voter{
	public:
	Voter(){
		string Lastname = "[empty]";
		string FirstName= "[empty]";
		string Userid = "[empty]";
		string Password = "[empty]";
		int Age = -1;
		int StreetNumber = 0;
		string StreetName = "[empty]";
		string Town = "[empty]";
		string ZipCode = "-----";
		float AmountDonated = 0.0;
	}
	Voter(string Lastname,string FirstName, string Userid, string password,
	int age, int StreetNumber, string StreetName, string Town, string ZipCode ){
		string Lastname = "[empty]";
		string FirstName= "[empty]";
		string Userid = "[empty]";
		string Password = "[empty]";
		int Age = -1;
		int StreetNumber = 0;
		string StreetName = "[empty]";
		string Town = "[empty]";
		string ZipCode = "-----";
		float AmountDonated = 0.0;
	}
	bool LoggedIn(string user_id, string password){
		ifstream infile("./ActiveVoters.csv"); // for example
		string line = "";
		while (getline(infile, line)){
			stringstream strstr(line);
			string word = "";
		}
	}
	
	void NewVoter(string userid, string name, string address, string password){

	}
}
int main(){
	string input;
	string user_id;
	string password;
	while(input != "Quit"){
		cout << "Enter User ID: ";
		cin >> user_id;
		cout << "\nEnter Password: ";
		cin >> password;
		Login(user_id, password);

	input = "";
}

void run()
{
	string input;
	while( input != "Quit"){
		cout << "\nEnter a command. \nChoose from [\"New\" \"Update\" \"View\" \"Donate\" \"Report\" \"Quit\"]" << "\n: ";
		cin >> input;

		if (input == "New")
			newInputs( Lastname, FirstName, Age, StreetNumber, StreetName, Town, ZipCode, AmountDonated);
		else if (input == "Update")
			updateInputs(Lastname,FirstName,Age,StreetNumber,StreetName,Town,ZipCode);
		else if (input == "View")
			View(Lastname, FirstName, Age, StreetNumber, StreetName, Town, ZipCode, AmountDonated);
		else if (input == "Donate"){
			float amount;
			cout << "\nEnter Amount to Donate:"; 
			cin >> amount;
			AmountDonated = donate(AmountDonated,amount);
		}
		else if (input == "Report")
			report(Lastname, AmountDonated);
		else if (input == "Quit")
			break;
		else
			cout << "Command not recognized. Please try again." << "\n";
		}
}
