#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

pile* newPile(){
	pile* retour=malloc(sizeof(pile));
	retour->haut=NULL;
	return retour;
}

int estVidePile(pile* p){
	return (p->haut==NULL);
}

pile* empiler(int v, pile* p){
	if(p==NULL){
		p=newPile();
	}
	cell* c=malloc(sizeof(cell));
	c->val=v;
	c->suiv=NULL;
	if(estVidePile(p)){
		p->haut=c;
	} else {
		c->suiv=p->haut;
		p->haut=c;
	}
	return p;
}

cell* depiler(pile* p){
	if(estVidePile(p)){
		return NULL;
	} else {
		cell* c=p->haut;
		p->haut=p->haut->suiv;
		return c;
	}	
}

void affichePile(pile* p){
	cell* c=p->haut;
	while(c!=NULL){
		printf("%d\t",c->val);
		c=c->suiv;
	}
	printf("\n");
}


