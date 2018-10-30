#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
template <class T>
class NODE {
	public:
	T data;
	NODE<T>* next = nullptr;
	};
template <class T>
class LLC{
	private:
	NODE<T>* first;
	NODE<T>* last;
	public:
	NODE<T>* getFirst();
	NODE<T>* getLast();
	LLC();
	LLC(LLC const &);
	~LLC();
	bool contains(const T &);
	bool insert(const T &);
	void remove(const T &);
	void shuffle();
	void head(int n);
	int len();
	void join(LLC &other);
	T tail();
	LLC& operator+=(int n);
	LLC& operator=(const LLC &);
	LLC operator+(const LLC &);
	//TODO include templating for friend function.
	template <class U>
	friend std::ostream& operator<<(std::ostream &, const LLC<U>&);
};
#endif
