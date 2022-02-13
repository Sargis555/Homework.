#include "ring.h"

class ring::node
{
public:
    int m_value;
    node* m_next;
    node* m_prev;

public:
    node(int v, node* n, node* p)
        : m_value(v)
        , m_next(n)
        , m_prev(p)
    {
    }

    ~node()
    {
    }
};

ring::ring()
    :current(nullptr)
{
}

ring::ring(int size, int value)
    : current(nullptr)
{
    node* tmp = nullptr;
    for (int i = 0; i < size; ++i) {
        node* new_node = new node(value, nullptr, nullptr);
        if (tmp != nullptr) {
            tmp->m_next = new_node;
            new_node->m_prev = tmp;
    } else {
        assert(current == nullptr);
        current = new_node;
    }
    tmp = new_node;
    }
	tmp->m_next = current;
	current->m_prev = tmp;
}

ring::~ring()
{
	clear();
}

bool ring::empty() const 
{
    return (current == nullptr );
}

int ring::size() const
{
	if(current == nullptr){
		return 0;
	}
    node* tmp = current;
    int count = 0;
    do
    {
        tmp = tmp->m_next;
        ++count;
    }while(tmp != current);

    return count;
}

void ring::push_next(int value)
{
    node* new_node = new node(value, nullptr, nullptr);
    if(current == nullptr){
        assert(current == nullptr);
        current = new_node;
        current->m_next = current;
        current->m_prev = current;
    }
    else{
		assert(! empty());
        new_node->m_next = current->m_next;
        new_node->m_prev = current;
        current->m_next->m_prev = new_node;
        current->m_next = new_node;
    }
}

void ring::push_prev(int value)
{
    node* new_node = new node(value, nullptr, nullptr);
    if(current == nullptr){
        assert(current == nullptr);
        current = new_node;
        current->m_next = current;
        current->m_prev = current;
    }
    else{
		assert(! empty());
        new_node->m_next = current;
        new_node->m_prev = current->m_prev;
        current->m_prev->m_next = new_node;
        current->m_prev = new_node;
    }
}

void ring::pull()
{
	assert(! empty());
	if(current->m_next == current){
		current = nullptr;
		assert(empty());
	}
	else{
    	node* tmp = current;
    	current->m_prev->m_next = current->m_next;
    	current->m_next->m_prev = current->m_prev;
    	current = current->m_next;
    	delete tmp;
	}
}

void ring::clear()
{
    do
    {
		assert(! empty());
        if(current->m_next == current){
			assert(current->m_next == current);
			current = nullptr;
        }
		else
		{
			assert(size() > 1);
        	node* tmp = current;
        	current->m_prev->m_next = current->m_next;
        	current->m_next->m_prev = current->m_prev;
        	current = current->m_next;
        	delete tmp;
		}
    }while( ! empty());
	assert(empty());
}

void ring::go_next()
{
    assert(current != nullptr);
    current = current->m_next;
}

void ring::go_prev()
{
    assert(current != nullptr);
    current = current->m_prev;
}

void ring::reset()
{
	assert(current != nullptr);
    node* tmp = current;
    do
    {
         tmp->m_value = 0;
         tmp = tmp->m_next;
    }while (tmp != current);
}

void ring::change(int a)
{
	assert(current != nullptr);
    current->m_value = a;
}

void ring::print_all()
{
	if(current == nullptr){
		printf("\t");
	}
	else{
		assert(! empty());
    	node* tmp = current;
    do
    {
        printf("%d   ", tmp->m_value );
        tmp = tmp->m_next;
    }while (tmp != current);
    printf("\n");
	}
}

void ring::print()
{
	 if(current == nullptr){
        printf("\t");
    }
	else{
		assert(! empty());
    	printf("%d\n", current->m_value );
	}
}

std::ostream& operator<<(std::ostream& out, const ring& l)
{
	if(l.current == nullptr){
		out << " " <<'\n';
	}
	else{
    	ring::node* tmp = l.current;
    do
    {
        out << tmp->m_value << " ";
        tmp = tmp->m_next;
    }while (tmp != l.current);
	}
    return out;
}



