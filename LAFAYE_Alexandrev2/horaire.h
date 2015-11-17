/* Fichier : horaire.h
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

/*Permet de passer du format HH:MM:SS a des secondes.*/
long heure_2_seconde(int h, int m, int s);

/*
 * Permet de passer des secondes au format HH:MM:SS
 * Il faut lui passer un buffer de int de taille au moins 3.
 */
void seconde_2_heure(int *heure, long secondes);

/*
 * Fonction calculant l'heure d'arrivee a partir du depart et de la duree.
 */
void heure_arrivee(void);

/*Calcule le temps de trajet a partir du depart et de l'arrivee*/
void temps_trajet(void);
