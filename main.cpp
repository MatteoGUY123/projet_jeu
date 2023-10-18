#include "mainwindow.h"


#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

extern "C" {
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include "Launch.h"

struct Card votre_main[10];
struct Card main_ennemie[10];
int number_cart = 0;
int number_ennemie_cart = 0;
void StartApp() {
    printf("App has been started! \n");
}
void EndApp() {
    printf("App has been closed! \n");
}

void PrintCard(int a, int *nombre_carte, struct Card* cards, struct Card *votre_main)
{
    printf("Vous avez piochez cette carte : \n");
    printf("Nom : %s\n", cards[a].Name);
    printf("Attaque : %d\n", cards[a].Attack);
    printf("Défense : %d\n", cards[a].Defence);
        printf("Pv : %d\n", cards[a].Pv);
    printf("Cout : %d\n", cards[a].Cost);
    printf("\n");
    votre_main[*nombre_carte] = cards[a];
}
void Attaquer(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie)
{
    int carte_choisi = 0;
    printf("choisissez la carte que vous voulez utiliser : \n");
    scanf_s("%d", &carte_choisi);
    if (votre_main[carte_choisi].Alive == false)
    {
        printf("votre carte choisi est morte, veuillez en choisir une autre :");
        scanf_s("%d", &carte_choisi);
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
    printf("choisissez la carte que vous voulez utiliser pour vous défendre : \n");
        scanf_s("%d", &carte_choisi);
    if (votre_main[carte_choisi].Alive == false)
    {
        printf("votre carte choisi est morte, veuillez en choisir une autre :");
        scanf_s("%d", &carte_choisi);
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
void ShowHand(int *nombre_carte, struct Card *votre_main) {
    for (int i = 0; i < *nombre_carte; i++)
    {
        printf("Votre %d carte : \n", i+1);
        printf("Nom : %s\n", votre_main[i].Name);
        printf("Attaque : %d\n", votre_main[i].Attack);
        printf("Défense : %d\n", votre_main[i].Defence);
            printf("Pv : %d\n", votre_main[i].Pv);
        printf("Coût : %d\n", votre_main[i].Cost);
            printf("\n");
    }
}
int PiocherCard(int *nombre_carte) {
    int NB_CARTES = 10;
    int j = rand() % NB_CARTES;
    (*nombre_carte)++;

    return j;
}
void ChoixAction(struct Card *card) {
    int Choix_action = 0;
    printf("que voulez vous faire ? \n");
    printf("1 : Attaquer \n");
    printf("2 : Piochez une autre carte \n");
    printf("3 : Voir votre main \n");
    printf("4 : abandonner la partie \n");
    scanf_s("%d",&Choix_action);
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

void MainMenu(struct Card *card)
{
    /* enum MenuButtons
    {
        New_Game = 1,
        Load_adventure,
        Option,
        Quit,
    }; */
    int MenuChoice = 1;

    //enum MenuButtons  MyMenuButtons = MenuChoice;
    int Choice = 0;
    while (MenuChoice != 4)
    {
        printf("choisissez votre option \n");
        printf("1 : Start game \n");
        printf("2 : Load game \n");
        printf("3 : Option \n");
        printf("4 : quit \n");
        scanf_s("%d", &MenuChoice);
        if (MenuChoice < 1 || MenuChoice > 4) {
            printf("choissisez un nombre en 1 et 4");
            scanf_s("%d", &MenuChoice);
        }
        switch (MenuChoice)
        {
        case 1:
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
        case 2:
            printf("partie load \n");
            break;
        case 3:
            printf("vous etes dans les options \n");
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}
}
