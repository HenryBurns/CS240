#ifndef VOTERDB_H
#define VOTERDB_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Voter.h"
using namespace std;


class VoterDB{
	public:
		string filename;
		int  user_id, max_voters;
		int current_num_voters;
		Voter** VoterList;
		VoterDB(string filename, int max_number_of_voters);
		VoterDB(int max_number_of_voters);
		~VoterDB();
		bool LoggedIn();
		void NewVoter();
		void Report();
		void Save(string filename);
		void load_file();
		void initiateLoop();
};
#endif
