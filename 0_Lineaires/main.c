#include "liste.c"
#include "pile.c"
#include "file.c"

int main(){
	pile* p=newPile();
	affichePile(p);
	for(int i=0;i<10;i++){
		empiler(i,p);
		affichePile(p);
	}
	for(int i=0;i<10;i++){
		printf("%d",depiler(p)->val);
		affichePile(p);
	}
	free(p);
	return 0;
}
