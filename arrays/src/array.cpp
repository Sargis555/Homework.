#include "array.hpp"

array::size_type array::size()
{
	return m_size;
}

array::array()
{
	std::cout << "Default constructor" << std::endl;
	m_size = 0;
	m_start = nullptr;
}

array::array(size_type n, element_type default_value)
{
	std::cout << "Constructor" << std::endl;
	m_size = 0;
	m_size = n;
	m_start = new element_type[n];
	for (size_type i = 0; i < m_size; ++i) {
		m_start[i] = default_value;
	}
}

array::~array()
{
	std::cout << "Destructor" << std::endl;
    if (m_start != nullptr) {
         delete [] m_start;
    }
}

void array::insert(size_type index, element_type value)
{
	assert(index >= 0);
	assert(index <= m_size);
	m_size = m_size + 1;
	element_type* tmp = new element_type[m_size];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	tmp[index] = value;
	for (size_type i = index + 1; i < m_size; ++i) {
		tmp[i] = m_start[i - 1];
	}
    if (m_start != nullptr) {
        delete [] m_start;
    }
    m_start = tmp;
}
/////////////////////////////
void array::remove(size_type index, element_type value)
{
	assert(index >= 0);
    assert(index <= m_size);
    m_size = m_size - 1;
    element_type* tmp = new element_type[m_size];
    for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
    for (size_type i = index + 1; i < m_size; ++i) {
        tmp[i-1] = m_start[i ];
	}
    if (m_start != nullptr) {
        delete [] m_start;
    }
    m_start = tmp;
}
/////////////////////////////////////////////////
/////////////////////////////////////////////
void array::modify(size_type index, element_type value)
{
	element_type* tmp = new element_type[m_size];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
    tmp[index]=value;
	for(size_type i = index + 1; i < m_size; i++){
        tmp[i] = m_start[i];
    }
    if (m_start != nullptr) {
        delete [] m_start;
    }
	m_start = tmp;
}
///////////////////////////////////////////
bool array::empty()
{
    assert(m_size >= 0);
    return m_size == 0;
}

array::element_type array::access(array::size_type index)
{
	assert(index >= 0);
    assert(index < m_size);
    assert(m_start != nullptr);
    return m_start[index];
}
