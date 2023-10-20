//
//  Actions.c
//  Local_Projet_jeu
//
//  Created by Kevin on 16/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "Platforms.h"
#include "Launcher.h"
#include "Actions.h"
#include "Display.h"

void Attaquer(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie)
{
    int carte_choisi = 0;
    printf("choisissez la carte que vous voulez utiliser : \n");
#if (VisualStudioCompiler == 1)
    scanf_s("%d", &carte_choisi);
#else
    scanf("%d", &carte_choisi);
#endif
    if (votre_main[carte_choisi].Alive == false)
    {
        printf("votre carte choisi est morte, veuillez en choisir une autre :");
#if VisualStudioCompiler == 1
        scanf_s("%d", &carte_choisi);
#else
        scanf("%d", &carte_choisi);
#endif
    }
    int carte_ennemie = (rand() % *nombre_ennemie_carte) + 1;
    printf("votre carte choisi : %s \n", votre_main[carte_choisi].Name);
    printf("la carte de l'ennemie : %s \n", main_ennemie[carte_ennemie].Name);
    /*if (votre_main[carte_choisi].Attack > main_ennemie[carte_ennemie].Pv)
    {
        printf("Vous avez tuer la carte ennemie \n");
    }
    else
        printf("Vous n'avez pas tuer la carte ennemie \n");
}*/
    main_ennemie[carte_ennemie].Pv = main_ennemie[carte_ennemie].Pv - votre_main[carte_choisi].Attack;
    printf("Pv de la carte ennemie apres votre attaque : %d \n", main_ennemie[carte_ennemie].Pv);
    if (main_ennemie[carte_ennemie].Pv <= 0)
    {
        printf("Vous avez tuer la carte ennemie \n");
        main_ennemie[carte_ennemie].Alive = true;
    }
}

void Attaque_ennemie(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie) {
    int carte_choisi = 0;
    printf("choisissez la carte que vous voulez utiliser pour vous defendre : \n");
#if VisualStudioCompiler == 1
        scanf_s("%d", &carte_choisi);
#else
        scanf("%d", &carte_choisi);
#endif
    if (votre_main[carte_choisi].Alive == false)
    {
        printf("votre carte choisi est morte, veuillez en choisir une autre :");
#if VisualStudioCompiler == 1
        scanf_s("%d", &carte_choisi);
#else
        scanf("%d", &carte_choisi);
#endif
    }
    int carte_ennemie = (rand() % *nombre_ennemie_carte) + 1;
    printf("votre carte choisi : %s \n", votre_main[carte_choisi].Name);
    printf("la carte de l'ennemie : %s \n", main_ennemie[carte_ennemie].Name);
    votre_main[carte_choisi].Pv = votre_main[carte_choisi].Pv - main_ennemie[carte_ennemie].Attack;
    printf("Pv de votre carte apres l'attaque ennemie : %d \n", votre_main[carte_choisi].Pv);
    if (main_ennemie[carte_ennemie].Pv <= 0)
    {
        printf("Votre carte est morte \n");
        votre_main[carte_choisi].Alive = true;
    }
}

int PiocherCard(int *nombre_carte) {
    int NB_CARTES = 10;
    int j = rand() % NB_CARTES;
    (*nombre_carte)++;

    return j;
}

void ChoixAction(struct Card *card) {
    struct Card votre_main[10];
    struct Card main_ennemie[10];
    int number_cart = 0;
    int number_ennemie_cart = 0;
    
    int Choix_action = 0;
    printf("que voulez vous faire ? \n");
    printf("1 : Attaquer \n");
    printf("2 : Piochez une autre carte \n");
    printf("3 : Voir votre main \n");
    printf("4 : abandonner la partie \n");
#if VisualStudioCompiler == 1
    scanf_s("%d",&Choix_action);
#else
    scanf("%d",&Choix_action);
#endif
    switch (Choix_action)
    {
    case 1:
        Attaquer(&number_cart,&number_ennemie_cart, votre_main, main_ennemie);
        Attaque_ennemie(&number_cart, &number_ennemie_cart, votre_main, main_ennemie);
        ChoixAction(card);
        break;
    case 2:
        PrintCard(PiocherCard(&number_cart), &number_cart, card, votre_main);
        printf("votre nombre de carte : %d \n", number_cart);
        ChoixAction(card);
    case 3:
        printf("votre nombre de carte : %d \n", number_cart);
        ShowHand(&number_cart, votre_main);
        ChoixAction(card);
    case 4:
        
        break;
    default:
        break;
    }
}
