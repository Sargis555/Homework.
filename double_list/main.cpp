
#include "list.hpp"

#include <iostream>
#include <cassert>

void test_default_constructor()
{
    list<int> l;
    assert(l.empty());
    assert(l.size() == 0);
    list<double>* p = new list<double>;
    assert(p->empty());
    assert(p->size() == 0);
    delete p;
    p = nullptr;
}

void test_constructor()
{
    list<int> l(6, 0);
    assert(! l.empty());
    assert(l.size() == 6);
}

void test_push_back()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_back(2 * i);
    }
    assert(l.size() == 8);
    for (list<int>::size_type i = 0; i < l.size(); ++i) {
        assert(l.at(i) == (list<int>::value_type)(2 * i));
    }
}

void test_push_front()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    assert(l.size() == 8);
    for (list<int>::size_type i = 0; i < l.size(); ++i) {
        assert(l.at(l.size() - 1 - i) == (list<int>::value_type)(2 * i));
    }
}

void test_pop_back()
{
    list<double> l(5, 89);
    assert(l.size() == 5);
    while (! l.empty()) {
        l.pop_back();
    }
}

void test_pop_front()
{
    list<int> l(89, 5);
    assert(l.size() == 89);
    while (! l.empty()) {
        l.pop_front();
    }
}

void test_copy_constructor()
{
	list<int> b(56, 0);
    assert(b.size() == 56);
    list<int> a(b);
    assert(a.size() == 56);
    for (list<int>::size_type i = 0; i < a.size(); ++i) {
        assert(a.at(i) == 0);
    }
}

void test_insert()
{
    list<int> a;
    assert(a.size() == 0);
    assert(a.empty());
	a.insert(a.size(), 5);
	a.insert(a.size(), 6);
	a.insert(a.size(), 7);
	a.insert(a.size(), 9);
	a.insert(a.size() - 1, 8);
	a.insert(0, 0);
    a.insert(1, 1);
    a.insert(2, 2);
    a.insert(3, 3);
    a.insert(4, 4);
    assert(a.size() == 10);
    assert(a.at(0) == 0);
    assert(a.at(1) == 1);
    assert(a.at(2) == 2);
    assert(a.at(3) == 3);
    assert(a.at(4) == 4);
    assert(a.at(5) == 5);
    assert(a.at(6) == 6);
    assert(a.at(7) == 7);
    assert(a.at(8) == 8);
    assert(a.at(9) == 9);
}

void test_cout()
{
    list<int> a;
    assert(a.size() == 0);
    assert(a.empty());
	a.insert(a.size(), 5);
	a.insert(a.size(), 6);
	a.insert(a.size(), 7);
	a.insert(a.size(), 8);
	a.insert(a.size(), 9);
    assert(a.size() == 5);
    assert(a.at(0) == 5);
    assert(a.at(1) == 6);
    assert(a.at(2) == 7);
    assert(a.at(3) == 8);
    assert(a.at(4) == 9);
    std::cout << a << std::endl;
}

void test_at()
{
    list<int> a;
    assert(a.size() == 0);
    assert(a.empty());
    for (list<int>::size_type i = 0; i < 10; ++i) {
        a.push_back(5 * i);
    }
    std::cout << "Enter list index: " << std::flush;
    int index = 0;
    std::cin >> index;
    try {
        list<int>::value_type v = a.at(index);
        std::cout << "at " << index << " value equal " << v << std::endl;
    } catch(const std::exception& o) {
        std::cout << "ERROR with exception " << o.what() << std::endl;
    } catch(...) {
        std::cout << "ERROR" << std::endl;
    }
}

struct data
{
    int x;
    int y;
    data(int a = 0, int b = 0) : x(a), y(b) {}
};

void test_complex_data_type()
{
    list<data> e;
    assert(e.empty());
    list<data> l(5, data(6, 7));
    assert(l.size() == 5);
    for (list<data>::size_type i = 0; i < l.size(); ++i) {
        assert(l.at(i).x == 6);
        assert(l.at(i).y == 7);
    }
}

void test_pointer()
{
    using list_data_pointer = list<data*>;
    list_data_pointer e;
    assert(e.empty());
    list_data_pointer l(5, nullptr);
    assert(l.size() == 5);
    for (list_data_pointer::size_type i = 0; i < l.size(); ++i) {
        assert(l.at(i) == nullptr);
        l.at(i) = new data(i, 2 * i);
    }
    for (list_data_pointer::size_type i = 0; i < l.size(); ++i) {
        list_data_pointer::value_type& v = l.at(i);
        assert(v != nullptr);
        delete v;
        v = nullptr;
        assert(l.at(i) == nullptr);
    }
}

void test_assignment()
{
    list<int> b(56, 0);
    assert(b.size() == 56);
    list<int> a(4, 7); 
    assert(a.size() == 4);
	b = a;
	assert(b.size() == 4);
}

void test_swap()
{
	list<int> f(25, 7);
	assert(f.size() == 25);
	list<int> e(7, 0);
	assert(e.size() == 7);
	f.swap(e);
	assert(f.size() == 7);
	assert(e.size() == 25);
}

void test_remove()
{
	list<int> f(25, 7);
	assert(f.size() == 25);
	f.remove(5);
	assert(f.size() == 24);
}

int main()
{
    test_default_constructor();
    test_constructor();
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_insert();
    test_cout();
    test_at();
    test_copy_constructor();
    test_complex_data_type();
    test_pointer();
	test_assignment();
	//test_swap();
	test_remove();
	return 0;
}
