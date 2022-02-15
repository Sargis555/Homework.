#include "tree.h"

int main()
{
	tree a(50);
	a.add(45);
	a.add(55);
	a.add(65);
	a.add(70);
	a.add(40);
	a.add(35);
	a.add(75);
	a.add(30);
    a.add(25);
    a.add(80);
    a.add(5);
	//std::cout<<a.find(50)<<'\n';
	a.show();
	a.print();
	std::cout<<"balanc - "<<a.is_balanc()<<'\n';
	a.rotate_l();
	std::cout<<"rotate_left"<<'\n';
	a.print();
	a.rotate_r();
	a.rotate_r();
	std::cout<<"2 * rotate_right"<<'\n';
	a.print();
	std::cout<<"balanc - "<<a.is_balanc()<<'\n';

	std::cout<<"size - "<<a.size()<<'\n';
    return 0;
}

