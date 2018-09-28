#include <stdio.h>
#include <string>
#include <iostream>
#include "Voter.cpp"
using namespace std;

class VoterDB{
	public:
		string filename, user_id, password;	
		int max_voters;
		Voter* Voterlist;
		VoterDB(string filename, int max_number_of_voters);
		bool LoggedIn(string user_id, string password);
		void NewVoter();
		void Report();
		void Save();
		void Load();
		bool fileExists(const std::string& filename);
};
