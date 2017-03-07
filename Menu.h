#define MENU_NUM 15
#define MENU_NAME_LEN 64

// Abbreviations
// chc - choice выбор
// av - available доступный
// n - number
// it - item пункт (меню)
// proc - processing обработка

typedef struct {
	wchar_t name[MENU_NAME_LEN];
	wchar_t item[MENU_NUM][MENU_NAME_LEN];
	bool av[MENU_NUM];
	int it_count;
	} Menu;

int Menu_Proc(Menu*); // menu printing, input and checking the menu item.
