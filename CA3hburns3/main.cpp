#include "LinkedList.h"
int main(){
	LLC* test = new LLC();
	test->insert("Hello");
	test->insert("middle");
	test->insert("Goodbye");
	test->head(test->len());
	test->remove("middle");
	test->head(test->len());
	test->shuffle();
	test->head(test->len());
	}
