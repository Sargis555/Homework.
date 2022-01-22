#include "point.h"

point::point()
{
    x=0;
    y=0;
}

point::point(int x1, int y1)
{
    x=x1;
    y=y1;
}

point::~point()
{
}

point::point(const point& b)
{
    x=b.x;
    y=b.y;
}

const point& point::operator=(const point& c)
{
    if (this == &c){
        return *this;
    }
    x=c.x;
    y=c.y;
    return *this;
}

void point::setPoints(int x1, int y1)
{
    x=x1;
    y=y1;
}

int point::getX()
{
    return x;
}

int point::getY()
{
    return y;
}

