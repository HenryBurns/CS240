#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "node.hpp"

int main(int argc, char* argv[]){
    std::ifstream file;
    file.open(argv[1]);
    std::string departure_city;
    std::string arrival_city;
    std::string arrival_time;
    std::string departure_time;
    //std::vector<Node*> graph;
    std::unordered_map<std::string, Node*> getter;
    Node* temp_node;
    Flight* temp_flight;
    while(file >> departure_city >> arrival_city >> arrival_time >> departure_time){
        if(getter.find(departure_city) == getter.end()){
            temp_node = new Node(departure_city); 
            getter[departure_city] = temp_node;
        } 
        temp_flight = new Flight(arrival_time, departure_time, 0);
        getter[departure_city]->flights.push_back(temp_flight);

    }
}
