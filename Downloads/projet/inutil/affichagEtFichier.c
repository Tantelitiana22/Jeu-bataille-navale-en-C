#include<stdio.h>
#include<stdlib.h>

#include"header.h"


NOM *tableauNiveau(FILE *fichier,int *nb_niveaux){

	int i;
	
  NOM *niveaux;

	fscanf(fichier,"%d",nb_niveaux);
 
  niveaux=(NOM*)calloc(*nb_niveaux,sizeof(NOM));
	if(niveaux==NULL){
	printf("Allocation non effectuer!\n");
	exit(1);
    }

	for(i=0;i<*nb_niveaux;i++){
  
  fscanf(fichier,"%s",niveaux[i]);

  }

  return niveaux;
}



void afficherNiveau(NOM niveau[],int nb_niveaux){

	int i;

 for(i=0;i<nb_niveaux;i++){
 printf("%s\n",niveau[i]);
 }
   
}



TYPE_NAVIRE *tailleNavire(FILE *fichier,int *nb_type){

	int i;
	 TYPE_NAVIRE *tableau;

		fscanf(fichier,"%d",nb_type);
    tableau=(TYPE_NAVIRE*)calloc(*nb_type,sizeof(TYPE_NAVIRE));

		for(i=0;i<*nb_type ;i++){
		fscanf(fichier,"%d %d %s",&tableau[i].numero,&tableau[i].taille,tableau[i].nom);
		}
  
  return tableau;

}


void afficherNavire(TYPE_NAVIRE niveau[],int nb_type){

	int i;

 for(i=0;i<nb_type;i++){
 printf("%d %d %s\n",niveau[i].numero,niveau[i].taille,niveau[i].nom);
 }
   
}




//

TYPE_NIVEAU *RecupNiveau(FILE *fich,DIM *dim){

int i;
TYPE_NIVEAU *niveau;
int temp;

fscanf(fich,"%d %d",&dim->nbLigne,&dim->nbCol);
fscanf(fich,"%d",&temp);

niveau=(TYPE_NIVEAU*)calloc(temp,sizeof(TYPE_NIVEAU));

if(niveau==NULL){
	printf("Allocation non effectuer!\n");
	exit(1);
}

niveau[0].dim.nbLigne=dim->nbLigne;
niveau[0].dim.nbCol=dim->nbCol;
niveau[0].nbNavire=temp;

 for(i=0;i<temp && !feof(fich);i++){
 fscanf(fich,"%d %d",&niveau[i].numType,&niveau[i].NombreNumType);
 
}
return niveau;

 } 






void AffiNiveau(FILE *fichier,TYPE_NIVEAU *niveau){
int i;
printf("%d %d\n",niveau[0].dim.nbLigne,niveau[0].dim.nbCol);
printf("%d\n",niveau[0].nbNavire);

	for(i=0;i<5;i++){
	 printf("%d %d\n",niveau[i].numType,niveau[i].NombreNumType);

	}

}


int affiche_menu_niveau_et_lire_choix(void){

	int choix;

	do{

	printf("Faire choix du niveau\n");
	puts("taper 1 pour niveau 1");
	puts("taper 2 pour niveau 2");
	puts("taper 3 pour niveau 3");
       
	scanf("%d",&choix);

	}while(choix!=1 && choix!=2 && choix!=3 );

return choix;

}


int affiche_menu_mode_et_lire_choix(void){

	int choix;

	do{

	printf("Faire choix du niveau\n");
	puts("taper 1 pour jouer seul");
	puts("taper 2 pour jouer a 2 joueur");
	puts("taper 3 pour jouer contre l'ordinateur");
        puts("tapez 0 pour quiter le programme");
	scanf("%d",&choix);

	}while(choix!=1 && choix!=2 && choix!=3 &&choix!=0 );

return choix;

}




























