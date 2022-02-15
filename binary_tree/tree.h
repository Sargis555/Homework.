#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cmath>
#include <cassert>

class tree
{
private:
	class node;

private:
	node* m_root;

private:
	void add(int value, node* &m);
	void show(node* &a);
	tree::node* find(int value, node* &a);
	void clear(node* &c);
	int size(node* &s);
	int height(node* &a);
	void rotate_l(node* &a);
	void rotate_r(node* &a);
	bool is_balanc(node* &a);

public:
	tree();
	tree(int value);
	~tree();

public:
	void add(int value);
	void show();
	tree::node* find(int value);
	void clear();
	int size();
	int height();
	void rotate_l();
	void rotate_r();
	bool is_balanc();
	void print();
};

#endif
