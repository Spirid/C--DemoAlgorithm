#include <iostream>
#include <cstdio>

#include "Point.h"

using namespace std;


Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

bool Point::operator < (const Point& other) const
{
	return (m_x*m_x + m_y*m_y) < (other.m_x*other.m_x + other.m_y*other.m_y);
}

bool Point::operator == (const Point& other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

bool Point::operator()(const Point& left, const Point& right)
{
	return (left < right);
}

 // * * *
ostream & operator << (ostream & os, const Point& p)
{
	os << p.m_x << ", " << p.m_y;
	return os;
};

ostream & operator << (ostream & os, const Point* pp)
{
	os << pp->m_x << ", " << pp->m_y;
	return os;
};