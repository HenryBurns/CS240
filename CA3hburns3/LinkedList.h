#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
typedef struct Node {
	std::string data;
	Node* next = nullptr;
	} NODE;
class LLC{
	private:
	NODE* first;
	NODE* last;
	public:
	NODE* getFirst();
	NODE* getLast();
	LLC();
	LLC(LLC const &);
	~LLC();
	bool contains(const std::string &);
	bool insert(const std::string &);
	void remove(const std::string &);
	void shuffle();
	void head(int n);
	int len();
	void join(LLC &other);
	std::string tail();
	LLC& operator+=(int n);
	LLC& operator=(const LLC &);
	LLC& operator+(const LLC &);
	friend std::ostream& operator<<(std::ostream &, const LLC&);
};
#endif
