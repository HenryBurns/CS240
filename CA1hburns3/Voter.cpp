#include <stdio.h>
#include <iostream>
#include <string>
#include "VoterHeader.h"
using namespace std;
int main(){
	string input = "";
	string Lastname = "[empty]";
	string FirstName= "[empty]";
	int Age = -1;
	int StreetNumber = 0;
	string StreetName = "[empty]";
	string Town = "[empty]";
	string ZipCode = "-----";
	float AmountDonated = 0.0;
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
