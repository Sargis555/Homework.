#include "tree.h"

class tree::node
{
public:
	int m_value;
	node* m_left;
	node* m_right;

public:
	node(int v, node* l, node* r)
		: m_value(v)
		, m_left(l)
		, m_right(r)
	{	
	}
	
	~node()
	{
	}

};

tree::tree()
	:m_root(nullptr)
{
}

tree::tree(int value)
{
	m_root = new node(value, nullptr, nullptr);
}

tree::~tree()
{
	clear();
}

void tree::add(int value)
{
	if(m_root != nullptr){
		add(value, m_root);
	}
	else{
		m_root = new node(value, nullptr, nullptr);
	}
}

void tree::add(int value, node* &m)
{
	assert(m != nullptr);
	if(value < m->m_value){
		if(m->m_left != nullptr){
			add(value, m->m_left);
		}
		else{
			assert(m->m_left == nullptr);
			m->m_left = new node(value, nullptr, nullptr);
		}
	}
	if(value > m->m_value){
        if(m->m_right != nullptr){
            add(value, m->m_right);
        }
        else{
			assert(m->m_right == nullptr);
            m->m_right = new node(value, nullptr, nullptr);
        }
	}
}

void tree::show()
{
	show(m_root);
}

void tree::show(node* &a)
{
	if(a != nullptr){
		show(a->m_left);
		std::cout<<a->m_value<<'\n';
		show(a->m_right);
	}
}

tree::node* tree::find(int value)
{
	find(value, m_root);
}

tree::node* tree::find(int value, node* &a)
{
	if(a != nullptr){
		if(value == a->m_value){
			return a;
		}
		if(value < a->m_value){
			return find(value, a->m_left);
		}
		if(value > a->m_value){
			return find(value, a->m_right);
		}
	}
	else
		return NULL;		
}

int tree::size()
{
	size(m_root);
}

int tree::size(node* &s)
{
	if(s == nullptr){
		return 0;
	}
	else{
		assert(s != nullptr);
		return (size(s->m_left) + 1 + size(s->m_right));
	}
}

int tree::height()
{
	height(m_root);
}

int tree::height(node* &a)
{
	if((a == nullptr)||((a->m_left == nullptr)&&(a->m_right == nullptr))){
		return 0;
	}
	int l = height(a->m_left);
	int r = height(a->m_right);
	if(l > r){
        return l + 1;
    }
    else{
        return r + 1;
    }
}

bool tree::is_balanc()
{
	is_balanc(m_root);
}

bool tree::is_balanc(node* &a)
{
	if(a == nullptr){
		return true; 
	}
	int l = height(a->m_left);
	int r = height(a->m_right);
	if(abs(l - r) <= 1){
		return true;
	}
	else{
		return false;
	}
}

void tree::rotate_l()
{
	rotate_l(m_root);
}

void tree::rotate_r()
{
	rotate_r(m_root);
}

void tree::rotate_l(node* &a)
{	
	node* tmp = a->m_left;
	a->m_left = tmp->m_right;
	tmp->m_right = a;
	a = tmp;
}

void tree::rotate_r(node* &a)
{
	
    node* tmp = a->m_right;
    a->m_right = tmp->m_left;
    tmp->m_left = a;
    a = tmp;
}

void tree::clear()
{
	clear(m_root);
}

void tree::clear(node* &c)
{
	if(c != nullptr){
		clear(c->m_left);
		clear(c->m_right);
		delete c;
		c = nullptr;
	}
	 assert(c ==nullptr);
}

void tree::print()
{
	assert(m_root != nullptr);
    printf("root -  %d", m_root->m_value);
    printf("\n");
}

