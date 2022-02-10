#include "array.hpp"

std::ostream& operator<<(std::ostream& out, const array& a)
{
    for (array::size_type i = 0; i < a.size(); ++i)  {
        out << "a[" << i << "] = " << a.m_start[i] << "\n";
    }
    return out;
}


void test_1()
{
	array a(4, 0);
    assert(a.size() == 4);
    assert(! a.empty());
    assert(a[0] == 0);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
    a.insert(a.size(), 8);
    a.insert(a.size(), 9);
    assert(a.size() == 6);
    assert(a[0] == 0);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
    assert(a[4] == 8);
    assert(a[5] == 9);
    a.insert(0, 5);
	assert(a.size() == 7);
    assert(a[0] == 5);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
    assert(a[4] == 0);
    assert(a[5] == 8);
    assert(a[6] == 9);
    a.insert(5, 15);
    assert(a.size() == 8);
    assert(a[0] == 5);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
	assert(a[4] == 0);
    assert(a[5] == 15);
    assert(a[6] == 8);
    assert(a[7] == 9);
    a.remove(6);
    assert(a.size() == 7);
    assert(a[0] == 5);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
    assert(a[4] == 0);
    assert(a[5] == 15);
    assert(a[6] == 9);
    a.remove(2);
    assert(a.size() == 6);
    assert(a[0] == 5);
    assert(a[1] == 0);
    assert(a[2] == 0);
    assert(a[3] == 0);
    assert(a[4] == 15);
    assert(a[5] == 9);
    for (array::size_type i = 0; i < a.size(); ++i)  {
		std::cout << "a[" << i << "]" << a[i] << std::endl;
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

void test_copy()
{
    array b(5, 0);
    assert(b.size() == 5);
    for (array::size_type i = 0; i < b.size(); ++i) {
        b[i] = 2 * i;
    }
    assert(b[0] == 0);
    assert(b[1] == 2);
    assert(b[2] == 4);
    assert(b[3] == 6);
    assert(b[4] == 8);
    array c(b);
    assert(c.size() == 5);
    assert(c[0] == 0);
    assert(c[1] == 2);
    assert(c[2] == 4);
    assert(c[3] == 6);
    assert(c[4] == 8);
}

void test_assignment()
{
    array b(16, 1);
    assert(b.size() == 16);
    array c(4, 0);
    assert(c.size() == 4);
    b = c; 
    assert(b.size() == 4);
    assert(b[0] == 0);
    assert(b[1] == 0);
    assert(b[2] == 0);
    assert(b[3] == 0);
}



int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
	test_copy();
	test_assignment();
    return 0;
}

