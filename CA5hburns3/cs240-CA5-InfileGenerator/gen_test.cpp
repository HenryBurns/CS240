#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <iomanip>
using namespace std;

const string city_filename = "city_list.txt";
const unsigned int num_cities = 250; // Don't make this larger than the number of cities in the file
const unsigned int num_flights = 500;
const unsigned int minutes_in_a_day = 24 * 60;
const unsigned int max_flight_time = 180;

string str_time(unsigned int mins) {
    ostringstream ss;
    unsigned int hour, min;
    string ampm = "am";
    hour = mins / 60;
    min = mins % 24;
    if (hour == 0) hour = 12;
    if (hour > 12) {
        hour -= 12;
        ampm = "pm";	
    }
    ss << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << min << ampm;
    return(ss.str());
}

int main(int argc, char **argv) {
    string city;
    vector<string> city_vector;
    ifstream city_file(city_filename);
    if (!city_file.is_open()) {
        cerr << "Could not open city file: " << city_filename << endl; 
	exit(1);
    }	 
    while (getline(city_file, city)) 
        city_vector.push_back(city);
    city_file.close();

    random_shuffle(city_vector.begin(), city_vector.end());   
    city_vector.erase(city_vector.begin() + num_cities, city_vector.end());

    int city1, city2, start_time, duration, end_time; 
    for (int i=0; i<num_flights; i++) {
        city1 = rand() % num_cities; 
        while ((city2 = rand() % num_cities) == city1); 
	start_time = rand() % (minutes_in_a_day - 3) + 1;
	duration = rand() % max_flight_time + 1;
	end_time = start_time + duration;
	if (end_time >= minutes_in_a_day)
            end_time = minutes_in_a_day - 1;
	cout << city_vector[city1] << " " << city_vector[city2] << " " 
	     << str_time(start_time) << " " << str_time(end_time) << endl;
    }
}
