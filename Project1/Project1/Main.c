#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Launcher.h"


int main() {
	struct Card arr_card[10] = {
		{0,"thanos", 4, 6, 20, 10},
		{1,"pion1", 3, 1, 10, 4},
		{2,"pion2", 4, 2, 5, 4},
		{3,"chevalier", 6, 7, 10, 6},
		{4,"Mage", 7, 1, 10, 7},
		{5,"Hobo", 2, 1, 1, 1},
		{6,"La_chose", 2, 5, 20, 8},
		{7,"Iron_man", 10, 3, 7, 8},
		{8,"Le_chauve", 5, 5, 15, 5},
		{9,"assassin", 8, 0, 5, 6}
	};
	StartApp();
	MainMenu(arr_card);
	EndApp();

	return 0;

}
