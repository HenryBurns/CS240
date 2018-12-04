#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
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
        std::cout << "Departure: " << departure_city << ". Arrival city: " << arrival_city << std::endl;
        if(getter[departure_city] == NULL){
            temp_node = new Node(departure_city); 
            getter[departure_city] = temp_node;
        } 
        if(getter[arrival_city] == NULL){
            temp_node = new Node(arrival_city); 
            getter[arrival_city] = temp_node;
        } temp_flight = new Flight(arrival_time, departure_time, 0, arrival_city);
        temp_flight->destination_node = getter[arrival_city];
        getter[departure_city]->flights.push_back(temp_flight);
        
    }
    std::cout << "Enter a departure city." << std::endl;
    std::cin >> departure_city;
    departure_city.erase(std::remove(departure_city.begin(), departure_city.end(), 'n'), departure_city.end());
    std::cout << "Enter a destination city." << std::endl;
    std::cin >> arrival_city;
    arrival_city.erase(std::remove(arrival_city.begin(), arrival_city.end(), 'n'), arrival_city.end());
    std::cout << "Enter the earliest acceptable departure time." << std::endl;
    std::cin >> departure_time;
    unsigned int dept_time = setTime(departure_time);
    std::string inp;
    std::string any = "any";
    std::string Earliest = "earliest";
    std::string Least = "cheapest";
    std::queue<Node*> frontier;
    frontier.push(getter[departure_city]);
    Node* temp  = getter[departure_city];
    std::cout << "temp test " << temp->Name << std::endl;
    Node* temp2 = getter[arrival_city];
    auto end = temp;
    auto start = temp2;
    std::cout << "Temp Before : " <<temp << std::endl;
    while(true){
        std::cout << "Type either 'any', 'earliest', or 'cheapest'" << std::endl;
        std::cin >> inp;
        if(inp.compare(any) == 0){
            std::cout << "Entered any" << std::endl;

            while(!frontier.empty()){
                temp = frontier.front();
                std::cout << "TEMP: " << temp->Name << std::endl;
                temp->visited = 2;
                frontier.pop();
                for(int i = 0; i < temp->flights.size(); i++){
                    Node* k = getter[temp->flights[i]->destination];
                    if(k != NULL){
                        Node* iter = k; 
                        std::cout << "Iter: " << iter->Name << std::endl;
                        //Node iter = *((*i)->destination_node);
                        if(iter->visited < 2 && temp->flights[i]->departure >= dept_time){
                            iter->visited = 1;
                            k->prev = temp;
                            if(iter->prev != temp)
                                std::cout << "Temp prev: " << iter->prev->Name << std::endl;
                            //update everything
                            //if(iter->arrival == 0)
                                //iter->arrival = temp->flights[i]->arrival;
                            //else
                            //    iter->arrival = std::min(iter->arrival, temp->flights[i]->arrival);

                            //if(iter->cost == 0){
                            //    iter->cost = iter->prev->cost + temp->flights[i]->cost;
                            //    std::cout << "Prev cost name " << iter->prev->Name << std::endl;
                            //}
                            //else
                            //    iter->cost = std::min(iter->cost, iter->prev->cost + temp->flights[i]->cost);
                            //check if we hit the end
                            if(iter->Name.compare(arrival_city) == 0){
                                iter->prev = temp;
                                std::cout << "DONE" << " Past: " << iter->prev->Name << std::endl;
                                //std::cout << "2 past " << iter->prev->prev->Name << std::endl;
                                while(!frontier.empty())
                                    frontier.pop();
                                break;
                            }
                            frontier.push(k);
                        }
                    }
                    else
                        std::cout << "WHY IS THIS NULL??? " << std::endl;
                }
            }
            std::cout << "Arrival city: " << arrival_city << std::endl;
            std::cout << "Departing city: " << departure_city << std::endl;
            temp = end;
            std::cout << "Temp: " << temp->Name << std::endl;
            temp2 = getter[arrival_city];
            while(temp != temp2){
//                if(temp == NULL){
//                    std::cout << "This node cannot be reached" << std::endl;
//                    break;
                std::cout << "Tracing Back: " << temp2->Name << std::endl;
//                }
//                else {std::cout << "Temp is Null" << std::endl; }
                temp2 = temp2->prev;
            }
            std::cout << "Tracing Back LAST: " << temp2->Name << std::endl;
            break;
        }
        else if(inp.compare(Earliest)){
            //TODO find the earliest path
        }
        else if(inp.compare(Least)){
            //TODO get the cheapest path
        }
        else{
            std::cout << "Input was not formatted correctly." << std::endl;
        }
    }
    for(auto i = getter.begin(); i != getter.end(); ++i){
        if(i->second != NULL){
            for(auto j = i->second->flights.begin(); j != i->second->flights.end(); ++j)
                delete (*j);
        }
        delete i->second;
    }
}
