#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

LC* initLC(int v){
	LC* retour = malloc(sizeof(LC));
	retour->val=v;
	retour->suiv=NULL;
	retour->pred=NULL;
	return retour;
}

LC* ajoutLC(int v, LC* lc){ // ajout en tete classique, on renvoie la tete
	LC* nv=initLC(v);
	nv->suiv=lc;
	if(lc!=NULL){
		lc->pred=nv;	
	}
	return nv;
}

LC* rechercheLC(int v, LC* lc){ // renvoie NULL si v n'est pas dans lc
	while(lc!=NULL){
		if (lc->val==v){
			return lc;
		}
		lc=lc->suiv;
	}
	return NULL;
}

LC* suprEltLC(int v, LC* lc){
	LC* tete=lc;
	LC* prec=NULL;
	while(lc!=NULL && lc->val!=v){
		prec=lc;
		lc=lc->suiv;
	}
	if(lc!=NULL){
		if(prec!=NULL){
			prec->suiv=lc->suiv;
			if (lc->suiv !=NULL){
				lc->suiv->pred=prec;
			}
		} else {
			tete=lc->suiv;
			if (lc->suiv !=NULL){
				lc->suiv->pred=NULL;
			}
		}
		free(lc);
	}
	return tete;
}

LC* retourneLC(LC* lc){ // inverse l'ordre des elts
	LC* tete=lc;
	while(lc!=NULL){
		LC* temp=lc->pred;
		lc->pred=lc->suiv;
		lc->suiv=temp;
		tete=lc;
		lc=lc->pred;
	}
	return tete;
}

void afficheLC(LC* lc){
	while(lc!=NULL){
		printf("%d\t",lc->val);
		lc=lc->suiv;
	}
	printf("\n");
	return;
}

void libererLC(LC* lc){
	LC* tmp;
	while(lc!=NULL){
		tmp=lc->suiv;
		free(lc);
		lc=tmp;
	}
}
