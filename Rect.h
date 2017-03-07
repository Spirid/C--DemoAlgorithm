#pragma once
using namespace std;
class Rect{ // rectangle
public:
	int m_left, m_right, m_top, m_bottom;
	Rect(int = 0, int = 0, int = 0, int = 0);
	~Rect() {};

	bool operator < (const Rect&) const;
	bool operator()(const Rect&, const Rect&);

	void PrtRect() const;
	void Norm();
	double distance() const;
};

ostream & operator << (ostream & os, const Rect&);
ostream & operator << (ostream & os, const Rect*);