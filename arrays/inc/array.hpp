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
    size_type size() const;
    bool empty() const;
    element_type& operator[](size_type index);
    void insert(size_type index, const element_type value);
    void remove(size_type index);
	bool operator==(const array& a) const;
    bool operator!=(const array& a) const;
	
	friend std::ostream& operator<<(std::ostream& out, const array& a);

private:
	element_type* m_start;
	size_type m_size;

public:
    array();
    array(size_type n, const element_type default_value);
	array(const array& b);
	const array& operator=(const array& c);
    ~array();

};

#endif
