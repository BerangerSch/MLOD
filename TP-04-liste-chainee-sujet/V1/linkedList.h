#pragma once

#include <stdbool.h>

typedef void* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;
typedef Cellule* Liste;


extern void afficheElement(Element e);
extern void detruireElement(Element e);
extern bool equalsElement(Element e1, Element e2);


bool estVide(Liste l);
Liste creer(Element v);
Liste ajoutTete(Element v, Liste l);

void afficheListe_i(Liste l);
void afficheListe_r(Liste l);

void detruire_i(Liste l);
void detruire_r(Liste l);

Liste ajoutFin_i(Element v, Liste l);
Liste ajoutFin_r(Element v, Liste l);

Liste cherche_i(Element v,Liste l);
Liste cherche_r(Element v,Liste l);

Liste retirePremier_i(Element v, Liste l);
Liste retirePremier_r(Element v, Liste l);

void afficheEnvers_r(Liste l);
