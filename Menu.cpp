#include <iostream>
#include <cstdio>
#include "Menu.h"

int Menu_Proc(Menu* Menu_X)
// Print Menu, input menu item and check
{
	int i, inpres;
	int ichoice = -1;

	setlocale(LC_ALL, ".866");

	while (ichoice == -1) {
		wprintf(L"\n%s", Menu_X->name);
		for (i = 0; i < Menu_X->it_count; i++) {
			if (Menu_X->av[i])
				wprintf(L"\n%2i - %s", i, Menu_X->item[i]);
		}
		wprintf(L"\n");
		fflush(stdin);
		inpres = wscanf(L"%i", &ichoice); // 1 - soccess readed field, 0 - else
		if ((inpres = 0) || (ichoice < 0) || (ichoice >(i - 1)) || ((ichoice >= 0) && (ichoice < (i - 1)) && !Menu_X->av[ichoice])) {
			wprintf(L"\n*** Значение не распознано\n");
			ichoice = -1; };
		}; // while
	return ichoice;
}
