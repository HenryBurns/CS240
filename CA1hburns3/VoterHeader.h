#include <string>
using namespace std;
void updateInputs(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode);
void newInputs(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode, float &AmountDonated);
void View(string &Lastname, string &FirstName, int &Age, int &StreetNumber, string &StreetName, string &Town, string &ZipCode, float &AmountDonated);
float donate(float amount, float addition);
void report(string &Lastname, float &AmountDonated);
