#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include "node.hpp"

void anySearch(std::unordered_map<std::string, Node*> &getter, std::string departure_city, std::string arrival_city, std::queue<Node*> &frontier, unsigned int dept_time){ //----------------------------------------------------------any--------------------------------
            frontier.push(getter[departure_city]);
            Node* temp2 = getter[arrival_city];
            Node* temp  = getter[departure_city];
            bool trap = true;
            std::cout << "Entered any" << std::endl;
            while(!frontier.empty()){
                temp = frontier.front();
                temp->visited = 2;
                frontier.pop();
                for(unsigned int i = 0; i < temp->flights.size(); i++){
                    Node* k = getter[temp->flights[i]->destination];
                    if(k != NULL){
                        std::cout << "Entered K " << std::endl;
                        Node* iter = k; 
                        //Node iter = *((*i)->destination_node);
                        if(iter->visited < 1 && temp->flights[i]->departure >= dept_time){
                            std::cout << "Entered next" << std::endl;
                            iter->visited = 1;
                            iter->prev = temp;
                            iter->cost = iter->prev->cost + temp->flights[i]->cost; 

                            //if(iter->prev != temp)
                            //update everything
                            //if(iter->arrival == 0)
                                //iter->arrival = temp->flights[i]->arrival;
                            //else
                            //    iter->arrival = std::min(iter->arrival, temp->flights[i]->arrival);
                            std::cout << "Current: " << iter->Name << std::endl;
                            std::cout << "PREV: " << iter->prev->Name <<std::endl;

                            if(iter->cost == 0){
                                iter->cost = iter->prev->cost + temp->flights[i]->cost;
                                std::cout << "Prev cost name " << iter->prev->Name << std::endl;
                            }
                            //else
                            //    iter->cost = std::min(iter->cost, iter->prev->cost + temp->flights[i]->cost);
                            //check if we hit the end
                            if(iter->Name.compare(arrival_city) == 0){
                                iter->prev = temp;
                                std::cout << iter->prev->Name <<std::endl;
                                //std::cout << "2 past " << iter->prev->prev->Name << std::endl;
                                while(!frontier.empty())
                                    frontier.pop();
                                break;
                            }
                            frontier.push(k);
                        }
                    }
                }
            }
            std::cout << "Arrival city: " << arrival_city << std::endl;
            std::cout << "Departing city: " << departure_city << std::endl;
            temp = getter[departure_city];
            temp2 = getter[arrival_city];
            std::cout << "Total cost: $" << temp2->cost << std::endl;
            while(temp != temp2){
                if(temp2 == NULL){
                    std::cout << "This node cannot be reached" << std::endl;
                    trap = false;
                    break;
                }
                std::cout << "Tracing Back: " << temp2->Name << std::endl;
//                }
//                else {std::cout << "Temp is Null" << std::endl; }
                temp2 = temp2->prev;
            }
            if(trap)
                std::cout << "Tracing Back LAST: " << temp2->Name << std::endl;
            //-----------------------------------------------------------------any on the return--------------------------------------
            return;
}

