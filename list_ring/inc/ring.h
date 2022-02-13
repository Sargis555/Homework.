#ifndef RING_H
#define RING_H

#include <iostream>
#include <ostream>
#include <cassert>


class ring
{
private:
	class node;

private:
    node* current;

public:
	ring();
	ring(int size, int value);
	~ring();

public:
	bool empty() const; 
	int size() const;
	void push_next(int value);
	void push_prev(int value);
	void pull();
	void clear();
	void go_next();
	void go_prev();
	void reset();
	void change(int a);
	void print_all();
	void print();
	friend std::ostream& operator<<(std::ostream& out, const ring& l);
};

#endif
