#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class VoterDB{
	public:
		string filename, user_id, password;	
		Voter[] Voterlist;
		VoterDB(filename, max_number_of_voters);
		bool LoggedIn(string user_id, string password);
		
	private:
