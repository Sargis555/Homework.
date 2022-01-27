#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <math.h>

class point
{
private:
	int x;
    int y;

public:
	point();
	point(int x1, int y1);
	~point();

public:
	int get_x();
	int get_y();
	void set_x(int x1);
	void set_y(int y1);	
};

class shape
{

public:
	virtual void set_width(point& a, point& b);
	virtual void set_height(point& c, point& d);
	virtual void set_radius(point& a, point& b);
	virtual void area();
};

class rectangle: public shape
{
private:
    int width;
    int height;

public:
	rectangle();
	rectangle( int width1, int height1);
	~rectangle();

public:
	int get_width();
	int get_height();
	void set_width(point& a, point& b);
	void set_height(point& c, point& d);
	void area();
	const rectangle& operator=(const rectangle& c);
	bool operator==(const rectangle& a) const;	
};

class circle: public shape
{
private:
	int radius;

public:
	circle();
	circle(int radius1);
	~circle();

public:
	int get_radius();
	void set_radius(point& a, point& b);
	void area();
	const circle& operator=(const circle& c);
	bool operator==(const circle& a) const;
	
};

class triangle: public shape
{
private:
	int width;
    int height;

public:
	triangle();
	triangle(int width1, int height1);
	 ~triangle();

public:
	int get_width();
	int get_height();
	void set_width(point& a, point& b);
	void set_height(point& c, point& d);
	double rezult=0;
	void area();
	const triangle& operator=(const triangle& c);
	bool operator==(const triangle& a) const;
	
};

#endif
