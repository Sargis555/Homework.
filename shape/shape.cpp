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

void shape::set_width(point& a, point& b)
    {
        std::cout<<"set_width"<<'\n';
    }

void shape::set_height(point& c, point& d)
    {
        std::cout<<"set_height"<<'\n';
    }

void shape::set_radius(point& a, point& b)
    {
        std::cout<<"set_radius"<<'\n';
    }

void shape::area()
    {
        std::cout<<"area"<<'\n';
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
        width =sqrt(pow(b.get_x()-a.get_x(),2)+pow(b.get_y()-a.get_y(),2));
    }

void rectangle::set_height(point& c, point& d)
    {
        height =sqrt(pow(d.get_x()-c.get_x(),2)+pow(d.get_y()-c.get_y(),2));
    }

void rectangle::area()
    {
        int rezult = get_width() * get_height();
        std::cout << "rectangle area = "<< rezult <<std::endl;
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

            std::cout<< "true"<<'\n';
            return true;
        }
        else
            std::cout<< "false"<<'\n';
            return false;
    }

circle::circle()
    {
        radius =0;
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

void circle::area()
    {
        double p =3.14;
        double rezult = p * pow(get_radius(),2);
        std::cout << "circle area = "<< rezult <<'\n';
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

//double triangle::rezult = 0;

void triangle::area()
    {
        rezult = 0.5 * get_width() * get_height();
        std::cout << "triangle = "<< rezult <<'\n';
    }

const triangle& triangle::operator=(const triangle& c)
    {
        if (this == &c){
            return *this;
        }
        width = c.width;
        height = c.height;
        rezult = c.rezult;
        return *this;
    }

bool triangle::operator==(const triangle& a) const
    {
        if (this == &a){
            return true;
        }
        if ((width == a.width)&&(height == a.height)&&(rezult == a.rezult)){
            return true;
        }
        else
            return false;
    }

