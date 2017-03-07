//Iterator. Standard algorithms. Predicates.
#include <tchar.h>
#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <locale>
#include <string.h>

#include "Iter_Alg.h"
#include "Menu.h"
#include "Rect.h"
#include "Point.h"

using namespace std;
#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{


	Menu Menu_main[] = {
		{ L"OOP. Practical",
		{
			L"Exit",
			L"Revers iterators",
			L"Flow iterators",
			L"Insert iterators",
			L"Algorithm for_each()",
			L"Algorithm find()",
			L"Algorithm sort()",
			L"Algorithm find_if()",
			L"algorithm sort() Rect",
			L"algorithm transform transform to lowerCase",
			L"map<string, int>",
			L"11",
			L"12",
			L"13",
			L"14" },
			{ true, true, true, true, true,
			true, true, true, true, true,
			true, false, false, false, false }, 15 } };

	int choice = 1, inpres = 0;

	system("MODE CON: COLS=150 LINES=2000"); //window size 

	while (choice != 0) {

		choice = Menu_Proc(&Menu_main[0]);

		switch (choice) {
		default: continue;

		case 0: break; //exit

			//Tas 1. Iterators
			//Reverse iterators. Create  set<Point>. Think, that you need to overload in class Poin() < +
			//Create a vector, whose elements are copies of the elements set, but in descending order +
		case 1: {
					setlocale(LC_ALL, "Russian");
					set<Point> s;

					for (size_t i = 0; i < 10; i++)
					{
						s.insert(Point(i, i));
					}
					ContainerPrint(s);

					vector<Point> v{ s.rbegin(), s.rend() };
					ContainerPrint(v);

					continue; };// case 1

			//Flow iterators.
			//Using ostream_iterator output vector and seti, from previous one task, on the the screen. +
		case 2: {
					set<Point> s;

					for (size_t i = 0; i < 10; i++)
					{
						s.insert(Point(i, i));
					}

					vector<Point> v{ s.rbegin(), s.rend() };
					ostream_iterator<Point> os(cout, "\n");
					auto is = s.begin();
					auto iv = v.begin();
					while (is != s.end())
					{
						os = *is;
						os = *iv;
						++is;
					}

					continue; };// case 2

			//Insert iterators.By using return function: +
			//back_inserter() front_inserter() inserter() +
			//adding elements in any of created containers. 
            //Thin:
			//What of iterators can be used with any container. <vector><list><set><map> +
		case 3: {
					int ar[] {0, 1, 2};
					vector<int> v(1);
					auto iv = v.begin();
					list<int> l;
					auto il = l.begin();
					set<int> s;
					auto is = s.begin();
					map<int, int> m;
					auto im = m.begin();
					for (size_t i = 0; i < sizeof(ar) / sizeof(int); i++)
					{
						*inserter(v, iv) = ar[i] + 20; //

						*back_inserter(l) = ar[i];
						*front_inserter(l) = ar[i] + 10;
						*inserter(l, il) = ar[i] + 20;

						*inserter(s, is) = ar[i] + 20;

						*inserter(m, im) = make_pair(ar[i] + 20, ar[i] + 200);
					}
					ContainerPrint(v);
					ContainerPrint(s);
					ContainerPrint(l);
					ContainerPrint(m);

					continue; };// case 3

			//Task 2. Generic algorithms (header <algorithm>). Predicates. 
			//algorithm for_each() - call defined function for each element of container (array, vector, list...) +
			//By using algorithm for_each in ether order for any type elements print element value. +
			//Help: good way is a define called function how a template. +
			//By using algorithm for_each in ether order for Point element type. +
			//change "coordinates"to said value and print the result using last predicate
		case 4: {
					setlocale(LC_ALL, "Russian");
					int ar[] {0, 1, 2, 3, 4};
					vector<int> vi(begin(ar), end(ar));
					list<int> li(begin(ar), end(ar));
					cout << "Array int\n";
					for_each(begin(ar), end(ar), EachPrint<int>);
					cout << "vector int\n";
					for_each(vi.begin(), vi.end(), EachPrint<int>);
					cout << "List int\n";
					for_each(li.begin(), li.end(), EachPrint<int>);

					Point p0[] {{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }}; // Reference
					Point p[] {{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }};
					Point p1(7, 7);

					cout << "Array Point before\n";
					for_each(begin(p), end(p), EachPrint<Point>);
					for_each(begin(p), end(p), chpnt(p1));
					cout << "Array Point after\n";
					for_each(begin(p), end(p), EachPrint<Point>);

					vector<Point> vp(begin(p0), end(p0));
					cout << "Vector Point before\n";
					for_each(vp.begin(), vp.end(), EachPrint<Point>);
					for_each(vp.begin(), vp.end(), chpnt(p1));
					cout << "Vector Point after\n";
					for_each(vp.begin(), vp.end(), EachPrint<Point>);

					list<Point> lp(begin(p0), end(p0));
					cout << "list Point before\n";
					for_each(lp.begin(), lp.end(), EachPrint<Point>);
					for_each(lp.begin(), lp.end(), chpnt(p1));
					cout << "List Point after\n";
					for_each(lp.begin(), lp.end(), EachPrint<Point>);

					continue; };// case 4

			//By using algorithm find() find in any sequence elements Point 
			//all iterators to the Point element with the specified value
		case 5: {
					Point p[] {{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }};
					auto ip = begin(p);
					while (ip != end(p))
					{
						ip = find(ip, end(p), Point(0, 0));
						if (ip != end(p)) { cout << ip << "\n"; ++ip; }
					}

					vector<Point> vp(begin(p), end(p));
					auto iv = vp.begin();
					while (iv != vp.end())
					{
						iv = find(iv, vp.end(), Point(1, 1));
						if (iv != vp.end()) { cout << *iv << "\n"; 	++iv; }
					}

					list<Point> lp(begin(p), end(p));
					auto il = lp.begin();
					while (il != lp.end())
					{
						il = find(il, lp.end(), Point(3, 3));
						if (il != lp.end()) { cout << *il << "\n";	++il; }
					}

					continue; };// case 5

			//By using algorithm sort() sort any sequence elements Poin
			//By default the algorithm sorts the sequence in ascending order
			//What needs to be defined in the class Poin? (+ () ènd <)
			//Note: The algorithm sort dose not work with the list, because it it not inefficiently
			//for list, sortind mast be implemented by the class
		case 6: {
					Point p0[] {{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }};
					array<Point, 15> p = { p0[0], p0[1], p0[2], p0[3], p0[4], p0[5], p0[6], p0[7], p0[8], p0[9], p0[10], p0[11], p0[12], p0[13], p0[14] };

					ContainerPrint(p);
					sort(p.begin(), p.end());
					ContainerPrint(p);

					vector<Point> vp(begin(p), end(p));
					ContainerPrint(vp);
					sort(vp.begin(), vp.end());
					ContainerPrint(vp);

					list<Point> lp(begin(p), end(p));
					ContainerPrint(lp);
					lp.sort();
					ContainerPrint(lp);

					continue; };// case 6

			//By using algorithm find_if() find, in any sequence of element of a Point, iterator to the Point,
			//satisfying: x and y lie in the interval [+n, +m] + functional object
		case 7: {
					Point p0[] {{ 0, 0 }, { -1, 1 }, { -2, 2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, -1 }, { 2, -2 }, { 3, 3 }, { 4, 4 },
					{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }};
					array<Point, 15> p = { p0[0], p0[1], p0[2], p0[3], p0[4], p0[5], p0[6], p0[7], p0[8], p0[9], p0[10], p0[11], p0[12], p0[13], p0[14] };

					auto ip = p.begin();
					while (ip != p.end())
					{
						ip = find_if(ip, p.end(), fndpnt(2, 2));
						if (ip != end(p)) { cout << *ip << "\n"; ++ip; }
					}

					vector<Point> vp(begin(p0), end(p0));
					auto iv = vp.begin();
					while (iv != vp.end())
					{
						iv = find_if(iv, vp.end(), fndpnt(2, 2));
						if (iv != vp.end()) { cout << *iv << "\n"; 	++iv; }
					}

					list<Point> lp(begin(p0), end(p0));
					auto il = lp.begin();
					while (il != lp.end())
					{
						il = find_if(il, lp.end(), fndpnt(2, 2));
						if (il != lp.end()) { cout << *il << "\n";	++il; }
					}

					continue; };// case 7

			//By using algorithm sort() sorting any sequence of elements of the Rect
			//placing the rects to remove the center from the origin
		case 8: {
					Rect r0[10];
					for (size_t i = 0; i < sizeof(r0) / sizeof(Rect); i++)
					{
						r0[i].m_left = -i - 5;
						r0[i].m_right = i + 5;
						r0[i].m_top = -i + 3;
						r0[i].m_bottom = -i - 4;
					}

					array<Rect, 10> r = { r0[9], r0[8], r0[7], r0[6], r0[5], r0[4], r0[3], r0[2], r0[1], r0[0] };
					ContainerPrint(r);
					sort(r.begin(), r.end());
					ContainerPrint(r);

					vector<Rect> vr(begin(r0), end(r0));
					sort(vr.begin(), vr.end());
					ContainerPrint(vr);

					list<Rect> vl(begin(r0), end(r0));
					vl.sort();
					ContainerPrint(vl);

					continue; };// case 8

			//transform
			//Write a function that uses algorithm transform, converts the contents of the string to lowercase
			//fill the list string. with algorithm transform create value "empty" set. by converting string to lowercase
		case 9: {
					list<string> ls{ "ONE", "TWO", "THREE", "FOUR", "FIVE", "Five" };

					set<string> ss;
					auto is = ss.begin();
					transform(ls.begin(), ls.end(), *inserter(ss, is), [](string& s)->string
					{char* c = new char[s.length()]; _locale_t lc = _create_locale(LC_ALL, "Russian"); 
					string s2 = _strlwr_l(strcpy(c, s.c_str()), lc); _free_locale(lc);  return s2; })
					ContainerPrint(ss);

					is = ss.begin();
					transform(ls.begin(), ls.end(), *inserter(ss, is), [](string& s)->string {transform(s.begin(), s.end(), s.begin(), toupper); return s; });
					ContainerPrint(ss);

					set<string> ss2;
					is = ss2.begin();
					transform(ls.begin(), ls.end(), inserter(ss2, is), stringtolwr());
					ContainerPrint(ss2); 

					continue; };// case 9

			// map
			//Create the vector of string elements
			//crate and print map<string, int>, which will contain alphabetically ordered rows and quantity of repeats of each row in vector
		case 10: {
					 vector<string> vs{ "one", "two", "two", "three", "three", "three", "four", "four", "four", "four" };
					 map<string, int> ms;
					 auto im = ms.begin();
					 auto im2 = ms.begin();
					 transform(vs.begin(), vs.end(), inserter(ms, im), fillmap(ms)); //inserter gives end(), 
                     //if it was ("one",1), the functional object return ("one",2)
					 ContainerPrint(ms);

					 continue; };// case 10

		case 11: { continue; };// case 11
		case 12: { continue; };// case 12
		case 13: { continue; };// case 13
		case 14: { continue; };// case 14

		};// switch (nmenu)
	}; //while (nmenu != 0)


	return 0;
}

