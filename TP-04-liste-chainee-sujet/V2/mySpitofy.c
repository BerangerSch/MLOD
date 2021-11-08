// gcc -W -Wall -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

Liste lireCsv(FILE*);
Liste trierParAnnee(Liste l);

// ============
// main
// ============

int main(void){
	Liste l;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = creer("Around the World", "Daft Punk", "Homework", "Techno", "1", "7", "1997");
	l = ajoutTete("Come Together", "The Beatles", "Abbey Road", "Pop", "1", "1", "1969", l);
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	afficheListe_r(l);
	detruire_i(l);

	//====================== ouvrir un fichier CSV =========================

	FILE* monFichier = fopen("music.csv","r");
	if(monFichier == NULL){
		printf("%d : Erreur à l'ouverture du fichier\n", errno);
		return EXIT_FAILURE;
	}
	Liste m = NULL;
	m = lireCsv(monFichier);
	afficheListe_r(m);

	//========================== trier par année ============================

	Liste n = NULL;
	n = trierParAnnee(m);
	afficheListe_r(n);

	detruire_i(m);
	fclose(monFichier);
	detruire_r(n);

	return EXIT_SUCCESS;
}

Liste lireCsv(FILE* csvFile){
	Liste l = NULL;
	char *ligne, *copie;
	Music* temp;

	ligne = calloc(256, sizeof(char));
	while (fgets(ligne, 256, csvFile) != NULL){
		temp = (Music*)malloc(sizeof(Music));

		copie = strdup(ligne);
		if(!copie){
			exit(EXIT_FAILURE);
		}

		temp->name = strsep(&copie, ",\n");
		temp->artist = strsep(&copie, ",\n");
		temp->album = strsep(&copie, ",\n");
		temp->genre = strsep(&copie, ",\n");
		temp->discNumber = strsep(&copie, ",\n");
		temp->trackNumber = strsep(&copie, ",\n");
		temp->year = strsep(&copie, ",\n");

		l = ajoutFin_r(temp, l);
		free(temp);
	}
	free(ligne);
	return l;
}

Liste trierParAnnee(Liste l){
	if(estVide(l) || estVide(l->suiv)){
		return l;
	}

	Liste actu, prec, ancien, precAncien;
	actu = prec = ancien = precAncien = l;

	while(!estVide(actu)){
		if(strcmp(actu->year, ancien->year) <= 0){
			precAncien = prec;
			ancien = actu;
		}
		prec = actu;
		actu = actu->suiv;
	}

	Liste temp;
	if(ancien != l){
		precAncien->suiv = l;
		temp = l->suiv;
		l->suiv = ancien->suiv;
		ancien->suiv = temp;
	}
	ancien->suiv = trierParAnnee(ancien->suiv);

	return ancien;
}