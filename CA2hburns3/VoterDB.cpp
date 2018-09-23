#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "VoterHeader.h"
using namespace std;

class VoterDB{
	public:
		string filename;
		string user_id;
		string password;
		//constructor to set the filename and dynamic array 
		VoterDB(filename, max_number_of_voters){
			//set the name of the csv file
			this.filename = filename;
			//dynamically allocate the max
			VoterList = new Voter[max_number_of_voters];
			//declare a counter that checks if you pass max voters
			int cntr  = 0;
			//declare a stream to process the file
			ifstream infile("./ActiveVoters.csv"); 
			string line;

			while(cntr < max_number_of_voters && getline(infile, line)){
				stringstream strstr(line);
				//TODO process each line and fill the voter array
				cntr++;
			}
		}
		Voter[] VoterList;
		bool LoggedIn(string user_id, string password){
			ifstream infile("./ActiveVoters.csv"); // for example
			string line = "";
			while (getline(infile, line)){
				stringstream strstr(line);
				string word = "";
			}
		}

void updateInputs(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode){
	cout <<"\nLast Name: ";
	cin >> Lastname;
	cout <<"First Name: ";
	cin >> FirstName;
	cout <<"Age: ";
	cin >> Age;
	cout <<"House Number: ";
	cin >> StreetNumber;
	cout <<"Street Name: ";
	cin.ignore();
	getline(cin,StreetName);
	cout <<"Town: ";
	cin.ignore();
	getline(cin,StreetName);
	cin >> Town;
	cout <<"Zip Code: ";
	cin >> ZipCode;
}

void newInputs(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode, float &AmountDonated){
	updateInputs(Lastname,FirstName,Age,StreetNumber,StreetName,Town,ZipCode);
	AmountDonated = 0;
}

void View(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode, float &AmountDonated){
	cout << "\nDonor Info:\n" << FirstName << " "<< Lastname << ": " <<  "age "  << Age << "\n";
	cout << StreetNumber << " " << StreetName << endl;
	cout << Town << " " << ZipCode << "\n";
	cout << "Current Amount Donated:" <<  setprecision (2) << fixed << " $"  <<AmountDonated << "\n\n";
}

float donate(float amount, float addition){
	amount += addition;
	cout << setprecision (2) << fixed << " $"  <<addition<< " donated.\n";
	return amount;
}

void report(string &Lastname, float &AmountDonated){
	cout <<"\n" << Lastname << " $" << std::setprecision(2) << std::fixed << AmountDonated << "\n";
}

void Passwd(string &Old_Password){
	cout << "Enter old password: ";
	string User_Password;
	cin >> User_Password;
	if(User_Password == Old_Password){
		string NewPassword;
		string second_attempt_at_new_password;
		cout << "Enter new password: ";
		cin >> NewPassword;
		cout << "Enter new password again: ";
		cin >> second_attempt_at_new_password;
		if(second_attempt_at_new_password == NewPassword)
			Old_Password = NewPassword;
		else
			cout << "Passwords do not match.\n";
	}
	else
		cout << "Incorrect Password.\n";

	bool LoggedIn(string user_id, string password){
		ifstream infile("./ActiveVoters.csv"); // for example
		string line = "";
		while (getline(infile, line)){
			stringstream strstr(line);
			string word = "";
		}
	}
