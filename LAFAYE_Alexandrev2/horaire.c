/* Fichier : horaire.c
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

#include <stdio.h>

#define JOURNEE 86400
#define HEURE 3600
#define MINUTE 60

/*Permet de passer du format HH:MM:SS a des secondes.*/
long heure_2_seconde(int h, int m, int s){
    long secondes;

    secondes = h*HEURE + m*MINUTE + s;
    return secondes;
}

/*
 * Permet de passer des secondes au format HH:MM:SS
 * Il faut lui passer un buffer de int de taille au moins 3.
 */
void seconde_2_heure(int *heure, long secondes){

    heure[0] = secondes/HEURE;
    secondes -= heure[0]*HEURE;
    heure[1] = secondes/MINUTE;
    secondes -= heure[1]*MINUTE;
    heure[2] = secondes;
}

/*
 * Fonction calculant l'heure d'arrivee a partir du depart et de la duree.
 */
void heure_arrivee(void){
    /*Les ints representent les heures sous forme HH:MM:SS*/
    int heure_depart_h, heure_depart_m, heure_depart_s;
    int temps_trajet_h, temps_trajet_m, temps_trajet_s;
    int heure[3] = {0};

    /*Les longs servent à representer le temps sous forme de secondes.*/
    long depart, temps_trajet, arrivee;

    printf("Entrez l'heure de départ (HH:MM:SS) : ");
    scanf("%d:%d:%d", &heure_depart_h, &heure_depart_m, &heure_depart_s);
    fflush(stdin);
    printf("Entrez le temps de trajet (HH:MM:SS) : ");
    scanf("%d:%d:%d", &temps_trajet_h, &temps_trajet_m, &temps_trajet_s);
    scanf("d");
    fflush(stdin);

    depart = heure_2_seconde(heure_depart_h, heure_depart_m, heure_depart_s);
    temps_trajet = heure_2_seconde(temps_trajet_h,
				   temps_trajet_m,
				   temps_trajet_s);

    if(depart + temps_trajet > JOURNEE){
	temps_trajet -= JOURNEE;
    }

    arrivee = temps_trajet + depart;

    seconde_2_heure(heure, arrivee);

    printf("L'heure d'arrivee sera %02d:%02d:%02d.\n",
	    heure[0], heure[1], heure[2]);

}

/*Calcule le temps de trajet a partir du depart et de l'arrivee*/
void temps_trajet(void){
    /*Les ints representent les heures sous forme HH:MM:SS*/
    int heure_depart_h, heure_depart_m, heure_depart_s;
    int heure_arrivee_h, heure_arrivee_m, heure_arrivee_s;
    int heure[3] = {0};

    /*Les longs servent à representer le temps sous forme de secondes.*/
    long depart, arrivee, temps_trajet_tot;

    printf("Entrez l'heure de départ (HH:MM:SS) : ");
    scanf("%d:%d:%d", &heure_depart_h, &heure_depart_m, &heure_depart_s);
    fflush(stdin);
    printf("Entrez l'heure d'arrivée (HH:MM:SS) : ");
    scanf("%d:%d:%d", &heure_arrivee_h, &heure_arrivee_m, &heure_arrivee_s);
    fflush(stdin);


    depart = heure_2_seconde(heure_depart_h, heure_depart_m, heure_depart_s);
    arrivee = heure_2_seconde(heure_arrivee_h,
	    		      heure_arrivee_m,
	    		      heure_arrivee_s);

    if(arrivee < depart){
	arrivee += JOURNEE;
    }

    temps_trajet_tot = arrivee - depart;

    seconde_2_heure(heure, temps_trajet_tot);

    printf("Le temps de trajet total est %02d:%02d:%02d.\n",
	    heure[0], heure[1], heure[2]);
}

