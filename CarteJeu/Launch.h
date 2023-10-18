#ifndef LAUNCH_H
#define LAUNCH_H
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
int PiocherCard(int *nombre_carte);
void PrintCard(int a,int *nombre_carte, struct Card *arr_card, struct Card *votre_main);
void ChoixAction(struct Card* arr_card);
void Attaquer(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie);
void Attaque_ennemie(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie);
#endif // LAUNCH_H
