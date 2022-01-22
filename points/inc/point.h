#ifndef POINT_H
#define POINT_H

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
    point(const point& b);
    const point& operator=(const point& c);
    ~point();   
    void setPoints(int x1, int y1);
    int getX();
    int getY();
  
};

class line
{
private:
    point a;
    point b;
public:
    line();
    line(point a1, point b1);
    ~line();
    void setA(point a1);
    void setB(point b1);
    int getLength();
    static void comparison(int line1, int line2);
};

#endif
