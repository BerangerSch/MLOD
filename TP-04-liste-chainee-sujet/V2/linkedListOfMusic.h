#pragma once

#include <stdbool.h>

typedef void* Element;

struct music_s {
	Element name;
	Element artist;
	Element album;
	Element genre;
	Element discNumber;
	Element trackNumber;
	Element year;
	struct music_s* suiv;
};

typedef struct music_s Music;
typedef Music* Liste;


extern void afficheElement(Element e);
extern void detruireElement(Element e);
extern bool equalsElement(Element e1, Element e2);


bool estVide(Liste l);
Liste creer(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year);
Liste ajoutTete(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l);

void afficheListe_i(Liste l);
void afficheListe_r(Liste l);

void detruire_i(Liste l);
void detruire_r(Liste l);

Liste ajoutFin_i(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l);
Liste ajoutFin_r(Element name, Element artist, Element album, Element genre, Element discNumber, Element trackNumber, Element year, Liste l);

Liste cherche_i(Element name, Element artist, Element album,Liste l);
Liste cherche_r(Element name, Element artist, Element album,Liste l);

Liste retirePremier_i(Element name, Element artist, Element album, Liste l);
Liste retirePremier_r(Element name, Element artist, Element album, Liste l);

void afficheEnvers_r(Liste l);
