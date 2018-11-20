#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"
#include<unistd.h>


void mode_un(GRILLE g,FLOTTE f, TYPE_NAVIRE *type_navire){
	
	
	POSITION arriere;
	
	int i;
	
       
    
		/* pour chaque navire, initialisation du nombre de cases non touchees */
		
		 for(i=0;i<f.nb_navires;i++){
		    f.t[i].nb_cases_non_touchees=type_navire[f.t[i].type -1].taille;
		 }


        positionner_flotte_intelligemment(g,f,type_navire);
				   
				  
	   
		   system("clear"); 
	   
	   do{
	    
	    // On affiche la flotte du joueur
	    
	     printf("\n");
		 printf("**************** Flotte ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",f.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<f.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", f.t[i].numero, f.t[i].type, f.t[i].nb_cases_non_touchees,  type_navire[f.t[i].type-1].nom);
		 }
		 printf("\n");
        printf("************VOTRE GRILLE******************\n");
		afficher_adversaire_grille(g);
	   arriere=afficher_menu_coup_et_lire_choix(g);
	   effectuer_coup(arriere,&g,&f,type_navire);
		 system("clear");

		}while(f.nb_navires!=f.nb_navires_coules);  
		 
		 if(f.nb_navires==f.nb_navires_coules){
			 
			 afficher_adversaire_grille(g);
			 printf("*********************\n");
			 printf("\n********BRAVO********\n");
			 printf("***VOUS AVEZ GAGNE***\n");
			 printf("\n*********************\n");
			 
		 }
		 
		 
	   free(g.t);
	   free(f.t);
 

}


