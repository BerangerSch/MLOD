#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year){
	Liste liste = (Liste)malloc(sizeof(Music));
	liste->name = name;
	liste->artist = artist;
	liste->album = album;
	liste->genre = genre;
	liste->discNumber = discNumber;
	liste->trackNumber = trackNumber;
	liste->year = year;
	liste->suiv = NULL;
	return liste;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l) {
	Liste n = creer(name, artist, album, genre, discNumber, trackNumber, year);
	n->suiv = l;
	return n;
}


// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;

	while(!estVide(p)){
		afficheElement(p->name, p->artist, p->album, p->genre, p->discNumber, p->trackNumber, p->year);
		p=p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (!estVide(l)){
		afficheElement(l->name, l->artist, l->album, l->genre, l->discNumber, l->trackNumber, l->year);
		afficheListe_r(l->suiv);
	}else{
		printf("\n");
	}
}


// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste p;

	while(!estVide(l)){
		p=l;
		l=l->suiv;
		detruireElement(p->name, p->artist, p->album, p->genre, p->discNumber, p->trackNumber, p->year);
		free(p);
	}
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->name, l->artist, l->album, l->genre, l->discNumber, l->trackNumber, l->year);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l) {
	Liste p = l;

	if(estVide(l)){
		return creer(name, artist, album, genre, discNumber, trackNumber, year);
	}

	//temp !=NULL
	while(!estVide(p->suiv)){
		p = p->suiv;
	}
	p->suiv = creer(name, artist, album, genre, discNumber, trackNumber, year);

	return l;
}

// version recursive
Liste ajoutFin_r(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l) {
	if(estVide(l)){
		return creer(v);
	}else{
		l->suiv = ajoutFin_r(v, l->suiv);
	}
	return l;
}



// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p = l;
	while(!estVide(p) && !equalsElement(v,p->val)){
		p=p->suiv;
	}
	// p==NULL || p->val==v
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(estVide(l) || equalsElement(v, l->val)){
		return l;
	}
	else{
		return cherche_r(v, l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent, p;

	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val, v)){
		p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	precedent = l;
	p = l->suiv;
	while(!estVide(p) && !equalsElement(p->val, v)){
		precedent = p;
		p = p->suiv;
	}
	if(!estVide(p)){
		precedent->suiv = p->suiv;
		p->suiv = NULL;
		detruire_r(p);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val, v)){
		Liste p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	l->suiv = retirePremier_r(v, l->suiv);
	return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		if(!estVide(l->suiv)){
			afficheEnvers_r(l->suiv);
		afficheElement(l->val);
		printf(" ");
		}
	}
}



