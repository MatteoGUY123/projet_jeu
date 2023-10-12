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
int PiocherCard(int *nombre_carte);
void PrintCard(int a,int *nombre_carte, struct Card *arr_card, struct Card *votre_main);
void ChoixAction(struct Card* arr_card);
void Attaquer();

#endif // !Launcher_h

