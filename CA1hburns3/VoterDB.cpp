#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "VoterHeader.h"
using namespace std;
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
