#include <algorithm>
using namespace std;

template <typename F, typename S>  ostream & operator << (ostream & os, const pair<F, S>& p)
{
	os << p.first << ", " << p.second;
	return os;
}

template<typename C> void ContainerPrint(C& cont)
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	cout << "* * *\n";
	for (const auto& it : cont)
	{
		cout << "[" << i << "] " << it << "\n";
		i++;
	}
	cout << "* * *\n\n";
}

template<typename D> void EachPrint(const D& data)
{
	cout << data << "\n";
}

//Help: class string - is thealmost container, so for him definition methods begin(), and end().
class stringtolwr
{
public:
	string s;
	string& operator () (string& s)
	{
		transform(s.begin(), s.end(), s.begin(), tolower);
		return s;
		
	}
};

class fillmap
{
public:
	map<string, int>* m;
	fillmap(map<string, int>& ms){ m = &ms; };
	~fillmap(){};
	pair<string, int> operator () (string& s)
	{
		map<string, int>::iterator im = m->find(s);
		pair<string, int> p = make_pair(s, 1);
		if (im != m->end()) (*im).second++;
		return p;
	}
};