void mode_deux(GRILLE g,GRILLE g_adversaire,FLOTTE f,FLOTTE f_adversaire,TYPE_NAVIRE *type_navire,TYPE_NAVIRE *type_navire_adversaire){
	
	
	int i,choix_mode_position,choix_mode_position_adversaire,si_coul,num_navire,num_navire_adversaire;
    POSITION arriere,arriere_adversaire;
    char Nom_du_joueur1[100];
    char Nom_du_joueur2[100];
    char Code1[10],verifier_code1[10];
    char Code2[10],verifier_code2[10];
   /* pour chaque navire, initialisation du nombre de cases non touchees */
		
		 for(i=0;i<f.nb_navires;i++){
		    f.t[i].nb_cases_non_touchees=type_navire[f.t[i].type -1].taille;
		    num_navire=f.t[i].numero;
		 }

	     for(i=0;i<f_adversaire.nb_navires;i++){
		    f_adversaire.t[i].nb_cases_non_touchees=type_navire[f_adversaire.t[i].type -1].taille;
		    num_navire_adversaire=f_adversaire.t[i].numero;
		 }
		 
		 //Pour eviter la triche , on va faire des identifiants et une petite code avec
		printf("Entrez votre Prenom joueur numero 1: ");
		 scanf("%s",Nom_du_joueur1);
		
		printf("%s entrez un code ",Nom_du_joueur1);
		scanf("%s",Code1);
		
		system("clear");
		
		printf("Entrez votre Prenom joueur numero 2: ");
		 scanf("%s",Nom_du_joueur2); 
		 
		 printf("%s entrez un code ",Nom_du_joueur2);
		scanf("%s",Code2);
		 
		 system("clear");
		 
		 //Si on est un peu flemard, on peut positionner automatiquement sinon on le fait manuellement
		do{
		
		printf("%s:CHOISISSEZ LE MODE DE POSITIONEMENT DES NAVIRE\n",Nom_du_joueur1);
		printf("Pour une saisi automatique:tapez 1\n");
		printf("Pour une saisi manuellement: tapez 2\n");
		
		vider_buffer_clavier();
		scanf("%d",&choix_mode_position); 
       
	    }while(choix_mode_position!=1 && choix_mode_position!=2);
	    
	    
	    
	    if(choix_mode_position==1){
		
		positionner_flotte_intelligemment(g,f,type_navire);	
			
		}else{
		
		positionner_flotte_manuelement(g,f);	
		afficher_grille(g);	
		}
		
		system("clear");
		
		//il en est de meme ici
		do{
		 
		printf("%s:CHOISISSEZ LE MODE DE POSITIONEMENT DES NAVIRE\n",Nom_du_joueur2);
		printf("Pour une saisi automatique:tapez 1\n");
		printf("Pour une saisi manuellement: tapez 2\n");
		
		vider_buffer_clavier();
		scanf("%d",&choix_mode_position_adversaire); 
       
	    }while(choix_mode_position_adversaire!=1 && choix_mode_position_adversaire!=2);
	    
	    
	    
	    if(choix_mode_position_adversaire==1){
		
		positionner_flotte_intelligemment(g_adversaire,f_adversaire,type_navire_adversaire);	
			
		}else{
		
		positionner_flotte_manuelement(g_adversaire,f_adversaire);	
		afficher_grille(g_adversaire);
		
		}
		
		system("clear");
		
		
		do{
			
			      //Petite verification avant de jouer pour le joueur 1
				
				do{
					printf("Entrez votre code %s\n",Nom_du_joueur1);
					scanf("%s",verifier_code1);
					
					if(verifier_code(Code1,verifier_code1)==0){
						printf("Mauvaise code!\n");
					}
					
				}while(verifier_code(Code1,verifier_code1)==0);
				
				
				
			// On affiche la flotte du joueur 
	    
	     printf("\n");
		 printf("**************** VOTRE FLOTTE ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",f.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<f.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", f.t[i].numero, f.t[i].type, f.t[i].nb_cases_non_touchees,  type_navire[f.t[i].type-1].nom);
		 }	
			
			
			printf("Votre Grille\n");
			afficher_grille(g);
			
			
			// On affiche la flotte de l'adversaire
	    
	     printf("\n");
		 printf("**************** FLOTTE DE L'ADVERSAIRE ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",f_adversaire.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<f_adversaire.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", f_adversaire.t[i].numero, f_adversaire.t[i].type, f_adversaire.t[i].nb_cases_non_touchees,  type_navire[f_adversaire.t[i].type-1].nom);
		 }
			
			
			printf("Grille de l'adversaire\n");
			
            afficher_adversaire_grille(g_adversaire);
			printf("%s\n",Nom_du_joueur1);
			
			//On affiche le menu coup et on fait un coup
			arriere_adversaire=afficher_menu_coup_et_lire_choix(g_adversaire);
			
			//Si le coup est operationnel on effectu le coup
			effectuer_coup(arriere_adversaire,&g_adversaire,&f_adversaire,type_navire_adversaire);	
			printf("Grille de l'adversaire\n");
			
			//ON reaffiche une nouvelle fois la grille de l'adversaire pour voir le coup qu'on a fait
            afficher_adversaire_grille(g_adversaire);
            
            sleep(3);
            system("clear");
            
             //Petite verification avant de jouer pour le joueur 2
            
            do{
					printf("Entrez votre code %s\n",Nom_du_joueur2);
					scanf("%s",verifier_code2);
					
					
					if(verifier_code(Code2,verifier_code2)==0){
						printf("Mauvaise code!\n");
					}
					
				}while(verifier_code(Code2,verifier_code2)==0);
				
				
				
			// On affiche la flotte 
	    
	     printf("\n");
		 printf("**************** VOTRE FLOTTE ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",f_adversaire.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<f_adversaire.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", f_adversaire.t[i].numero, f_adversaire.t[i].type, f_adversaire.t[i].nb_cases_non_touchees,  type_navire[f_adversaire.t[i].type-1].nom);
		 }
			
				
            printf("Votre Grille\n");
            afficher_grille(g_adversaire);
        
        
         //On affiche la flotte de l'adversaire
         printf("\n");
		 printf("**************** FLOTTE DE L'ADVERSAIRE ****************\n");
		 printf("\n");
		 /* affichage du nombre de bateaux de la flotte */
		 printf("Nombre de bateaux : %d \n",f.nb_navires);

		 printf("\n");
		 /* pour chaque navire, affichage du numero, type, nb_cases_non_touchees, et du nom du bateau */
		 printf ("Numero\t Type\t Non touchees\t Nom\n");
		 for(i=0;i<f.nb_navires;i++){
		    printf("%d\t %d\t %d\t\t %s \n", f.t[i].numero, f.t[i].type, f.t[i].nb_cases_non_touchees,  type_navire[f.t[i].type-1].nom);
		 }	    
       
            
            printf("Grille de l'adversaire\n");
            afficher_adversaire_grille(g);
               
            printf("%s\n",Nom_du_joueur2); 
            arriere=afficher_menu_coup_et_lire_choix(g);
            effectuer_coup(arriere,&g,&f,type_navire);
            printf("Grille de l'adversaire\n");
            afficher_adversaire_grille(g);
             
            sleep(3);
            
           
              
			system("clear");
			
				
		}while(f.nb_navires!=f.nb_navires_coules && f_adversaire.nb_navires!=f_adversaire.nb_navires_coules);
		
		
		if(f.nb_navires==f.nb_navires_coules){
		printf("\n*********************\n");	
		printf("%s,Vous avez gagnez, Bravo!!!\n",Nom_du_joueur2);
		printf("*********************\n");	
	    }else{
		printf("\n*********************\n");
		printf("%s,Vous avez gagnez, Bravo!!!\n",Nom_du_joueur1);
		printf("*********************\n");	
		}
		
		free(g.t);
		free(f.t);
		free(g_adversaire.t);
		free(f_adversaire.t);			
		
		    
	
}



