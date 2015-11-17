/* Fichier : main.c
 * Auteur  : Alexandre Lafaye
 * Date    : 05.11.2015
 *
 * But     :  Labo08: Calcul de temps de trajets.
 *
 *
 * Remarque(s) : 
 *
 *
 * Compilateur : g++
 * Debuggueur : gdb
 */
/*
 * Pour Windows
 * #define _CRT_SECURE_NO_WARNINGS
 */

#include <stdlib.h>
#include <stdio.h>
#include "horaire.h"


int main(void){
    int choix;
    printf("Programme permettant de calculer un temps de trajet ");
    printf("à partir d'une heure de départ et d'arrivée.\n");
    printf("Ou de trouver l'heure d'arrivée d'un train avec la durée du trajet\n");

    do{
	printf("============== MENU ==============\n");
	printf("1 - Heure d'arrivée.\n");
	printf("2 - Temps de trajet.\n");
	printf("0 - Quitter\n");
	printf("Votre choix : ");
	scanf("%d", &choix);
	switch(choix){
	    case 1:
		heure_arrivee();
		break;
	    case 2:
		temps_trajet();
		break;
	    case 0:
		printf("Fin du programme!\n");
		break;
	    default:
		printf("La valeur entrée n'est pas valable.\n");
		break;
	}
    }
    while(choix != 0);

    return EXIT_SUCCESS;
}
