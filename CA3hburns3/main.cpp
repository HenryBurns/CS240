#include "LinkedList.h"
#include <iostream>
int main(){
	LLC* test = new LLC();
	test->insert("Hello");
	test->insert("middle");
	test->insert("Goodbye");
	LLC* test3 = new LLC(*test);
	//std::cout << "test3" <<std::endl;
	LLC* test2 = new LLC();
	test2->insert("Hello2");
	test2->insert("middle2");
	test2->insert("Goodbye2");
	//std::cout << *test2 << std::endl;	
	test->join(*test2);
	std::cout << "\n\nTest: " << *test << std::endl;
	//std::cout << "Test: " << *test << std::endl;
	*test = *test3;
	//std::cout << "Should seg fault" << std::endl;
	//std::cout << "Test: " << *test << std::endl;
	//std::cout << "Test3 " << *test3 << std::endl;
	//delete(test3);
	//std::cout << "Test: " << *test << std::endl;
	std::cout << "\n\nTest: " << *test << std::endl;
	std::cout << "\n\nTest2 HERE: " << *test2 << std::endl;
	*test = *test+(*test2);
	std::cout << "ending test: " << *test << std::endl;
	std::cout << "Num nodes: " << test->len() << std::endl;
	*test += 4;
	std::cout << "Test: " << *test << std::endl;
	//test->shuffle();
	//std::cout << "Shuffle: " << *test << std::endl;
	test ->tail();
	delete(test);
	delete(test2);
	delete(test3);
	}
