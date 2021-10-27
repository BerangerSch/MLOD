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


void afficheElement(Liste l){
	printf("%s, %s, %s, %s, %s, %s, %s\n", l->name, l-> artist, l->album, l->genre, l->discNumber, l->trackNumber, l->year);
}

void afficheListe_i(Liste l) {
	Liste p = l;

	while(!estVide(p)){
		afficheElement(l);
		p=p->suiv;
	}
}

// version recursive
void afficheListe_r(Liste l) {
	Liste p = l;
	if (!estVide(p)){
		afficheElement(p);
		afficheListe_r(p->suiv);
	}else{
		printf("\n");
	}
}

void detruireElement(Element e){
	free(e);
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste p;

	while(!estVide(l)){
		p=l;
		l=l->suiv;
		detruireElement(p->name);
		detruireElement(p->artist);
		detruireElement(p->album);
		detruireElement(p->genre);
		detruireElement(p->discNumber);
		detruireElement(p->trackNumber);
		detruireElement(p->year);
		free(p);
	}
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->name);
		detruireElement(l->artist);
		detruireElement(l->album);
		detruireElement(l->genre);
		detruireElement(l->discNumber);
		detruireElement(l->trackNumber);
		detruireElement(l->year);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Music* m, Liste l) {
	Liste p = l;

	if(estVide(l)){
		return creer(m->name, m->artist, m->album, m->genre, m->discNumber, m->trackNumber, m->year);
	}

	//temp !=NULL
	while(!estVide(p->suiv)){
		p = p->suiv;
	}
	p->suiv = creer(m->name, m->artist, m->album, m->genre, m->discNumber, m->trackNumber, m->year);

	return l;
}

// version recursive
Liste ajoutFin_r(Music* m, Liste l) {
	if(estVide(l)){
		return creer(m->name, m->artist, m->album, m->genre, m->discNumber, m->trackNumber, m->year);
	}else{
		l->suiv = ajoutFin_r(m, l->suiv);
	}
	return l;
}


bool equalsElement(Element e1, Element e2){
	if (e1 == e2){
		return true;
	}else{
		return false;
	}
	
}
// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element name, Element artist, Element album, Liste l) {
	Liste p = l;
	while(!estVide(p) && (!equalsElement(name, p->name) && !equalsElement(artist, p->artist) && !equalsElement(album, p->album))){
		p=p->suiv;
	}
	// p==NULL || (p->name==name && p->artist==artist && p->album==album)
	return p;
}

// version récursive
Liste cherche_r(Element name, Element artist, Element album, Liste l) {
	if(estVide(l) || (equalsElement(name, l->name) && equalsElement(artist, l->artist) && equalsElement(album, l->album))){
		return l;
	}
	else{
		return cherche_r(name, artist, album, l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element name, Element artist, Element album, Liste l) {
	Liste precedent, p;

	if(estVide(l)){
		return l;
	}
	if(equalsElement(name, l->name) && equalsElement(artist, l->artist) && equalsElement(album, l->album)){
		p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	precedent = l;
	p = l->suiv;
	while(!estVide(p) && (!equalsElement(name, p->name) && !equalsElement(artist, p->artist) && !equalsElement(album, p->album))){
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
Liste retirePremier_r(Element name, Element artist, Element album, Liste l) {
	if(estVide(l)){
		return l;
	}
	if(equalsElement(name, l->name) && equalsElement(artist, l->artist) && equalsElement(album, l->album)){
		Liste p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	l->suiv = retirePremier_r(name, artist, album, l->suiv);
	return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		if(!estVide(l->suiv)){
			afficheEnvers_r(l->suiv);
		afficheElement(l);
		printf("\n");
		}
	}
}