int main(int argc, char* argv[]){
    std::ifstream file;
    file.open(argv[1]);
    std::string departure_city;
    std::string arrival_city;
    std::string arrival_time;
    std::string departure_time;
    //std::vector<Node*> graph;
    std::string temp_string;
    float cost;
    std::unordered_map<std::string, Node*> getter;
    Node* temp_node;
    Flight* temp_flight;
    while(file >> departure_city >> arrival_city >> departure_time >> arrival_time >> temp_string){
        std::cout << "Departure: " << departure_city << ". Arrival: " << arrival_city << std::endl;
        cost = std::stof(temp_string.substr(1,temp_string.size()));
        if(getter[departure_city] == NULL){
            temp_node = new Node(departure_city); 
            getter[departure_city] = temp_node;
        } 
        if(getter[arrival_city] == NULL){
            temp_node = new Node(arrival_city); 
            getter[arrival_city] = temp_node;
        } temp_flight = new Flight( arrival_time,departure_time, cost, arrival_city);
        temp_flight->destination_node = getter[arrival_city];
        getter[departure_city]->flights.push_back(temp_flight);
        
    }
    std::cout << "Enter a departure city." << std::endl;
    std::cin >> departure_city;
    std::cout << "Enter a destination city." << std::endl;
    std::cin >> arrival_city;
    std::cout << "Departure:" << departure_city << ". Arrival city: " << arrival_city << " $" << cost<< std::endl;
    std::cout << "Enter the earliest acceptable departure time." << std::endl;
    std::cin >> departure_time;
    unsigned int dept_time = setTime(departure_time);
    std::string inp;
    std::string any = "any";
    std::string Earliest = "earliest";
    std::string Least = "cheapest";
    std::queue<Node*> frontier;
    Node* temp2 = getter[arrival_city];
    Node* temp  = getter[departure_city];
    auto end = temp;
    int imSorry = 0;
    while(true){
        std::cout << "Type either 'any', 'earliest', or 'cheapest'" << std::endl;
        std::cin >> inp;
        std::cin.ignore();
        if(inp.compare(any) == 0){
            anySearch( getter, departure_city, arrival_city, frontier, dept_time);
            for(auto i = getter.begin(); i != getter.end(); ++i){
                auto var = i->second;
                var-> visited = 0;
                var-> arrival = (unsigned int)-1;
                var-> cost = 0;
                var-> prev = NULL;
            }
            std::cout << "Enter a new departing time: " <<std::endl;
            std::cin >> dept_time;
            anySearch( getter, arrival_city, departure_city, frontier, dept_time);
        }
        else if(inp.compare(Earliest)==0){//------------------------------------------------------------Earliest------------------------
            //TODO find the earliest path
            std::cout << "Entered earliest" << std::endl;

            while(!frontier.empty()){
                temp = frontier.front();
                std::cout << "TEMP: " << temp << std::endl;
                std::cout << "TEMP: " << temp->Name << std::endl;
                temp->visited = 2;
                frontier.pop();
                for(unsigned int i = 0; i < temp->flights.size(); i++){
                    Node* k = getter[temp->flights[i]->destination];
                    if(k != NULL){
                        Node* iter = k; 
                        //Node iter = *((*i)->destination_node);
                        std::cout << "Time:  " << iter->arrival << std::endl;
                        std::cout << "Time2:  " << temp->arrival << std::endl;
                        if( temp->flights[i]->departure >= dept_time && (temp->flights[i]->departure >= temp->arrival || iter->arrival >= 2600)){
                            iter->visited = 1;
                            //update everything
                            std::cout << "Time:  " << iter->arrival << std::endl;
                            if(iter->arrival >= 2600){
                                std::cout << "Iter: " << iter->Name << ". " << "First time" << std::endl;
                                iter->arrival = temp->flights[i]->arrival;
                                iter->prev = temp;
                                frontier.push(k);
                            }
                            else{
                                std::cout << "Else: " << iter->Name << std::endl;
                                std::cout << "Other arrival: " <<  temp->flights[i]->arrival << std::endl;
                                iter->arrival = std::min(iter->arrival, temp->flights[i]->arrival);
                                if(iter->arrival ==  temp->flights[i]->arrival){
                                    iter->prev = temp;
                                    frontier.push(k);
                                }
                            }
                            std::cout << "Time:  " << iter->arrival << std::endl;

                            //if(iter->cost == 0){
                            //    iter->cost = iter->prev->cost + temp->flights[i]->cost;
                            //    std::cout << "Prev cost name " << iter->prev->Name << std::endl;
                            //}
                            //else
                            //    iter->cost = std::min(iter->cost, iter->prev->cost + temp->flights[i]->cost);
                            //check if we hit the end
                            }
                        }
                    else 
                        std::cout << "WTF" << std::endl;
                    }
                }
            std::cout << "Arrival city: " << arrival_city << std::endl;
            std::cout << "Departing city: " << departure_city << std::endl;
            temp = end;
            std::cout << "Temp2: " << temp2->Name << ". Temp2 arrival time: " << temp2->arrival << std::endl;
            temp2 = getter[arrival_city];
            while(temp != temp2){
                if(temp == NULL){
                    std::cout << "This node cannot be reached" << std::endl;
                    break;
                }
                std::cout << "Tracing Back: " << temp2->Name << std::endl;
                temp2 = temp2->prev;
            }
            std::cout << "Tracing Back LAST: " << temp2->Name << std::endl;
            for(auto i = getter.begin(); i != getter.end(); ++i){
                i->second->visited = 0;
                i->second->cost = 0;
                i->second->arrival= (unsigned int) -1;
            }
            frontier.push(getter[arrival_city]);
            //-------------------------------------------------------------end of earliest---------------------------------------------
            break;
        }
        else if(inp.compare(Least)==0){
            //TODO get the cheapest path
            std::cout << "Entered earliest" << std::endl;

            while(!frontier.empty()){
                temp = frontier.front();
                std::cout << "TEMP: " << temp << std::endl;
                std::cout << "TEMP: " << temp->Name << std::endl;
                temp->visited = 2;
                frontier.pop();
                for(unsigned int i = 0; i < temp->flights.size(); i++){
                    Node* k = getter[temp->flights[i]->destination];
                    if(k != NULL){
                        Node* iter = k; 
                        //Node iter = *((*i)->destination_node);
                        std::cout << "Time:  " << iter->arrival << std::endl;
                        std::cout << "Time2:  " << temp->arrival << std::endl;
                        if( temp->flights[i]->departure >= dept_time && (temp->flights[i]->departure >= temp->arrival || iter->arrival >= 2600)){
                            iter->visited = 1;
                            //update everything
                            std::cout << "Time:  " << iter->arrival << std::endl;
                            if(iter->arrival >= 2600){
                                std::cout << "Iter: " << iter->Name << ". " << "First time" << std::endl;
                                iter->arrival = temp->flights[i]->arrival;
                                iter->prev = temp;
                                frontier.push(k);
                            }
                            else{
                                std::cout << "Else: " << iter->Name << std::endl;
                                std::cout << "Other arrival: " <<  temp->flights[i]->arrival << std::endl;
                                iter->arrival = std::min(iter->arrival, temp->flights[i]->arrival);
                                if(iter->arrival ==  temp->flights[i]->arrival){
                                    iter->prev = temp;
                                    frontier.push(k);
                                }
                            }
                            std::cout << "Time:  " << iter->arrival << std::endl;

                            //if(iter->cost == 0){
                            //    iter->cost = iter->prev->cost + temp->flights[i]->cost;
                            //    std::cout << "Prev cost name " << iter->prev->Name << std::endl;
                            //}
                            //else
                            //    iter->cost = std::min(iter->cost, iter->prev->cost + temp->flights[i]->cost);
                            //check if we hit the end
                            }
                        }
                    else 
                        std::cout << "WTF" << std::endl;
                    }
                }
            std::cout << "Arrival city: " << arrival_city << std::endl;
            std::cout << "Departing city: " << departure_city << std::endl;
            temp = end;
            std::cout << "Temp2: " << temp2->Name << ". Temp2 arrival time: " << temp2->arrival << std::endl;
            temp2 = getter[arrival_city];
            while(temp != temp2){
                if(temp == NULL){
                    std::cout << "This node cannot be reached" << std::endl;
                    break;
                }
                std::cout << "Tracing Back: " << temp2->Name << std::endl;
                temp2 = temp2->prev;
            }
            std::cout << "Tracing Back LAST: " << temp2->Name << std::endl;
            break;

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


