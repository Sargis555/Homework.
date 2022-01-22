#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cassert>

class array
{

public:
    typedef int element_type;
    typedef unsigned int size_type;

public:
    size_type size();
    bool empty();
    element_type access(size_type index);
    void insert(size_type index, element_type value);
    ///////////
    void remove(size_type index, element_type value);
    ///////////
    ///////////
    void modify(size_type index, element_type value);
    ///////////

private:
	element_type* m_start;
	size_type m_size;

public:
    array();
    array(size_type n, element_type default_value);
    ~array();

};

#endif
