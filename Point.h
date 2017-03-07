#pragma once
using namespace std;
class Point
{
public:
	int m_x, m_y;
	Point(int x = 0, int y = 0);
	~Point() {};

	bool operator < (const Point&) const;
	bool operator == (const Point&) const;
	bool operator()(const Point &, const Point &);
};

// * * *

ostream & operator << (ostream & os, const Point& p);
ostream & operator << (ostream & os, const Point* pp);
 
// * * * for algoritm

class chpnt
{
public:
	Point pn;
	chpnt(Point p){ this->pn = p; };
	~chpnt(){};
	void operator () (Point& p)
	{
		p = this->pn;
	}
};

//Find iterator in Point in any sequensional of Point witch assistance find_if()
//satisfy the conditions: x and y lie betwenn [-n, +m].
class fndpnt
{
public:
	int c1, c2;
	fndpnt(int n, int m){ c1 = -n; c2 = m; };
	~fndpnt(){};
	bool operator () (Point& p)
	{
		return p.m_x >= c1 && p.m_x <= c2 && p.m_y >= c1 && p.m_y <= c2;
	}
};
