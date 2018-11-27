#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <vector>
#include <iostream>
class Node;

int setTime(std::string Time_val){
            std::cout << "Input Time: " << Time_val << std::endl;
            const char* temp = Time_val.c_str();
            char m = '\0';
            int hour = 0;
            int min = 0;
            std::cout << "Starting scan" << std::endl;
            printf("%s\n", temp);
            sscanf(temp, "%u:%u%cm", &hour, &min, &m);
            std::cout << "Hour: " << hour << std::endl;
            std::cout << "Min: " << min << std::endl;
            if(m == 'p')
                hour += 12;
            if((hour %12) == 0)
                hour -= 12;
            int val = (hour * 100) + min;
            std::cout << "Returning int: " << val << std::endl;
            return val;
        }
class Flight{
    public:
        std::string destination = "[empty]";
        Node* destination_node;
        unsigned int cost = 0;
        unsigned int arrival = 0 ;
        unsigned int departure = 0;
        Flight(){}
        Flight(std::string start, std::string end, int mon){
            arrival = setTime(start);
            departure = setTime(end);
            cost = mon;
        }
};

class Node{
    public:
        std::string Name = "[empty]";
        std::vector<Flight*> flights;
        Node(std::string str){
            Name = str;
        }
};

#endif
