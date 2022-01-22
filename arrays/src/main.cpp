#include "array.hpp"

void test_1()
{
	array a(4, 0);
    assert(a.size() == 4);
    assert(! a.empty());
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    a.insert(a.size(), 8);
    a.insert(a.size(), 9);
    assert(a.size() == 6);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 8);
    assert(a.access(5) == 9);
    a.insert(0, 5);
	assert(a.size() == 7);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 0);
    assert(a.access(5) == 8);
    assert(a.access(6) == 9);
    a.insert(5, 15);
    assert(a.size() == 8);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
	assert(a.access(4) == 0);
    assert(a.access(5) == 15);
    assert(a.access(6) == 8);
    assert(a.access(7) == 9);
/////////////
    a.remove(6,a.empty());
    assert(a.size() == 7);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 0);
    assert(a.access(5) == 15);
    assert(a.access(6) == 9);
    a.modify(3, 4);
    assert(a.size() == 7);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 4);
    assert(a.access(4) == 0);
    assert(a.access(5) == 15);
    assert(a.access(6) == 9);
    a.modify(1, 77);
    assert(a.size() == 7);
    assert(a.access(0) == 5);
    assert(a.access(1) == 77);
    assert(a.access(2) == 0);
    assert(a.access(3) == 4);
    assert(a.access(4) == 0);
    assert(a.access(5) == 15);
	assert(a.access(6) == 9);
    a.remove(2 ,a.empty());
    assert(a.size() == 6);
    assert(a.access(0) == 5);
    assert(a.access(1) == 77);
    assert(a.access(2) == 4);
    assert(a.access(3) == 0);
    assert(a.access(4) == 15);
    assert(a.access(5) == 9);
///////////////
    for (array::size_type i = 0; i < a.size(); ++i)  {
		std::cout << "a[" << i << "]" << a.access(i) << std::endl;
    }
}

void test_2()
{
	array b;
    assert(b.size() == 0);
    assert(b.empty());
}

void test_3()
{
    array* c = new array(5, 8);
    assert(c->size() == 5);
    assert((*c).size() == 5);
    assert(! c->empty());
        delete c;
}

void test_4()
{
	array* d = new array[5];
    assert(d[0].size() == 0);
    assert(d[1].size() == 0);
    assert(d[2].size() == 0);
    assert(d[3].size() == 0);
    assert(d[4].size() == 0);
    for (int i = 0; i < 5; ++i) {
        assert(d[i].empty());
    }
    delete [] d;
}

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}

