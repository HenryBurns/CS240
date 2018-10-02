#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

	LLC(){
		first = nullptr;
		last = nullptr;
	}

	LLC(LLC const &other){
		NODE* other_temp = other.first;
		NODE* prev;
		while(other_temp != null){
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

	~LLC(){
		NODE* temp = first;
		while(temp != nullptr){
			first = temp ->next;
			delete(temp);
			temp = first;
		}
	}

	bool contains(const std::string &val){
		NODE* temp = first;
		while(temp != nullptr){
			if(temp->data == val)
				return true;
			temp = temp -> next;
		}
		return false;
	}

	bool insert(const std::string &value){
		NODE* temp = new NODE;
		last -> next = temp;
		temp -> data = value;	
	}

	void remove(const std::string &value){
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

	void shuffle(){
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

	void head(int n){
		
	}

	std::string tail(){

	}

	void join(LLC other){

	}

	operator=(const LLC &other){
		LLC(other);
		delete(other);
	}

	operator+(const LLC &){

	}

	friend operator<<(std::ostream &){

	}

	operator+=(int n){

	}

