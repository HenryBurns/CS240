#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "LinkedList.h"
//works
	LLC::LLC(){
		first = nullptr;
		last = nullptr;
	}
//works
	LLC::LLC(LLC const &other){
		NODE* other_temp = other.first;
		NODE* prev;
		while(other_temp != NULL){
			NODE* temp_node = new NODE;
			if(prev != nullptr)
				prev ->next = temp_node;
			if(first == nullptr)
				first = temp_node;
			temp_node ->data = other_temp -> data;
			prev = temp_node;
			last = temp_node;
			other_temp = other_temp -> next;
		}
	}

	LLC::~LLC(){
		NODE* temp = first;
		while(temp != nullptr){
			first = temp ->next;
			delete(temp);
			temp = first;
		}
	}
//works
	bool LLC::contains(const std::string &val){
		NODE* temp = first;
		while(temp != nullptr){
			if(temp->data == val)
				return true;
			temp = temp -> next;
		}
		return false;
	}
//works
	bool LLC::insert(const std::string &value){
		NODE* temp = new NODE;
		if(last == nullptr){
			first = temp;
			last = temp;
		}
		else{
			last -> next = temp;
			last = last->next;
		}
		temp -> data = value;	
		return true;
	}
//works
	void LLC::remove(const std::string &value){
		if(first == nullptr)
			return;
		NODE* temp = first;
		while(temp != nullptr && first -> data == value){
			first = first -> next;
			delete(temp);
			temp = first;
		}
		NODE* prev = temp;
		if(temp != nullptr){
			temp = temp -> next;
			while(temp != nullptr){
				if(temp -> data == value){
					prev -> next = temp -> next;
					delete temp;
				}
				else{
					prev = temp;
				}
				temp = prev -> next;
			}
		}
		last = prev;
	}
//TODO
	void LLC::shuffle(){
		
	}

//works
	void LLC::head(int n){
		NODE* temp = first;
		std::cout << "[";
		for(int i = 0; i < n-1; i++){
			if(temp == nullptr){
				std::cout << "NULL]\n";
				return;
			}
			else{
				std::cout<< temp->data << ", ";
				temp = temp->next;
			}
		}
		std::cout << temp->data << "]\n";
		return;
	}

	std::string LLC::tail(){
	std::cout << last->data << std::endl;
	return last ->data;
	}

//works
	void LLC::join(LLC &other){
		NODE* temp = other.first;
		if(last != nullptr){
			std::cout << "Last: " << last << " Last Data: " << last->data <<std::endl;
			while(temp != nullptr){
				std::cout <<"Data: " <<temp->data <<std::endl;
				NODE* new_node = new NODE;
				new_node->data = temp ->data;
				last ->next = new_node;
				last = new_node;
				temp = temp-> next;
			}
			last->next = nullptr;
		}
		else{
			temp = other.first;
			while(temp != nullptr){
				last ->next = temp;
				last = temp;
			}
			std::cout << "hit other" << std::endl;
		}
		return;
}
//works
	int LLC::len(){
		NODE* temp = first;
		int cntr = 1;
		while(temp != last){
			temp = temp -> next;
			cntr++;
		}
		return cntr;
	}
//works
	LLC& LLC::operator=(const LLC& other){
		if(this != &other){
			NODE* iter = first;
			NODE* thing;
				while(iter != nullptr){
						thing = iter->next;
						delete(iter);
						iter = thing;
				}
				iter = other.first;
				NODE* temp = new NODE;
				first = temp;
				if(iter == nullptr)
					first = nullptr;
				while(iter != nullptr){
					temp->data = iter-> data;
					last = temp;
					temp = new NODE;
					last->next = temp;
					iter = iter-> next;
				}
				last ->next = nullptr;
		}
		return *this;
	}
//TODO make
	std::ostream& operator<<(std::ostream &os, const LLC& to_print){
		os << "test" << std::endl;
		return os;
	}
//TODO test
	LLC& LLC::operator+(const LLC &other){
		LLC* temp = new LLC(*this);
		temp->last->next = other.first;
		return *temp;
	}

//TODO test
	LLC& LLC::operator+=(int n){
		int length = len();
		n = n%length;
		for(int i = 0; i < n; i++){
			last -> next = first;
			last = last -> next;
			first = first->next;
			last -> next = NULL;
		}	
		return *this;
	}

	NODE* LLC::getFirst(){
			return first;
	}
	NODE* LLC::getLast(){
			return last;
	}