void mode_trois(GRILLE g,GRILLE g_adversaire,FLOTTE f,FLOTTE f_adversaire,TYPE_NAVIRE *type_navire,TYPE_NAVIRE *type_navire_adversaire){
	
	
	int i,choix_mode_position,num_navire,num_navire_adversaire;
    POSITION arriere,arriere_adversaire;
    char Nom_du_joueur1[100];
    int touche=0,direction,taille;
    
   /* pour chaque navire, initialisation du nombre de cases non touchees */
		
		 for(i=0;i<f.nb_navires;i++){
		    f.t[i].nb_cases_non_touchees=type_navire[f.t[i].type -1].taille;
		    num_navire=f.t[i].numero;
		 }

	     for(i=0;i<f_adversaire.nb_navires;i++){
		    f_adversaire.t[i].nb_cases_non_touchees=type_navire[f_adversaire.t[i].type -1].taille;
		    num_navire_adversaire=f_adversaire.t[i].numero;
		 }
		 
		printf("Entrez votre Prenom joueur numero 1: ");
		 scanf("%s",Nom_du_joueur1);
	
		
		system("clear");
		
		 
		do{
		
		printf("%s:CHOISISSEZ LE MODE DE POSITIONEMENT DES NAVIRE\n",Nom_du_joueur1);
		printf("Pour une saisi automatique:tapez 1\n");
		printf("Pour une saisi manuellement: tapez 2\n");
		
		positionner_flotte_intelligemment(g_adversaire,f_adversaire,type_navire_adversaire);
		
		vider_buffer_clavier();
		scanf("%d",&choix_mode_position); 
       
	    }while(choix_mode_position!=1 && choix_mode_position!=2);
	    
	    
	    
	    
	    if(choix_mode_position==1){
		
		positionner_flotte_intelligemment(g,f,type_navire);	
			
		}else{
		
		positionner_flotte_manuelement(g,f);	
		afficher_grille(g);	
		}
		
	    system("clear");
			
	
	
		
		
		do{
			
					
			printf("Votre Grille %s\n",Nom_du_joueur1);
			afficher_grille(g);
			printf("Grille de l'ordinateur\n");
            afficher_adversaire_grille(g_adversaire);
			printf("%s\n",Nom_du_joueur1);
			arriere_adversaire=afficher_menu_coup_et_lire_choix(g_adversaire);
			effectuer_coup(arriere_adversaire,&g_adversaire,&f_adversaire,type_navire_adversaire);
			touche=chercher_coup(g,&f,&arriere,touche,&direction,&taille);
			
            system("clear");
           
			
     
			
				
		}while(f.nb_navires!=f.nb_navires_coules && f_adversaire.nb_navires!=f_adversaire.nb_navires_coules);
		
		
		if(f.nb_navires==f.nb_navires_coules){
		printf("\n*********************\n");	
		printf("VOUS VOUS ETES FAIT BATTRE PAR L'ORDINATEUR!!!\n");
		printf("***VOUS AVEZ PERDU!!!***\n");
		printf("*********************\n");	
	    }else{
		printf("\n*********************************************\n");
		printf("%s,Vous avez gagner, Bravo!!!\n",Nom_du_joueur1);
		printf("********************************************\n");	
		}
		
		free(g.t);
		free(f.t);
		free(g_adversaire.t);
		free(f_adversaire.t);			
		
		    
	
}
