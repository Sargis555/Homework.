#include "shape.h"

int main()
{
    rectangle rec;
    rectangle rec1;
    circle cir;
    triangle tri;
    point a,b,c,d;
    a.set_x(5);
    a.set_y(7);
    b.set_x(15);
    b.set_y(17);
    c.set_x(9);
    c.set_y(14);
    d.set_x(19);
    d.set_y(24);
	shape *ss;
    ss = &rec1;
    ss->set_height(c, b);
    ss->set_width(a, d);
    ss = &rec;
    ss->set_height(a, b);
    ss->set_width(c, d);
    std::cout<<ss->area()<<'\n';
   // ss= &cir;
    //ss->set_radius(a, b);
    //ss->area();
    ss = &tri;
    ss->set_height(a, b);
    ss->set_width(c, d);
    std::cout<<ss->area()<<'\n';
	cir.set_radius(a, b);
	std::cout<<cir.area()<<'\n';
    rec == rec1;

return 0;
}

