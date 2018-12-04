#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <vector>
#include <iostream>
class Node;

unsigned int setTime(std::string Time_val){
            const char* temp = Time_val.c_str();
            char m = '\0';
            unsigned int hour = 0;
            unsigned int min = 0;
            printf("%s\n", temp);
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
        Flight(std::string start, std::string end, int mon, std::string dest){
            arrival = setTime(start);
            departure = setTime(end);
            cost = mon;
            destination = dest;
        }
};

class Node{
    public:
        Node* prev = NULL;
        std::string Name = "[empty]";
        std::vector<Flight*> flights;
        unsigned int arrival = 0;
        float cost = 0;
        unsigned int visited = 0;
        Node(std::string str){
            Name = str;
        }
};

#endif
