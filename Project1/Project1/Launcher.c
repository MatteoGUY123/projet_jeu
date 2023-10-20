#include <stdio.h>

#include "Platforms.h"
#include "Launcher.h"
#include "Actions.h"
#include "Display.h"
#define _CRT_SECURE_NO_WARNINGS


void StartApp(void) {
	printf("App has been started! \n");
}
void EndApp(void) {
	printf("App has been closed! \n");
}

void MainMenu(struct Card *card)
{
    struct Card votre_main[10];
    struct Card main_ennemie[10];
    int number_cart = 0;
    int number_ennemie_cart = 0;
    
	enum MenuButtons
	{
		New_Game = 1,
		Load_adventure,
		Option,
		Quit,
  };
	int MenuChoice = 1;


//	enum MenuButtons  MyMenuButtons = MenuChoice;
	while (MenuChoice != 4)
	{
		printf("choisissez votre option \n");
		printf("1 : Start game \n");
		printf("2 : Load game \n");
		printf("3 : Option \n");
		printf("4 : quit \n");
#if VisualStudioCompiler == 1
		scanf_s("%d", &MenuChoice);
#else
        scanf("%d", &MenuChoice);
#endif
		if (MenuChoice < 1 || MenuChoice > 4) {
			printf("choissisez un nombre en 1 et 4");
#if VisualStudioCompiler == 1
			scanf_s("%d", &MenuChoice);
#else
            scanf("%d", &MenuChoice);
#endif
		}
		switch (MenuChoice)
		{
		case New_Game:
			StartApp();
			for (int i = 0; i < 3; i++)
			{
			PrintCard(PiocherCard(&number_cart),&number_cart, card, votre_main);
			printf("votre nombre de carte : %d \n", number_cart);
			PrintCard(PiocherCard(&number_ennemie_cart), &number_ennemie_cart, card, main_ennemie);			
			printf("nombre de carte de l'ennemie : %d \n", number_cart);
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
