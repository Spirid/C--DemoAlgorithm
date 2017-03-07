#include <iostream>
#include <stdlib.h>

#include "Rect.h"

using namespace std;


Rect::Rect(int l, int r, int t, int b)
{
	m_left = l; m_right = r; m_top = t; m_bottom = b;
	Norm();
}

void Rect::PrtRect() const
{
	setlocale(LC_ALL, "rus");
	printf("\n[L]%5i; [R]%5i; [T]%5i; [B]%5i; \n", this->m_left, this->m_right, this->m_top, this->m_bottom);
}

void Rect::Norm(){
	int tmp;
	if (this->m_left > this->m_right) {
		tmp = this->m_left;
		this->m_left = this->m_right;
		this->m_right = tmp;
	}
	if (this->m_bottom < this->m_top) {
		tmp = this->m_top;
		this->m_top = this->m_bottom;
		this->m_bottom = tmp;
	}
}

double Rect::distance() const
{
	return sqrt((double)m_left*m_left + .25 * (double)m_left * m_right + (double)m_right * m_right + (double)m_top * m_top + .25 * (double)m_top * m_bottom + (double)m_bottom * m_bottom);
}

bool Rect::operator < (const Rect& r) const
{
	return distance() < r.distance();
}

bool Rect::operator()(const Rect& left, const Rect& right)
{
	return (left < right);
}

ostream & operator << (ostream & os, const Rect& r)
{
	os << r.distance() << " " << r.m_left << " " << r.m_right << " " << r.m_top << " " << r.m_bottom << "\n";
	return os;
};

ostream & operator << (ostream & os, const Rect* pr)
{
	os << pr->distance() << " " << pr->m_left << " " << pr->m_right << " " << pr->m_top << " " << pr->m_bottom << "\n";
	return os;
};