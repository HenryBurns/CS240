#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "LinkedList.h"

	LLC::LLC(){
		first = nullptr;
		last = nullptr;
	}

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

	bool LLC::contains(const std::string &val){
		NODE* temp = first;
		while(temp != nullptr){
			if(temp->data == val)
				return true;
			temp = temp -> next;
		}
		return false;
	}

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

	void LLC::shuffle(){
		NODE* temp = first;
		if(temp == nullptr)
			return;
		NODE* next = temp->next;
		first = next;
		next -> next = temp;
		temp-> next = next -> next;
		NODE* prev = first;
		temp = first -> next; 
		next = temp -> next;
		while(next->next != nullptr){
			prev->next = next;
			temp -> next = next -> next;
			next -> next = temp;
			prev = next;
			next = temp -> next;
		}	
		last = next;
	}

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

	void LLC::join(LLC other){
		last ->next = other.first;
		last = other.last;
		return;
	}
	int LLC::len(){
	NODE* temp = first;
	int cntr = 1;
	while(temp != last){
		temp = temp -> next;
		cntr++;
	}
	return cntr;
	}
	LLC& LLC::operator=(const LLC& other){
		if(this != &other){
			LLC ansr = (LLC(other));
			this->first = ansr.first;
			this->last = ansr.last;
			delete(&other);
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream &os, const LLC& to_print){
		os << "test" << std::endl;
		return os;
	}
	LLC& LLC::operator+(const LLC &other){
		LLC* temp = new LLC(*this);
		temp->last->next = other.first;
		return *temp;
	}


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

