
#include <cassert>
#include <stdexcept>

template <typename J>
class node
{
public:
    J m_value;
    node<J>* m_next;
    node<J>* m_prev;

public:
    node(const J& v, node<J>* n, node<J>* p)
        : m_value(v)
        , m_next(n)
        , m_prev(p)
    {
    }

    ~node()
    {
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const list<T>& l)
{
    node<T>* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

template <typename T>
typename list<T>::size_type list<T>::size() const noexcept
{
    node<T>* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

template <typename T>
bool list<T>::empty() const noexcept
{
    assert(m_head != nullptr || m_tail == nullptr);
    return (m_head == nullptr);
}

template <typename T>
void list<T>::push_front(const value_type& value) noexcept// O(1)
{
    assert(m_head != nullptr || m_tail == nullptr);
    assert(size() != 1 || m_head == m_tail);
    node<T>* new_node = new node<T>(value, m_head, nullptr);
    if (nullptr == m_head) {
        assert(nullptr == m_tail);
        m_tail = new_node;
    } else {
        assert(m_head->m_prev == nullptr);
        m_head->m_prev = new_node;
    }
    m_head = new_node;
    assert(nullptr != m_tail);
    assert(nullptr != m_head);
}

template <typename T>
void list<T>::push_back(const value_type& value) noexcept// O(n)
{
    assert(m_head != nullptr || m_tail == nullptr);
    assert(size() != 1 || m_head == m_tail);
    node<T>* new_node = new node<T>(value, nullptr, m_tail);
    if (m_tail == nullptr) {
        assert(nullptr == m_head);
        m_head = new_node;
    } else {
        assert(m_tail->m_next == nullptr);
        m_tail->m_next = new_node;
    }
    m_tail = new_node;
    assert(nullptr != m_tail);
    assert(nullptr != m_head);
}

template <typename T>
void list<T>::insert(const size_type& index, const value_type& value) noexcept
{
    assert(index >= 0);
    assert(index <= size());
    if (index == 0) {
        push_front(value);
    } else if (index == size()) {
        push_back(value);
    } else {
        node<T>* new_node = new node<T>(value, nullptr, nullptr);
        assert(index >= 1);
        node<T>* current = access_helper(index);
        assert(current != nullptr);
        new_node->m_prev = current->m_prev;
        assert(new_node->m_prev != nullptr);
        new_node->m_prev->m_next = new_node;
        new_node->m_next = current;
        current->m_prev = new_node;
    }
}

template <typename T>
void list<T>::pop_front() noexcept
{
    assert(m_head != nullptr);
    assert(m_tail != nullptr);
    node<T>* n = m_head;
    m_head = m_head->m_next;
    if (m_head != nullptr) {
        assert(n == m_head->m_prev);
        m_head->m_prev = nullptr;
    } else {
        assert(n == m_tail);
        m_tail = nullptr;
    }
    delete n;
}

template <typename T>
void list<T>::pop_back() noexcept
{
    assert(m_tail != nullptr);
    node<T>* n = m_tail;
    m_tail = m_tail->m_prev;
    if (m_tail != nullptr) {
        assert(m_tail->m_next == n);
        m_tail->m_next = nullptr;
    } else {
        assert(m_head == n);
        m_head = nullptr;
    }
    delete n;
}

template <typename T>
node<T>* list<T>::access_helper(const size_type& index) const noexcept
{
    assert(index >= 0);
    assert(index < size());
	node<T>* current = m_head;
    for (size_type i = 0; i < index; ++i) {
        assert(current != nullptr);
        current = current->m_next;
	}
    assert(current != nullptr);
	return current;
}

template <typename T>
const typename list<T>::value_type&
list<T>::at(const size_type& index) const noexcept(false)
{
    if (index >= size()) {
        throw std::out_of_range("hello my name is");
    }
    node<T>* n = access_helper(index);
    assert(n != nullptr);
	return n->m_value;
}

template <typename T>
typename list<T>::value_type&
list<T>::at(const size_type& index) noexcept(false)
{
    if (index >= size()) {
        throw std::out_of_range("hello my name is");
    }
    node<T>* n = access_helper(index);
    assert(n != nullptr);
	return n->m_value;
}

template <typename T>
list<T>::list()
    : m_head(nullptr)
    , m_tail(nullptr)
{
}

template <typename T>
list<T>::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
    , m_tail(nullptr)
{
    node<T>* current = nullptr;
    for (size_type i = 0; i < n; ++i) {
        node<T>* new_node = new node<T>(default_value, nullptr, nullptr);
        if (current != nullptr) {
            current->m_next = new_node;
            new_node->m_prev = current;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        current = new_node;
    }
    m_tail = current;
    assert(m_head == nullptr || m_head->m_prev == nullptr);
    assert(m_tail == nullptr || m_tail->m_next == nullptr);
}

template <typename T>
void list<T>::clear()
{
	while (! empty()) {
		pop_front();
	}
    assert(m_head == nullptr);
}

template <typename T>
list<T>::list(const list<T>& b)
    : m_head(nullptr)
    , m_tail(nullptr)
{
 	node<T>* bcurrent = b.m_head;
    node<T>* acurrent = nullptr;
	while (bcurrent != nullptr) {
	   	node<T>* new_node = new node<T>(bcurrent->m_value, nullptr, nullptr);
        if (m_head == nullptr) {
            m_head = new_node;
            assert(acurrent == nullptr);
        } else {
            assert(acurrent != nullptr);
            acurrent->m_next = new_node;
            new_node->m_prev = acurrent;
        }
        acurrent = new_node;
		bcurrent = bcurrent->m_next;
	}
    m_tail = acurrent;
}

template <typename T>
const list<T>& list<T>::operator=(const list<T>& c)
{
	if (this == &c) {
        return *this;
    }
	if (this->m_head != nullptr) {
		clear();
	}
	assert(this->m_head == nullptr);
	node<T>* ccurrent = c.m_head;
    node<T>* acurrent = nullptr;
    while (ccurrent != nullptr) {
        node<T>* new_node = new node<T>(ccurrent->m_value, nullptr, nullptr);
        if (m_head == nullptr) {
            m_head = new_node;
            assert(acurrent == nullptr);
        } else {
            assert(acurrent != nullptr);
            acurrent->m_next = new_node;
            new_node->m_prev = acurrent;
        }
        acurrent = new_node;
        ccurrent = ccurrent->m_next;
    }
    m_tail = acurrent;

    return *this;
}

template <typename T>
void list<T>::remove(const size_type& index)
{
    assert(index >= 0);
    assert(index <= size());
    if (index == 0) {
        pop_front();
    } 
	else if (index == size()) {
        pop_back();
    } 
	else {
        assert(index >= 1);
        node<T>* current = access_helper(index);
        assert(current != nullptr);
		current->m_next->m_prev = current->m_prev;
		current->m_prev->m_next = current->m_next;
		delete current; 
    }
}


template <typename T>
void list<T>::swap(list<T>& a)
{
	node<T>* tmp = this->m_head;
	node<T>* tmp1 = this->m_tail;
	this->m_head = a.m_head;
	this->m_tail = a.m_tail;
	a.m_head = tmp;
	a.m_tail = tmp1;
	
}

template <typename T>
void list<T>::bubblesort()
{
	size_type swapped;
	node<T>* current = nullptr;
	node<T>* current1 = nullptr;
	node<T>* tmp = new node<T>(0,nullptr,nullptr);
	do
	{	
		swapped=0;
		current = m_head;
		while (current->m_next != current1) 
		{
			if ((current->m_value) > (current->m_next->m_value)){
				tmp->m_value = current->m_value;
				current->m_value = current->m_next->m_value;
				current->m_next->m_value = tmp->m_value;
				swapped=1;
			}	
			current = current->m_next;		
		}
	current1 = current;
	}
	while (swapped);
}

template <typename T>
list<T>::~list()
{
    clear();
}
