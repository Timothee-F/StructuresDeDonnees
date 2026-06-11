#ifndef LISTE_H
#define LISTE_H

typedef struct LC_ { // liste doublement chainee classique (pas circulaire)
	int val;
	struct LC_* suiv;
	struct LC_* pred;
} LC;

LC* initLC(int v);
LC* ajoutLC(int v, LC* lc);
LC* rechercheLC(int v, LC* lc);
LC* suprEltLC(int v, LC* lc);
LC* retourneLC(LC* lc);
void afficheLC(LC* lc);
void libererLC(LC* lc);

#endif
