#include "point.h"

line::line()
{

}

line::line(point a1, point b1)
{
    a = a1;
    b = b1;
}

line::~line()
{

}

void line::setA(point a1)
{
    a=a1;
}

void line::setB(point b1)
{
    b=b1;
}

int line::getLength()
{
    int length=sqrt((b.getX()-a.getX())*(b.getX()-a.getX())+(b.getY()-a.getY())*(b.getY()-a.getY()));
    return length;
}

void line::comparison(int line1, int line2)
{
    if (line1 == line2){
        std::cout << "line1 = line2" <<std::endl;
    }
    else if (line1 > line2){
        int rezult = line1 - line2;
        std::cout << "line1 more on "<<rezult<<" line2"<<std::endl;
    }
    else if (line1 < line2){
        int rezult = line2 - line1;
        std::cout << "line1 less by "<<rezult<<" line2"<<std::endl;
    }
}

