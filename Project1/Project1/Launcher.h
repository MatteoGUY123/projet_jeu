#ifndef Launcher_h
#define Launcher_h

struct Card {
	int ID;
	char Name[30];
	int Attack;
	int Defence;
	int Pv;
	int Cost;
};
void StartApp();
void EndApp();
void MainMenu(struct Card* card);
int PiocherCard();
void PrintCard(int a, struct Card *arr_card);
void ChoixAction(struct Card* arr_card);

#endif // !Launcher_h

