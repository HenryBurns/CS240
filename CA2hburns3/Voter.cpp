#include <stdio.h>
#include <bits/stdc++.h> 
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Voter.h"
using namespace std;
Voter::Voter(){
		LastName = "[empty]";
		FirstName= "[empty]";
		Userid = "[empty]";
		user_password = "[empty]";
		Age = -1;
		StreetNumber = 0;
		StreetName = "[empty]";
		Town = "[empty]";
		ZipCode = "-----";
		AmountDonated = 0.0;
	}

Voter::Voter(string& csv_portion){
		istringstream ss(csv_portion);

	   string token;

		getline(ss,token, ',');
		{
	    LastName = token;
		}
		cout << "Lastname: " << LastName << endl;
		getline(ss,token, ',');
		{
	    FirstName = token;
		}
		cout << "Firstname: " << FirstName << endl;
		getline(ss,token, ',');
		{
	    Userid = token;
		}
		cout << "Userid: " << Userid << endl;
		getline(ss,token, ',');
		{
	    user_password = token;
		}
		cout << "User password" << endl;
		getline(ss,token, ',');
		{
		Age = stoi(token);
		}
		cout << "Age: " << Age <<endl;
		getline(ss,token, ',');
		{
		StreetNumber = stoi(token);
		}
		cout << "StreetNumber: " << StreetNumber << endl;
		getline(ss,token, ',');
		{
		StreetName = token;
		}
		cout << "StreetName: " << StreetName << endl;
		getline(ss,token, ',');
		{
		Town  = token;
		}
		cout << "Town: " << Town << endl;
		getline(ss,token, ',');
		{ ZipCode = token; }
		cout << "ZipCode: " << ZipCode << endl;
		ss >> ws;
				getline(ss,token, ' ');
		std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
		token.erase(end_pos, token.end());
		AmountDonated = atof(token.c_str());
		cout << "Amount Donated: " << AmountDonated << endl;
		return;

		//{
		//cout << "TOKEN: " << token;
		//ss >> AmountDonated  = stof(token);
		//}
	}

	bool Voter::EnterVoterMenu(){
	string input = "";
	float donation;
	while(input != "Logout"){
		cout << "Enter Input (Choose from Update, Passwd, View, Donate, Report, and Logout): \n";
		cin >> input;
		//input = transform(input.begin(), input.end(), input.begin(), ::toupper);
		if(input == "Update"){
			cout <<"Updating voter information\n";
			Update();
			}
		else if (input == "Passwd"){
			cout <<"Setting new password\n";
			Password();
			}
		else if (input == "View"){
			cout << "Viewing voter information\n";
			View();
		}
		else if (input == "Donate"){
			cout << "donating to campaign\n Enter amount to donate: ";
			cin >> donation;
			Donate(donation);
		}
		else if (input == "Report"){
			cout << "Reporting\n";
			Report();
		}
		else if (input == "Logout"){
			cout <<"Logging out\n";
			return false;
		}
		else
			cout <<"Enter Valid Input\n";
		
		}
		return false;
	}
	void Voter::Password(){
		string temp = "";
		bool special_char = false;
		string confirmation_password;
		while( temp != "\n"){
			cout << "Enter old password: ";
			cin.ignore();
			cin >> temp;
			if(this -> user_password == temp){
					cout << "Enter new password: \n";
					cin.ignore();
					cin >> temp;
					if(temp.length() > 5 && temp.find_first_of("0123456789") != std::string::npos){
						for(unsigned int i = 0; i < temp.length(); i++){
							if(!isalnum(temp[i]))
									special_char = true;
						}
						if(!special_char)
							continue;		
						cout << "Enter new password again: \n";
						cin >> confirmation_password;
						if(temp == confirmation_password){
							this ->user_password = temp;
							break;
						}
					}
					else{
						cout << "Password did not have the correct specifications" << endl;
			}	
		}
		else
			cout << "Invalid data: Both new passwords must match\n";

	}
}
	void Voter::setNewPassword(){
			string temp;
			string confirmation_password;
			cout << "Enter new password (must contain at least 5 characters, including 1 digit and one special character): \n";
			cin >> temp;
			if(temp.length() > 5 && !std::all_of(temp.begin(), temp.end(), ::isalnum) && temp.find_first_of("0123456789") != std::string::npos){
				cout << "Enter new password again: \n";
				cin >> confirmation_password;
				if(temp == confirmation_password){
					this ->user_password = temp;
				}
				else{
					cout << "Passwords Mismatched, trying agina";
					setNewPassword();
			}
		}
		else{
			cout << "Password did not meet criteria, try again";
			setNewPassword();
		}
}

	void Voter::Update(){
		string temp;
		string templine;
		cout << "\nCurrent last name is " << this->LastName << ". Enter Last Name: ";
		cin.ignore();
		temp = cin.get();
		if( temp != "\n"){
			getline(cin,templine) ;
			this->LastName = temp + templine;
		}
		cout << "\nCurrent first name is " << this->FirstName << ". Enter First Name: ";
		temp = cin.get();
		if( temp != "\n"){
			getline(cin,templine) ;
			this->FirstName = temp + templine;
		}
		cout << "\nCurrent age is " << this->Age << ". Enter Age: ";
		temp = cin.get();
		if(temp != "\n"){
			getline(cin,templine);
			Age = stoi(temp + templine);
		}
		cout <<"\nCurrent House Number is: " << this->StreetNumber << ". Enter House Number: ";
		temp = cin.get();
		if(temp != "\n"){
			getline(cin,templine);
			this->StreetNumber = stoi(temp + templine);
		}
		cout <<"\nCurrent Street Name is: " << this->StreetName << ". Enter Street Name: ";
		temp = cin.get();
		if(temp != "\n"){
			getline(cin,templine);
			this->StreetName = temp + templine;
		}
		cout <<"\nCurrent Town is: " << this->Town << ". Enter Town name: ";
		temp = cin.get();
		if(temp != "\n"){
			getline(cin,templine);
			this->Town = temp + templine;
		}
		cout <<"\nCurrent Zip Code is: "<< ZipCode << ". Enter new Zip Code: ";
		this->ZipCode = updateZipCode();
		return;
	}
	void Voter::Donate(float amount){
	float total = AmountDonated + amount;
	if(amount >= 0){
		if(total < 2700)
			AmountDonated += amount;
		else
			cout << "\nYou cannot donate more than $2700 total\n";
	}
	else
		cout << "\nYou cannot donate a negative amount";
	}
	string Voter::updateZipCode(){
		string temp;
		string rest_of_the_letters;
		string zipCode = "1";
		while(zipCode.length() != 5 || !std::all_of(zipCode.begin(), ZipCode.end(), ::isdigit)){
			cout << "\nEnter a ZipCode containing exactly 5 digits: ";
			temp = cin.get();
			cin >> rest_of_the_letters;
			zipCode = temp + rest_of_the_letters;
			if(zipCode == "\n")
				return this->ZipCode;
		}
		return zipCode;
	}

	string Voter::updateUserid(){
		string new_userid = "[empty]";
		int string_length = 0;
		do{
			cout << "\ninput a new userID: ";
			cin >> new_userid;
			string_length = new_userid.length();
			if(new_userid == "\n")
				return this->Userid;
		} while(string_length > 11 || string_length < 4 || !std::all_of(new_userid.begin(), new_userid.end(), ::isalnum));
		return new_userid;
	}
	
	string Voter::setUserid(string userID){
		string new_userid = userID;
		int string_length = userID.length();
		while(string_length > 11 || string_length < 4 || !std::all_of(new_userid.begin(), new_userid.end(), ::isalnum)){
			cout << "\ninput a new userID that contains 5-10 alpha numeric characters (inclusive) : ";
			cin >> new_userid;
			string_length = new_userid.length();
		} 
		return new_userid;
	}

	void Voter::View(){
		cout << "\nLogin Information:\n" << "Userid: " << this->Userid << " Password: " << this->user_password << endl;
		cout << "\nDonor Info:\n" << this->FirstName << " "<< this->LastName << ": " <<  "age "  << this->Age << "\n";
		cout << this->StreetNumber << " " << this->StreetName << endl;
		cout << this->Town;
		cout << " " << this->ZipCode << "\n";
		cout << "Current Amount Donated:" <<  setprecision (2) << fixed << " $"  <<this->AmountDonated << "\n\n";
	}

	void Voter::Report(){
		cout << setprecision (2) << fixed << LastName <<  " $"  <<AmountDonated << "\n\n";
	}

	
