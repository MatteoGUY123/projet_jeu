//
//  Display.c
//  Local_Projet_jeu
//
//  Created by Kevin on 16/10/2023.
//
#include <stdio.h>
#include "Launcher.h"
#include "Display.h"

void PrintCard(int a, int *nombre_carte, struct Card* cards, struct Card *votre_main)
{
    printf("Vous avez piochez cette carte : \n");
    printf("Nom : %s\n", cards[a].Name);
    printf("Attaque : %d\n", cards[a].Attack);
    printf("Defense : %d\n", cards[a].Defence);
    printf("Pv : %d\n", cards[a].Pv);
    printf("Cout : %d\n", cards[a].Cost);
    printf("\n");
    votre_main[*nombre_carte] = cards[a];
}

void ShowHand(int *nombre_carte, struct Card *votre_main) {
    for (int i = 0; i < *nombre_carte; i++)
    {
        printf("Votre %d carte : \n", i+1);
        printf("Nom : %s\n", votre_main[i].Name);
        printf("Attaque : %d\n", votre_main[i].Attack);
        printf("Defense : %d\n", votre_main[i].Defence);
        printf("Pv : %d\n", votre_main[i].Pv);
        printf("Cout : %d\n", votre_main[i].Cost);
        printf("\n");
    }
}
