#include <iostream>
#include <string>
#include <sstream>
#include "VoterDB.h"
using namespace std;

int main(int argc, char **argv) {
	cout << "Starting Function" << endl ;
	if(argc > 2){
		int arg1 = stoi(argv[1]);
		string arg2 = argv[2];
		VoterDB* Database = new VoterDB(arg2, arg1);
		cout << "Database has been initiated\n";
		Database -> initiateLoop();
	}else{
		int arg1 = stoi(argv[1]);
		VoterDB* Database = new VoterDB( arg1);
		cout << "Database has been initiated\n";
		Database -> initiateLoop();
	}
   return 0;
}
