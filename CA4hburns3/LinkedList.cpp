#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "LinkedList.h"
//works
	template <class T>
	LLC<T>::LLC(){
		first = nullptr;
		last = nullptr;
	}
//work
	template <class T>
	LLC<T>::LLC(LLC<T> const &other){
		NODE<T>* other_temp = other.first;
		NODE<T>* prev;
		while(other_temp != NULL){
			NODE<T>* temp_node = new NODE<T>;
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

	template <class T>
	LLC<T>::~LLC(){
		NODE<T>* temp = first;
		while(temp != nullptr){
			first = temp ->next;
			delete(temp);
			temp = first;
		}
	}
//works
	template <class T>
	bool LLC<T>::contains(const T &val){
		NODE<T>* temp = first;
		while(temp != nullptr){
			if(temp->data == val)
				return true;
			temp = temp -> next;
		}
		return false;
	}
//works
	template <class T>
	bool LLC<T>::insert(const T &value){
		NODE<T>* temp = new NODE<T>;
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
	template <class T>
	void LLC<T>::remove(const T &value){
		if(first == nullptr)
			return;
		NODE<T>* temp = first;
		while(temp != nullptr && first -> data == value){
			first = first -> next;
			delete(temp);
			temp = first;
		}
		NODE<T>* prev = temp;
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
	template <class T>
	void LLC<T>::shuffle(){
		//generate a random seed
		srand(time(0));
		//create a random number of times to switch elements
		int n = (rand()%40),rand1, rand2;
		std::cout << "Num times: " << n << std::endl;
		//get the length of the list
		int length = len();
		std::cout << "Length: " << length << std::endl;
		//declare temporary pointers
		NODE<T>* temp,*temp2,*temp3, *rand1_prev, *rand2_prev;
		for(int i = 0; i < n; i++){
			//get 2 random node indexes to switch
			rand1 = (rand()%(length))+1;
			rand2 = (rand()%(length))+1;
			std::cout << "Rand1: " << rand1 << ". Rand2: " << rand2 << std::endl;
			//if rand1 = rand2 do nothing
			if(rand1 != rand2){
				temp = first;
				std::cout << "Searching through" << std::endl;
				for(int i = 1; i < std::max(rand1,rand2); i++){
					std::cout << "I: " << i << ". Rand1: " << rand1 << ". Rand2: " << rand2 << std::endl;
					if(i == rand1 -1)
							rand1_prev = temp;
					if(i == rand2-1)
							rand2_prev = temp;
					temp = temp -> next;
				}
				if(rand1 == 1){
						std::cout << "Rand1 is 1. Rand2 prev: " << rand2_prev->data <<std::endl;
						if(rand2 == 2){
							temp = first;
							temp2 = rand2_prev->next->next;
							first = rand2_prev->next;
							first->next = temp;
							temp->next = temp2;
						}
						else{
							temp = first;
							temp2 = rand2_prev->next->next;
							first = rand2_prev->next;
							first->next = temp->next;
							rand2_prev->next=temp;
							temp->next = temp2;
						}
				}	
				else if(rand2 == 1){
						std::cout << "Rand2 is 1. Rand1 prev: " << rand1_prev->data <<std::endl;
						if(rand1 == 2){
							temp = first;
							temp2 = rand1_prev->next->next;
							first = rand1_prev->next;
							first->next = temp;
							temp->next = temp2;
						}
						else{
						std::cout << "rand2 is 1" << std::endl;
						temp = first;
						temp2 = rand1_prev->next->next;
						first = rand1_prev->next;
						first->next = temp->next;
						rand1_prev->next=temp;
						temp->next = temp2;

						}
				}
				else if(rand1 > rand2){
					//goodbye -> next = hello -> next
					std::cout << "Data: " << rand1_prev->data << ". Data2: " << rand2_prev ->data << std::endl;
					if(rand2_prev->next == rand1_prev){
						std::cout << "Case 1: pt 1: Nodes next to each other" << std::endl;
						temp = rand1_prev->next->next;
						temp2 = rand1_prev->next;
						temp3 = rand2_prev->next;
						rand2_prev->next = temp2;
						temp2->next = temp3;
						temp3->next = temp;
					}
					else{

					std::cout << "Case 1: " << std::endl;
					temp = rand1_prev->next->next;
					temp2 = rand2_prev->next->next;
					//save the continuation of the list
					temp3 = rand1_prev->next;
					//save the node to be replaced
					rand1_prev->next = rand2_prev->next;
					rand1_prev->next->next = temp;
					rand2_prev->next = temp3;
					temp3->next = temp2;
					}
				}
				else if(rand1 < rand2){
				std::cout << "Data: " << rand1_prev->data << ". Data2: " << rand2_prev ->data << std::endl;
					if(rand1_prev->next == rand2_prev){
						std::cout << "Case 2: pt1: Nodes next to each other" << std::endl;
						std::cout << "This list " << *this << std::endl;
						std::cout << "rand2 prev: " << rand2_prev->data << std::endl;
						std::cout << "rand2 prev next: " << rand2_prev->next->data << std::endl;
						temp = rand2_prev->next->next;
						if(temp != nullptr)
								std::cout << "Temp: " << temp->data<< std::endl;
						temp2 = rand2_prev->next;
						std::cout << "Temp2: " << temp2->data << std::endl;
						temp3 = rand1_prev->next;
						rand1_prev->next = temp2;
						temp2->next = temp3;
						temp3 ->next = temp;
						std::cout << "first: " << std::endl;
					}
					else{
						std::cout << "Case 2: " << std::endl;
						temp = rand2_prev->next->next;
						temp2 = rand1_prev->next->next;
						rand2_prev->next->next = temp2;
						rand1_prev->next->next = temp;
						temp = rand2_prev->next;
						rand2_prev->next = rand1_prev->next;
						rand1_prev->next = temp;
					}
				}
				std::cout << "Current List: " << *this << std::endl;
			}
		}
		temp = first;
		while(temp != nullptr){
				temp2 = temp;
				temp = temp->next;
	}
		std::cout << "First: " << std::endl;
		std::cout << first->data << std::endl;
		std::cout << "Last: " << std::endl;
		std::cout << last -> data << std::endl;
	last = temp2;
}

//works
	template <class T>
	void LLC<T>::head(int n){
		NODE<T>* temp = first;
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

	template <class T>
	T LLC<T>::tail(){
	std::cout << last->data << std::endl;
	return last ->data;
	}

//works 
	template <class T>
	void LLC<T>::join(LLC<T> &other){
		NODE<T>* temp = other.first;
		if(temp != nullptr){
			std::cout << "Temp: " << temp << " Temp Data: " << temp->data <<std::endl;
			while(temp != nullptr){
				std::cout <<"Data: " <<temp->data <<std::endl;
				NODE<T>* new_node = new NODE<T>;
				new_node->data = temp ->data;
				last ->next = new_node;
				last = new_node;
				temp = temp-> next;
			}
			last->next = nullptr;
		}
		else{
			std::cout << "Other was null" << std::endl;
		}
		return;
}
//works
	template <class T>
	int LLC<T>::len(){
		NODE<T>* temp = first;
		int cntr = 1;
		while(temp != last){
			temp = temp -> next;
			cntr++;
		}
		return cntr;
	}
//works
	template <class T>
	LLC<T>& LLC<T>::operator=(const LLC<T>& other){
		if(this != &other){
			NODE<T>* iter = first;
			NODE<T>* thing;
				while(iter != nullptr){
						thing = iter->next;
						delete(iter);
						iter = thing;
				}
				iter = other.first;
				NODE<T>* temp = new NODE<T>; 
				first = temp;
				if(iter == nullptr)
					first = nullptr;
				while(iter != nullptr){
					temp->data = iter-> data;
					last = temp;
					temp = new NODE<T>; 
					last->next = temp;
					iter = iter-> next;
				}
				last ->next = nullptr;
		}
		return *this;
	}
//works
	template <class T>
	std::ostream& operator<<(std::ostream &os, const LLC<T>& to_print){
		NODE<T>* temp = to_print.first;
		os << "[";
		if(temp == nullptr)
				os << "NULL]";
		while(temp != nullptr){
			if(temp->next !=nullptr)
				os << temp->data << ", ";
			else
				os << temp->data << "]" << std::endl;
			temp = temp->next;
			}
		return os;
	}
//works
	template <class T>
	LLC<T>& LLC<T>::operator+(const LLC<T> &other){
		LLC<T>* new_llc = new LLC<T>();
		new_llc->last = nullptr;
		this->head(this->len());
		std::cout << "length: " << this->len() << std::endl;
		NODE<T>* temp = this->first;
		std::cout << "Temp: " << temp << std::endl;
		std::cout << "first: " << temp->data << std::endl;
		while(temp != nullptr){
				NODE<T>* next = new NODE<T>;
				if(new_llc->last == nullptr){
						next->data = temp -> data;
						new_llc->last = next;
						new_llc->first = next;
						std::cout << "first temp data: " << new_llc->first->data << std::endl;
						temp = temp->next;
				}
				else {
					std::cout << "first temp data: " << new_llc->first->data << std::endl;
					new_llc->last->next = next;
					next ->data = temp->data;
					temp = temp->next;
					new_llc->last = new_llc->last->next;
				}
		}
		std::cout << "length: " << new_llc->len() << std::endl;
		temp = other.first;
		std::cout << "Temp: " << temp << std::endl;
		std::cout << "first: " << temp->data << std::endl;
		while(temp != nullptr){
				NODE<T>* next = new NODE<T>;
				if(new_llc->last == nullptr){
						new_llc->last = next;
						new_llc->first = next;
						next = temp->next;
						std::cout << "WRONG first temp data: " << new_llc->first->data << std::endl;
				}
				else {
					new_llc->last->next = next;
					next ->data = temp->data;
					temp = temp->next;
					new_llc->last = new_llc->last->next;
				}
		}
		last->next = nullptr;
		std::cout << "first temp data: " << new_llc->first->data << std::endl;
		new_llc->head(new_llc->len());
		return *new_llc;
	}

//works
	template <class T>
	LLC<T>& LLC<T>::operator+=(int n){
		int length = len();
		n = n%length;
		for(int i = 0; i < n; i++){
			last -> next = first;
			last = last -> next;
			first = first->next;
			last -> next = nullptr;
		}	
		return *this;
	}

	template <class T>
	NODE<T>* LLC<T>::getFirst(){
			return first;
	}
	template <class T>
	NODE<T>* LLC<T>::getLast(){
			return last;
	}
