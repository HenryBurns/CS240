#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Voter.h"
using namespace std;
Voter::Voter(){
		string LastName = "[empty]";
		string FirstName= "[empty]";
		string Userid = "[empty]";
		string user_password = "[empty]";
		int Age = -1;
		int StreetNumber = 0;
		string StreetName = "[empty]";
		string Town = "[empty]";
		string ZipCode = "-----";
		float AmountDonated = 0.0;
	}
	void Voter::EnterVoterMenu(){
	string input = "";
	float donation;
	while(input != "Logout"){
		cout << "Enter Input: \n";
		cin >> input;
		//input = transform(input.begin(), input.end(), input.begin(), ::toupper);
		if(input == "Update"){
			cout <<"Updating voter information";
			Update();
			}
		else if (input == "Passwd"){
			cout <<"Setting new password";
			Password();
			}
		else if (input == "View"){
			cout << "Viewing voter information";
			View();
		}
		else if (input == "Donate"){
			cout << "donating to campaign\n Enter amount to donate: ";
			cin >> donation;
			Donate(donation);
		}
		else if (input == "Report"){
			cout << "Reporting";
		}
		else if (input == "Logout"){
			cout <<"Logging out";
		}
		else
			cout <<"Enter Valid Input";
		
		}
	}
	void Voter::Password(){
		string temp = "";
		string confirmation_password;
		while( temp != "\n"){
			cout << "Enter old password: ";
			cin >> temp;
			if(this -> user_password == temp){
					cout << "Enter new password: ";
					cin >> temp;
					if(temp.length() > 5 || !std::all_of(temp.begin(), temp.end(), ::isalnum) && temp.find_first_of("0123456789") != std::string::npos){
						cout << "Enter new password again: ";
						cin >> confirmation_password;
						if(temp == confirmation_password){
							this ->user_password = temp;
							break;
						}
					}
			}	
			else
				cout << "Invalid data";
		}
	}

	void Voter::Update(){
		string temp;
		int temp_num;
		cout << "Current last name is " << this->LastName << ". Enter Last Name: ";
		cin >> temp;
		if( temp != "\n")
			this->LastName = temp;
		cout << "Current first name is " << this->FirstName << ". Enter First Name: ";
		cin >> temp;
		if( temp != "\n")
			this->FirstName = temp;
		cout << "Current age is " << this->Age << ". Enter Age: ";
		cin >> temp_num;
		if(temp_num > 0)
			this->Age = temp_num;
		cout <<"Current House Number is: " << this->StreetNumber << ". Enter House Number: ";
		cin >> temp;
		if(temp_num > 0)
			this->StreetNumber = temp_num;
		cout <<"Current Street Name is: " << this->StreetName << ". Enter Street Name: ";
		if(temp != "\n"){
			cin.ignore();
			getline(cin,temp);
			this->StreetName = temp;
		}
		cout <<"Current Town is: " << this->Town << ". Enter Town name";
		if(temp != "\n"){
			this->Town = temp;
			cin.ignore();
			getline(cin,temp);
		}
		cout <<"Current Zip Code is: "<< ZipCode << ". Enter new Zip Code";
		this->ZipCode = updateZipCode();
		
	}
	void Voter::Donate(float amount){
	float total = AmountDonated + amount;
	if(amount >= 0){
		if(total < 2700)
			AmountDonated += amount;
		else
			cout << "You cannot donate more than $2700 total\n";
	}
	else
		cout << "You cannot donate a negative amount";
	}
	string Voter::updateZipCode(){
		string zipCode = "1";
		while(zipCode.length() != 5 || !std::all_of(zipCode.begin(), ZipCode.end(), ::isdigit)){
			cout << "Enter a ZipCode containing 5 digits";
			cin >> zipCode;
			if(zipCode == "\n")
				return this->ZipCode;
		}
	}

	string Voter::updateUserid(){
		string new_userid = "[empty]";
		int string_length = 0;
		do{
			cout << "input a new userID: ";
			cin >> new_userid;
			string_length = new_userid.length();
			if(new_userid == "\n")
				return this->Userid;
		} while(string_length > 11 || string_length < 4 || !std::all_of(new_userid.begin(), new_userid.end(), ::isalnum));
		return new_userid;
	}
	void Voter::View(){
		cout << "\nLogin Information:\n" << "Userid: " << this->Userid << " Password: " << this->user_password << endl;
		cout << "\nDonor Info:\n" << this->FirstName << " "<< this->LastName << ": " <<  "age "  << this->Age << "\n";
		cout << this->StreetNumber << " " << this->StreetName << endl;
		cout << this->Town << " " << this->ZipCode << "\n";
		cout << "Current Amount Donated:" <<  setprecision (2) << fixed << " $"  <<this->AmountDonated << "\n\n";
	}

	void Voter::Report(){
		cout << setprecision (2) << fixed << LastName <<  " $"  <<AmountDonated << "\n\n";
	}
	string Voter::toString(){
	string ansr = this->LastName + ","+ this->FirstName +"," + this->Userid +
	"," +  this->user_password + "," + this->Age + "," + this->StreetNumber +
	"," + this->StreetName + "," + this->Town + "," + this->ZipCode + "," +
	this->AmountDonated;
	return ansr;
}
