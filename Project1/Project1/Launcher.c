#include <stdio.h>
#include "Launcher.h"
#define _CRT_SECURE_NO_WARNINGS

struct Card votre_main[10];
int *nombre_carte = 0;
void StartApp() {
	printf("App has been started! \n");
}
void EndApp() {
	printf("App has been closed! \n");
}

void PrintCard(int a, struct Card *cards) {
	printf("Vous avez piochez cette carte : \n");
	printf("Nom : %s\n", cards[a].Name);
	printf("Attaque : %d\n", cards[a].Attack);
	printf("Défense : %d\n", cards[a].Defence);
	printf("Pv : %d\n", cards[a].Pv);
	printf("Coût : %d\n", cards[a].Cost);
	printf("\n");
}

int PiocherCard() {
	int NB_CARTES = 10;
	int j = rand() % NB_CARTES;
	return j;
}
void ChoixAction(struct Card *card) {
	int Choix_action = 0;
	printf("que voulez vous faire ? \n");
	printf("1 : Attaquer \n");
	printf("2 : Piochez une autre carte \n");
	scanf_s("%d",&Choix_action);
	switch (Choix_action)
	{
	case 1:
		printf("Vous avez attaquer");
		break;
	case 2:
		PrintCard(PiocherCard(nombre_carte), card);
	default:
		break;
	}
}

void MainMenu(struct Card *card)
{
	enum MenuButtons
	{
		New_Game = 1,
		Load_adventure,
		Option,
		Quit,
  };
	int MenuChoice = 1;

	enum MenuButtons  MyMenuButtons = MenuChoice;
	int Choice = 0;
	printf("Choisissez : \n");
	printf("1 : Start game \n");
	printf("2 : Load game \n");
	printf("3 : Option \n");
	printf("4 : quit \n");
	while (MenuChoice != 4)
	{
		printf("choisissez votre option");
		scanf_s("%d", &MenuChoice);
		switch (MenuChoice)
		{
		case New_Game:
			StartApp();
			for (int i = 0; i < 3; i++)
			{
			PrintCard(PiocherCard(nombre_carte),card);
			}
			ChoixAction(card);
			break;
		case Load_adventure:
			printf("partie load \n");
			break;
		case Option:
			printf("vous etes dans les options \n");
			break;
		case Quit:
			break;
		default:
			break;
		}
	}
}