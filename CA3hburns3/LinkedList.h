#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef stuct Node {
	string data;
	Node* next;
	} NODE;
public class LLC{
	public:
	NODE* first;
	NODE* last;
	LLC()
	LLC(LLC const &);
	~LLC();
	bool contains(const std::string &);
	bool insert(const std::string &);
	void remove(const std::string &);
	void shuffle();
	void head(int n);
	void join(LLC other);
	std::string tail();
	operator+=(int n);
	operator=(const LLC &);
	operator+(const LLC &);
	friend operator<<(std::ostream &);

#endif
