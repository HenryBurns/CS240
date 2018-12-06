#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
class Node;

unsigned int setTime(std::string Time_val){
    const char* temp = Time_val.c_str();
    char m = '\0';
    unsigned int hour = 0;
    unsigned int min = 0;
    sscanf(temp, "%u:%u%cm", &hour, &min, &m);
    if(m == 'p')
        hour += 12;
    if((hour %12) == 0)
        hour -= 12;
    unsigned int val = (hour * 100) + min;
    return val;
}



class Flight{
    public:
        std::string destination = "[empty]";
        Node* destination_node = NULL;
        float cost = 0;
        unsigned int arrival = 0 ;
        unsigned int departure = 0;
        Flight(){}
        Flight(std::string arive, std::string depart, float mon, std::string dest){
            arrival = setTime(arive);
            departure = setTime(depart);
            cost = mon;
            destination = dest;
        }
};

void printFlight(Flight* flight){
    unsigned int hour = 0;
    unsigned int min = 0;
    hour = flight->departure/100;
    min = flight->departure%100;
    bool p = false;
    if(hour / 12 == 1)
        p = true;
    if(hour == 0){
        hour = 12;
        p = false;
    }
    if(p){
        hour -= 12;
    }
    std::cout << "Departure: ";
    std::cout << hour; 
    std::cout <<  ":" << std::setfill('0') << std::setw(2) << std::fixed  << std::setprecision(2) << min;
    if(p)
        std::cout << "pm ";
    else
        std::cout << "am";

    hour = flight->arrival/100;
    min = flight->arrival%100;

    p = false;
    if(hour / 12 == 1){
        p = true;
        hour -= 12;
    }
    if(hour == 0)
        hour = 12;
    std::cout << " Arrival: "<< hour << ":"  << std::setfill('0') << std::setw(2) << std::fixed  << std::setprecision(2) << min;
    if(p)
        std::cout << "pm ";
    else
        std::cout << "am";

    std::cout << " Cost: $" << flight->cost << std::endl;
}
class Node{
    public:
        Node* prev = NULL;
        std::string Name = "[empty]";
        std::vector<Flight*> flights;
        Flight* prev_flight;
        unsigned int arrival = 0;
        float cost = 0;
        unsigned int visited = 0;
        Node(std::string str){
            Name = str;
        }
};

#endif
