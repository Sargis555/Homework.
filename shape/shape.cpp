#include "shape.h"

point::point()
{
    x = 0;
    y = 0;
}

point::point(int x1, int y1)
{
    x = x1;
    y = y1;
}

point::~point()
{

}

int point::get_x()
{
    return x;
}

int point::get_y()
{
    return y;
}

void point::set_x(int x1)
{
    x = x1;
}

void point::set_y(int y1)
{
    y = y1;
}

void point::moveTo(int& x1, int& y1)
{
    x = x + x1;
    y = y + y1;
}


void shape::set_width(point& a, point& b)
{

}

void shape::set_height(point& c, point& d)
{

}


int shape::area()
{
	return 0;
}

rectangle::rectangle()
{
     width = 0;
     height = 0;
}

rectangle::rectangle( int width1, int height1)
{
    width = width1;
    height = height1;
}

rectangle::~rectangle()
{

}

int rectangle::get_width()
{
    return width;
}

int rectangle::get_height()
{
    return height;
}

void rectangle::set_width(point& a, point& b)
{
    width = sqrt(pow(b.get_x()-a.get_x(),2)+pow(b.get_y()-a.get_y(),2));
}

void rectangle::set_height(point& c, point& d)
{
    height =sqrt(pow(d.get_x()-c.get_x(),2)+pow(d.get_y()-c.get_y(),2));
}

int rectangle::area()
{
    int rezult = get_width() * get_height();
	return rezult;
}

const rectangle& rectangle::operator=(const rectangle& c)
{
    if (this == &c){
        return *this;
    }
    width = c.width;
    height = c.height;
    return *this;
}

bool rectangle::operator==(const rectangle& a) const
{
    if (this == &a){
        return true;
    }
    if ((width == a.width)&&(height == a.height)){
        return true;
    }
    else
        return false;
}

circle::circle()
{
    radius = 0;
}

circle::circle(int radius1)
{
    radius = radius1;
}

circle::~circle()
{

}

int circle::get_radius()
{
    return radius;
}

void circle::set_radius(point& a, point& b)
{
    radius = sqrt(pow(b.get_x()-a.get_x(),2)+pow(b.get_y()-a.get_y(),2));
}

int circle::area()
{
    double p =3.14;
    double rezult = p * pow(get_radius(),2);
	return rezult;
}

const circle& circle::operator=(const circle& c)
{
    if (this == &c){
        return *this;
    }
    radius = c.radius;
    return *this;
}

bool circle::operator==(const circle& a) const
{
    if (this == &a){
        return true;
    }
    if (radius == a.radius){
        return true;
    }
    else
        return false;
}

triangle::triangle()
{
    width = 0;
    height = 0;
}

triangle::triangle(int width1, int height1)
{
    width = width1;
    height = height1;
}

triangle::~triangle()
{

}

int triangle::get_width()
{
    return width;
}

int triangle::get_height()
{
    return height;
}

void triangle::set_width(point& a, point& b)
{
    width = sqrt(pow(b.get_x()-a.get_x(),2)+pow(b.get_y()-a.get_y(),2));
}

void triangle::set_height(point& c, point& d)
{
    height = sqrt(pow(d.get_x()-c.get_x(),2)+pow(d.get_y()-c.get_y(),2));
}

int triangle::area()
{
    area1 = 0.5 * get_width() * get_height();
	return area1;
}

const triangle& triangle::operator=(const triangle& c)
{
    if (this == &c){
        return *this;
    }
    width = c.width;
    height = c.height;
    area1 = c.area1;
    return *this;
}

bool triangle::operator==(const triangle& a) const
{
    if (this == &a){
        return true;
    }
    if ((width == a.width)&&(height == a.height)&&(area1 == a.area1)){
        return true;
    }
    else
        return false;
}

