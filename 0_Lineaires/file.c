#include <stdlib.h>
#include <stdio.h>
#include "file.h"

file* newFile(){
	file* retour=malloc(sizeof(file));
	retour->first=NULL;
	retour->last=NULL;
	return retour;
}

int estVideFile(file* f){
	return (f->first==NULL && f->last==NULL);
}

file* addFile(int v, file* f){
	if(f==NULL){
		f=newFile();
	}
	cell* c=malloc(sizeof(cell));
	c->val=v;
	c->suiv=NULL;
	if(estVideFile(f)){
		f->first=c;
		f->last=c;
	} else {
		f->last->suiv=c;
		f->last=c;
	}
	return f;
}

cell* pop(file* f){
	if(estVideFile(f)){
		return NULL;
	} else {
		cell* c=f->first;
		if(f->first==f->last){
			f->last=NULL;
		}
		f->first=f->first->suiv;
		return c;
	}	
}

void afficheFile(file* f){
	cell* c=f->first;
	while(c!=NULL){
		printf("%d\t",c->val);
		c=c->suiv;
	}
	printf("\n");
}


