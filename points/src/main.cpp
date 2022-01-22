#include "point.h"

int main()
{
    point a, b, a1, b1;
    line c, c1;
    a.setPoints(27,90);
    b.setPoints(55,250);
    c.setA(a);
    c.setB(b);
    a1.setPoints(15,74);
    b1.setPoints(59,23);
    c1.setA(a1);
    c1.setB(b1);

    std::cout << c.getLength() << std::endl;
    std::cout << c1.getLength() << std::endl;
    line::comparison( c.getLength(),  c1.getLength());
    return 0;
}

