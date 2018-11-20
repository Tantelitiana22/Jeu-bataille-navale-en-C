#include<stdio.h>
#include<stdlib.h>
#include"projet.h"



int main(void)
{
   int nb_niveaux,nb_types;
   int choix_niveau, choix_mode;
   int success;
   int i,j;
   
   // declaration du tableau de STRING de fichier de niveau (taille encore inconnue)
   STRING *niveau=NULL;

   // declaration du tableau de types de navire (taille encore inconnue)
   TYPE_NAVIRE *type_navire=NULL;

   // declaration de la flotte et de la grille pour un joueur
   FLOTTE flotte;
   GRILLE grille;

   // lecture du fichier jeu.txt
   success=lecture_fichier_parametres(NOM_FICHIER_JEU, &niveau, &nb_niveaux, &type_navire, &nb_types);

   // echec de lecture du fichier ou d'allocation memoire
   if(success!=EXIT_SUCCESS){
      system("pause");
      return EXIT_FAILURE;
   }

  
   
     choix_mode=affiche_menu_mode_et_lire_choix();
		 // choisir choix niveau
		 
		 choix_niveau=affiche_menu_niveau_et_lire_choix( );
		 

		 // lecture du fichier et initialisation de la grille et de la flotte
		 success=lecture_fichier_niveau(niveau[choix_niveau-1], &grille, &flotte);

		 // echec de lecture du fichier ou d'allocation memoire
		 if(success!=EXIT_SUCCESS){
		    system("pause");
		    return EXIT_FAILURE;
		 }

		 /* pour chaque navire, initialisation du nombre de cases non touchees */
		 for(i=0;i<flotte.nb_navires;i++){
		    flotte.t[i].nb_cases_non_touchees=type_navire[flotte.t[i].type -1].taille;
		 }


		 // LA SUITE NE SERT QU'A VERIFIE LES DEUX FONCTIONS DE LECTURE DES FICHIERS
		 

		 /* affichage du tableau niveau */
		 printf("\n");
		 printf("**************** Tableau niveau ****************\n");
		 printf("\n");
		 for(i=0;i<nb_niveaux;i++){
		    printf("%s\n",niveau[i]);
		 }

		 printf("\n");
		 printf("**************** Tableau type_navire ****************\n");
		 printf("\n");
		 /* affichage du tableau type_navire */
		 printf ("Numero\t Taille\t Nom\n");
		 for(i=0;i<nb_types;i++){
		    printf ("%d\t %d\t %s\n", type_navire[i].numero, type_navire[i].taille, type_navire[i].nom);
		 }

		 printf("\n");
		 printf("**************** Grille ****************\n");
		 printf("\n");
		 /* affichage des champs nbl et nbc de la grille */
		 printf("Taille de la grille : %d %d\n",grille.nbl, grille.nbc);

		 printf("\n");
		 /* affichage de la grille */
		 for(i=0;i<grille.nbl;i++){
		    for(j=0;j<grille.nbc;j++){
		       printf("%d ",grille.t[i*grille.nbc+j]);
		    }
			printf("\n");
		 }

		 printf("\n");
		 printf("**************** Flotte ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",flotte.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<flotte.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", flotte.t[i].numero, flotte.t[i].type, flotte.t[i].nb_cases_non_touchees,  type_navire[flotte.t[i].type-1].nom);
		 }
		 printf("\n");

     
		 system("pause");
		 return EXIT_SUCCESS;
	}


