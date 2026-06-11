#ifndef PILE_H
#define PILE_H
#include "cell.h"

typedef struct pile_ { // aka LIFO
	cell* haut;
} pile;

pile* newPile();
int estVidePile(pile* p);
pile* empiler(int v, pile* p);
cell* depiler(pile* p);
void affichePile(pile* p);

#endif
