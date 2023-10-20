#ifndef Launcher_h
#define Launcher_h
#include <stdbool.h>

struct Card {
	int ID;
	char Name[30];
	int Attack;
	int Defence;
	int Pv;
	int Cost;
	bool Alive;
};


void StartApp(void);
void EndApp(void);
void MainMenu(struct Card* card);
#endif // !Launcher_h

