#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"
#include<unistd.h>


/***** Lecture fichier niveau consiste a lire le fichier niveau et a recuperer la grille et la flotte******/


int lecture_fichier_niveau(char* nom_fichier,GRILLE* P_grille, FLOTTE * P_flotte){

   int i,j, nbl, nbc, nb_navires, num_type, nb_du_type;

   FILE *fichier = NULL;

   fichier=fopen(nom_fichier,"rt");

   // si erreur d'ouverture du fichier
   if (fichier == NULL)
   {
      printf("Il est impossible d'ouvrir le fichier %s\n",nom_fichier);
      return EXIT_FAILURE;
   }

   // Initialisation de la grille
   fscanf(fichier,"%d%d", &nbl, &nbc);
   P_grille->nbl=nbl;
   P_grille->nbc=nbc;

   //allocation du tableau de la grille
   P_grille->t=(int*)calloc(nbl*nbc,sizeof(int));

   // si erreur d'allocation
   if(P_grille->t==NULL){
      printf("Erreur d'allocation\n");
      return EXIT_FAILURE;
   }

   //initialisation du tableau de la grille avec des 0
   for(i=0; i<nbl*nbc; i++) P_grille->t[i]=0;


   //initialisation de la flotte
   fscanf(fichier,"%d",&nb_navires);
   P_flotte->nb_navires=nb_navires;
   P_flotte->nb_navires_coules=0;

   //allocation du tableau de la flotte
   P_flotte->t=(NAVIRE*)calloc(nb_navires,sizeof(NAVIRE));

   // si erreur d'allocation
   if(P_flotte->t==NULL){
      printf("Erreur d'allocation\n");
      return EXIT_FAILURE;
   }

   // initialisation des numeros et type des navires
   for(i=0;i<nb_navires;){
      fscanf(fichier,"%d %d", &num_type, &nb_du_type);
      for(j=0;j<nb_du_type;j++){
         P_flotte->t[i+j].type=num_type;
         P_flotte->t[i+j].numero=i+j+1;
         // +1 car le numero 0 est interdit pour les navires sinon probleme pour ecrire un navire dans la grille
      }
      i+=nb_du_type;
   }

   fclose(fichier);

   return EXIT_SUCCESS;
}


/***************************************************************************
                Fonction lecture_fichier_parametres
                
 - Lit le fichier des parametres du jeu : "jeu.txt" par defaut
 - Initialise le nombre de niveaux
 - Cree et initialise le tableau contenant les noms de fichiers de niveau
 - Initialise le nombre de types de navires
 - Cree le tableau des types de navires

 Parametres
 - char* : nom du fichier des parametres du jeu
 - STRING** : adresse du pointeur sur le tableau de noms de fichiers de niveaux
 - int* : adresse de la variable nombre de niveau
 - TYPE_NAVIRE** : adresse du pointeur sur le tableau des types de navires
 - int* : adresse de la variable nombre de types de navires

 Valeur de retour :
 int : EXIT_FAILURE si echec de lecture du fichier ou d'allocation memoire
 EXIT_SUCCESS sinon.
 ****************************************************************************/
int lecture_fichier_parametres(char* nom_fichier, STRING** P_niveau, int* P_nb_niveaux, TYPE_NAVIRE** P_type, int* P_nb_types){//numero taille nom

   int i;
   FILE* entree;

   entree=fopen(nom_fichier, "rt");

  
   if (entree==NULL){
     printf("Erreur d'ouverture en lecture du fichier %s\n",NOM_FICHIER_JEU);
     return EXIT_FAILURE;
   }
  
   fscanf (entree, "%d", P_nb_niveaux );

  
   *P_niveau=(STRING*) calloc(*P_nb_niveaux, sizeof(STRING));

  
   if(*P_niveau==NULL){
     printf("Erreur d'allocation");
     return EXIT_FAILURE;
   }


   for(i=0;i<*P_nb_niveaux;i++){
     fscanf (entree, "%s", (*P_niveau)[i]);
   }

   
   fscanf (entree, "%d", P_nb_types);

   
   *P_type=(TYPE_NAVIRE*) calloc(*P_nb_types, sizeof(TYPE_NAVIRE));

 
   if(*P_type==NULL){
     printf("Erreur d'allocation");
     return EXIT_FAILURE;
   }

   // lecture et stockage des types de navires
   for(i=0;i<*P_nb_types;i++){
    fscanf (entree, "%d%d%s", &(*P_type)[i].numero, &(*P_type)[i].taille, (*P_type)[i].nom);
   }

   fclose(entree);

   return EXIT_SUCCESS;
}
