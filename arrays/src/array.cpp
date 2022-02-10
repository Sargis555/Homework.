#include "array.hpp"

array::size_type array::size() const
{
	return m_size;
}

array::array()
{
	m_size = 0;
	m_start = nullptr;
}

array::array(const array& b)
{
    m_size = b.m_size;
    if (m_size == 0) {
        m_start = nullptr;
    } else {
        m_start = new element_type[m_size];
        for (size_type i = 0; i < m_size; ++i) {
            m_start[i] = b.m_start[i];
        }
    }
}

const array& array::operator=(const array& c)
{
    assert(c.m_size >= 0);
    if (this == &c) {
        return *this;
    }
    if (m_start != nullptr) {
        delete [] m_start;
        m_start = nullptr;
    }
    assert(m_start == nullptr);
    m_size = c.m_size;
    if (m_size > 0) {
        m_start = new element_type[m_size];
        for (size_type i = 0; i < m_size; ++i) {
            m_start[i] = c.m_start[i];
        }
    }
    return *this;
}


array::array(size_type n, const element_type default_value)
{
	m_size = 0;
	m_size = n;
	m_start = new element_type[n];
	for (size_type i = 0; i < m_size; ++i) {
		m_start[i] = default_value;
	}
}

array::~array()
{
    if (m_start != nullptr) {
         delete [] m_start;
    }
}

void array::insert(size_type index, const element_type value)
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

void array::remove(size_type index)
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

bool array::empty() const
{
    assert(m_size >= 0);
    return m_size == 0;
}

array::element_type& array::operator[](size_type index)
{
	assert(index >= 0);
    assert(index < m_size);
    assert(m_start != nullptr);
    return m_start[index];
}

bool array::operator==(const array& a) const
{
    if (this == &a) {
        return true;
    }
    if (m_size != a.m_size) {
        return false;
    }
    for (size_type i = 0; i < m_size; ++i) {
        if (m_start[i] != a.m_start[i]) {
            return false;
        }
    }
    return true;
}

bool array::operator!=(const array& a) const
{
    return ! operator==(a);
}

