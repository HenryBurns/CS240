#include "LinkedList.h"
#include <iostream>
int main(){
	LLC* test = new LLC();
	test->insert("Hello");
	test->insert("middle");
	test->insert("Goodbye");
	test->head(test->len());
	test->remove("middle");
	test->head(test->len());
	test->tail();
	if(test->contains("Hello"))
			std::cout << "\n WE GOT EM BOYZ, HELLO is there" <<std::endl;
	if(test->contains("shit"))
			std::cout << "should not hit" << std::endl;
	LLC test3(*test);
	std::cout << "test3" <<std::endl;
	test3.head(test3.len());
	test3.remove("Hello");
	test->head(test->len());
	LLC* test2 = new LLC();
	test2->insert("Hello2");
	test2->insert("middle2");
	test2->insert("Goodbye2");
	test2->head(test2->len());
	std::cout << test->getFirst()->data << " Last: " << test->getLast()->data << "Last next: " << test->getLast()->next << std::endl;
	std::cout << test2 << std::endl;	
	std::cout << test2->getFirst()->data << " Last: " << test2->getLast()->data << " Last Next: " << test2->getLast()->next << std::endl;
	test->join(*test2);
	std::cout << test->len();
	test->head(test->len());
	*test = test3;
	std::cout << "Should seg fault" << std::endl;
	test->head(test->len());
	}
