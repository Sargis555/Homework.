
#include "list.hpp"

#include <cassert>

class list::node
{
public:
    value_type m_value;
    node* m_next;

public:
    node(value_type v, node* n)
        : m_value(v)
        , m_next(n)
    {
    }

    ~node()
    {
    }
};

std::ostream& operator<<(std::ostream& out, const list& l)
{
    list::node* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

list::size_type list::size() const
{
    node* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

bool list::empty() const
{
    return (m_head == nullptr);
}

void list::push_front(const value_type& value)
{
    node* new_node = new node(value, m_head);
    m_head = new_node;
}

void list::push_back(const value_type& value)
{
	if (m_head == nullptr) {
        m_head = new node(value, nullptr);
	}
	else
	{
		assert(size() >= 1);
		node* current = m_head;
        while(current->m_next != nullptr)
        {
            current = current->m_next;
        }
        current->m_next = new node(value, nullptr);
	}
}

void list::pop_front()
{
	node *tmp = m_head;
	m_head = m_head->m_next;
	delete tmp;
}

void list::pop_back()
{
	assert(m_head != nullptr);
    if (m_head->m_next == nullptr) {
        pop_front();
        assert(m_head == nullptr);
	}
	else
	{
		assert(size() >= 2);
		node* current = m_head;
		node* tmp = current->m_next;
    	while (tmp->m_next != nullptr) {
        	tmp = tmp->m_next;
			current = current->m_next;
    	}
		current->m_next = nullptr;
		delete tmp;
	}
}	

list::list()
    : m_head(nullptr)
{
}

list::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
{
    node* current = nullptr;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr);
        if (current != nullptr) {
            current->m_next = new_node;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        current = new_node;
    }
}

list::list(const list& b)
{
	node* tmp = nullptr;
	node* current = b.m_head;
	while (current != nullptr)
	{
		node* new_node = new node(current->m_value, nullptr);
		if(m_head == nullptr){
			m_head = new_node;
		}
		else
		{
			tmp->m_next = new_node;
		}
		tmp = new_node;
		current = current->m_next;
	}
}

const list& list::operator=(const list& c)
{
	assert(c.size() >= 0);
    if (this == &c) {
        return *this;
	}
	if(m_head != nullptr){
		clear();
	}
	node* tmp = nullptr;
    node* current = c.m_head;
    while (current != nullptr)
    {
        node* new_node = new node(current->m_value, nullptr);
        if(m_head == nullptr){
            m_head = new_node;
        }
        else
        {
            tmp->m_next = new_node;
        }
        tmp = new_node;
        current = current->m_next;
    }

    return *this;
}

void list::clear()
{
	while (! empty()) {
		pop_front();
	}
    assert(m_head == nullptr);
}

list::~list()
{
	while (! empty()) {
        pop_front();		
    }
}
