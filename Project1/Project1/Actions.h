//
//  Actions.h
//  Local_Projet_jeu
//
//  Created by Kevin on 16/10/2023.
//

#ifndef Actions_h
#define Actions_h

void Attaquer(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie);
void Attaque_ennemie(int* nombre_carte, int* nombre_ennemie_carte, struct Card* votre_main, struct Card* main_ennemie);
int PiocherCard(int *nombre_carte);
void ChoixAction(struct Card *card);

#endif /* Actions_h */
