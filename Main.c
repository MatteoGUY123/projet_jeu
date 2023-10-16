#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Launcher.h"
#include <stdbool.h>


int main(void) {
	struct Card arr_card[10] = {
		{0,"thanos", 4, 6, 20, 10,true},
		{1,"pion1", 3, 1, 10, 4,true},
		{2,"pion2", 4, 2, 5, 4,true},
		{3,"chevalier", 6, 7, 10, 6,true},
		{4,"Mage", 7, 1, 10, 7,true},
		{5,"Hobo", 2, 1, 1, 1,true},
		{6,"La_chose", 2, 5, 20, 8,true},
		{7,"Iron_man", 10, 3, 7, 8,true},
		{8,"Le_chauve", 5, 5, 15, 5,true},
		{9,"assassin", 8, 0, 5, 6,true}
	};
	StartApp();
	MainMenu(arr_card);
	EndApp();

	return 0;


}
