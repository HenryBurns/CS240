#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "VoterDB.h"
#include "Voter.h"

//constructor to set the filename and array 
VoterDB::VoterDB(std::string newfilename, int max_number_of_voters){
	//set the name of the csv file		
	cout << "Starting Constructor" << endl;
	this->starting_filename = newfilename;
	this ->max_voters = max_number_of_voters;
	this -> current_num_voters = 0;
	load_file();
	cout << "Loaded File" << endl;
	//dynamically allocate the max
	this->max_voters = max_number_of_voters;
	VoterList = new Voter*[max_number_of_voters];
	}
VoterDB::VoterDB(int max_number_of_voters){
	//set the name of the csv file		
	this->starting_filename = "[empty]";
	this ->max_voters = max_number_of_voters;
	this -> current_num_voters = 0;
	//dynamically allocate the max
	VoterList = new Voter*[max_number_of_voters];
	}
VoterDB::~VoterDB(){
	for(int i = 0; i < current_num_voters; i++)
		delete(VoterList[i]);
	}
void VoterDB::initiateLoop(){
	std::string input = "";
	while(true){
		cout << "Enter Input: choose from Login, New, Report, Save, Load, and Quit" << endl;
		cin >> input;
		if(input == "Login"){
			if(LoggedIn()){
				cout << "Logged in." << endl;
				VoterList[user_id]->EnterVoterMenu();	
			}
		}
		else if(input == "New"){
			NewVoter();
		}
		else if(input == "Report"){
			Report();
		}
		else if(input == "Save"){
			cout << "What file would you like save to?" <<endl;
			cin >> starting_filename;
			Save(starting_filename);
		}
		else if(input == "Load"){
			load_file();
		}
		else if(input == "Quit"){
			break;
		}
		else
			std::cout << "Enter valid input.\n";
	}
}
bool VoterDB::LoggedIn(){
	cout << "Enter a username: ";
	string username;
	cin >> username;
	cout << "\nEnter a password: \n";
	string password;
	cin >> password;
	cout << "Checking passwords against users";
	for(int i = 0; i < this->current_num_voters; i++){
		cout << "Voter Index: " << i << endl;
		if(VoterList[i] ->Userid == username && VoterList[i] ->user_password == password){
			cout << "Found a match on Username and password";
			this->user_id = i;
			return true;
			}
	}
	cout << "Found no matches";
	return false;
}
void VoterDB::Report(){
	float sum = 0;
	for(int i = 0; i < current_num_voters; i++){
		sum += VoterList[i]->AmountDonated;
	}
	cout << "Number of Voters: " << current_num_voters << " Current Amount Donated:" <<  setprecision (2) << fixed << " $"  << sum << "\n\n";
}

void VoterDB::NewVoter(){
	std::string username;
	std::string line;
	std::string temp;
	std::string pass;
	bool username_found = false;
	if(current_num_voters < max_voters){
		cout << "Enter a username.\n";
		cin >> username;
			for(int i = 0; i < current_num_voters; i++){
				if(VoterList[i] -> Userid == username){	
					username_found = true;
					cout << "Username was found!";
					break;
				}
			}

		if(username_found)
			cout << "\nThat username is taken, returning to menu\n";
		else{
			cout << "\nCurrent num voters: " << current_num_voters << endl;
			VoterList[current_num_voters] = new Voter();
			if( VoterList[current_num_voters] == nullptr)
				cout << "WHY THE FUCK " << endl;
			VoterList[current_num_voters]->Update();
			VoterList[current_num_voters]->Userid = VoterList[current_num_voters]->setUserid(username);
			VoterList[current_num_voters]->setNewPassword();
			current_num_voters++;
		}
	}
	else
		cout << "No new Voters can be created.\n";
}
void VoterDB::Save(std::string filename){
	int i = 0;
	Voter* temp = new Voter();
	std::ifstream file(filename);
	string temp_string = "";
	if(file){
			file.close();
			std::cout << "This file already exists, do you want to overwrite it? Y/N" << endl;
			std::string ansr;
			cin >> ansr;
			if(ansr.find('y') != std::string::npos){
				ofstream csv_writer(filename);
				if(!csv_writer)
					cout << "OFSTREAM NULL";
				cout << "opening csv_writer" << endl;
				//csv_writer.open(filename);
				for(i = 0; i <current_num_voters; i++){
					cout << "in for loop \n";
					cout << "Starting temp" << endl;
					temp =  VoterList[i];
					stringstream donation;
					cout << "Amound Donated: " << temp->AmountDonated << endl;
					donation << fixed << setprecision(2) << temp->AmountDonated;
					cout << "i: " << i << ". temp: " << temp << endl;
					csv_writer << temp->LastName << "," << temp->FirstName << ","<< temp->Userid << "," <<  temp->user_password << "," << temp->Age << "," <<  temp->StreetNumber << "," << temp->StreetName << ","  << temp->Town << "," << temp->ZipCode << "," << donation.str() << "," << "\n";
					if(temp != nullptr)
						csv_writer << temp_string;
					else
						cout << "NULLPTR!!!";
				}
			}
		}
	else{
		ofstream csv_writer(filename);
		//csv_writer.open(filename);
		for(i = 0; i <current_num_voters; i++){
			cout << "FILE NOT FOUND" << endl;
			Voter* temp = VoterList[i];
			stringstream donation;
		    donation << fixed << setprecision(2) << temp->AmountDonated;
			csv_writer << temp->LastName << "," << temp->FirstName << ","<< temp->Userid << "," <<  temp->user_password << "," << temp->Age << "," <<  temp->StreetNumber << "," << temp->StreetName << ","  << temp->Town << "," << temp->ZipCode << "," <<donation.str() << "," << "\n";
		}
	}
}

	void VoterDB::load_file(){
		string filename;
		cout << "would you like to enter a file name y/n (no will use the command line arg provided)" <<endl;
		string ansr;
		cin >> ansr;
		if(ansr.find('y') != std::string::npos){
			cout << "Enter a file name (with the .csv extension): " << endl;
			cin >> filename;
		}
		else{
			cout << "There is a file " << endl;
			filename = starting_filename;
		}
		ifstream csv_reader(filename);
		csv_reader >> std::noskipws;
		int cntr = 0;
		string line;
		cout << "Loading line from CSV" << endl;
		while(cntr < max_voters && getline(csv_reader, line)){
			if (line.find(',') != std::string::npos){
				if(VoterList != nullptr){
					cout << "PTR: " << VoterList[cntr] << endl;
					VoterList[cntr] = new Voter(line);
					cout << "TEST" << endl;
					cntr++;
				}
				else{
					VoterList = new Voter*[max_voters];
					cout << "PTR: " << VoterList[cntr] << endl;
					VoterList[cntr] = new Voter(line);
					cout << "TEST" << endl;
					cntr++;
				}
			}
	}
		current_num_voters = cntr;
		cout << "Num Voters: " << current_num_voters <<endl;
}
