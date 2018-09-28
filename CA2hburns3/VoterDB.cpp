#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "VoterDB.h"
using namespace std;

class VoterDB{
		//constructor to set the filename and dynamic array 
		VoterDB(string filename, int max_number_of_voters){
			//set the name of the csv file		string filename;
			string user_id = "[empty}";
			string password = "[empty]";
			int max_voters = max_number_of_voters;
			int current_num_voters;
			this->filename = filename;
			//dynamically allocate the max
			this->max_voters = max_number_of_voters;
			VoterList = new Voter[max_number_of_voters];
			//declare a counter that checks if you pass max voters
			int cntr  = 0;
			//declare a stream to process the file
			//ifstream infile("./ActiveVoters.csv"); 
			string line;

			//while(cntr < max_number_of_voters && getline(infile, line)){
				//stringstream strstr(line);
				//TODO process each line and fill the voter array
				//cntr++;
			//}
		}
		Voter* VoterList;

		void initiateLoop(){
			string input = "";
			while(true){
				cin >> input;
				if(input == "Login"){
					cout << "Login";
				}
				if(input == "New"){
					cout << "New";
				}
				if(input == "Report"){
					cout << "Report";
				}
				if(input == "Save"){
					cout << "Save";
				}
				if(input == "Load"){
					cout << "Load";
				}
				if(input == "Quit"){
					break;
				}
				else
					cout << "Enter valid input.\n";
			}
		}
	bool fileExists(const std::string& filename)
	{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
	    {
        return true;
	    }
    return false;
	}


	void Save(string filename){
	int i = 0;
	if(fileExists(filename){
		cout << "This file already exists, do you want to overwrite it? Y/N\n";
		string ansr;
		cin >> ansr;
		if(ansr.find('y') != std::string::npos){
			ofstream csv_writer;
			csv_writer.open(filename);
			for(i = 0; i <current_num_voters; i++){
				ofstream << VoterList[i].toString();
			}
		}
	}

