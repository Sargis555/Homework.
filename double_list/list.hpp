
#ifndef LIST_HPP
#define LIST_HPP

#include <ostream>

template <typename J>
class node;

template <typename T>
class list
{
private:

public:
    typedef T value_type;
    typedef unsigned int size_type;

private:
    node<T>* access_helper(const size_type& index) const noexcept;

public:
    size_type size() const noexcept;
    bool empty() const noexcept;
    void push_front(const value_type& value) noexcept;
    void push_back(const value_type& value) noexcept;
    void pop_front() noexcept;
    void pop_back() noexcept;
    const value_type& at(const size_type& index) const noexcept(false);
    value_type& at(const size_type& index) noexcept(false);
    void insert(const size_type& p, const value_type& value) noexcept;
    void remove(const size_type& index); 
	void clear();
	void swap(list& a);
	void bubblesort();
	node<T> midPoint(list &a);
    node<T> merge(node<T> &m_head1, node<T> &m_head2);
    node<T> mergesort(list &a);
    template <typename C>
    friend std::ostream& operator<<(std::ostream& out, const list<C>& l);

private:
    node<T>* m_head;
    node<T>* m_tail;

public:
    list();
    list(size_type n, const value_type& default_value);
    list(const list& b);
    const list& operator=(const list& c);
    ~list();
};

#include "list.tpp"

#endif
