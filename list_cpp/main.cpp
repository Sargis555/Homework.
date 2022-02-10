
#include "list.hpp"

#include <iostream>
#include <cassert>

void test_default_constructor()
{
    list l;
    assert(l.empty());
    assert(l.size() == 0);
    list* p = new list;
    assert(p->empty());
    assert(p->size() == 0);
    delete p;
}

void test_constructor()
{
    list l(6, 0);
    assert(! l.empty());
    assert(l.size() == 6);
}

void test_push_back()
{
    list l;
    assert(l.empty());
    for (list::size_type i = 0; i < 8; ++i) {
        l.push_back(2 * i);
    }
	assert(l.size() == 8);
	std::cout << l << std::endl;
}

void test_push_front()
{
    list l;
    assert(l.empty());
    for (list::size_type i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    assert(l.size() == 8);
    std::cout << l << std::endl;
}

void test_pop_back()
{
    list l(5, 89);
    assert(l.size() == 5);
    while (! l.empty()) {
        l.pop_back();
    }
	assert(l.size() == 0);
	std::cout << l << std::endl;
}

void test_pop_front()
{
    list l(89, 5);
    assert(l.size() == 89);
    while (! l.empty()) {
        l.pop_front();
    }	
	assert(l.size() == 0);
	assert( l.empty());
	std::cout << l << std::endl;
}

void test_copy_constructor()
{
	list b(7, 0);
    assert(b.size() == 7);
    list a(b);
    assert(a.size() == 7);
	std::cout << a << std::endl;
}

void test_assignment()
{
    list b(7, 0);
    assert(b.size() == 7);
    list a(9,5);
	a = b;
    assert(a.size() == 7);
    std::cout << a << std::endl;
}


int main()
{
    test_default_constructor();
    test_constructor();
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_copy_constructor();
	test_assignment();
	return 0;
}
