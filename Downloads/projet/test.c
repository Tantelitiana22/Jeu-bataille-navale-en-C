#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"
#include<unistd.h>

int main(void){

 int choix,nb_niveau,nb_type,nb_type_adversaire,temp,nb_navires,nb_navire_adversaire,i,mode,num_navire,touche=0,taille,direction;
    POSITION arriere;
    FLOTTE f,f_adversaire;
    GRILLE g,g_adversaire;
    
    // declaration du tableau de STRING de fichier de niveau (taille encore inconnue)
    STRING *niveau=NULL;

    // declaration du tableau de types de navire (taille encore inconnue)
    TYPE_NAVIRE *type_navire=NULL;
    TYPE_NAVIRE *type_navire_adversaire=NULL;
     
     
      //Pour recuperer le nombre de niveau, et les types qu navire anisi que le nombre de type
                //On le fait deux pour le type de l'adversaire et du joueur
	lecture_fichier_parametres(NOM_FICHIER_JEU,&niveau,&nb_niveau,&type_navire,&nb_type);
	lecture_fichier_parametres(NOM_FICHIER_JEU,&niveau,&nb_niveau,&type_navire_adversaire,&nb_type_adversaire);
 
        	system("clear");
     printf("\n*****************************************************\n");
     printf("*******BIENVENUE DANS LE JEU BATAILLE NAVALE*********\n");
     printf("*****************************************************\n");        
              
     do{
		 
	
		 
                //On demande le mode de jeu
                 mode=affiche_menu_mode_et_lire_choix(); 
                 
                 if(mode==0){
				 
				 printf("Au revoir!\n");
				 
				 exit(1);
			 }       
                
               
				
				
				choix=affiche_menu_niveau_et_lire_choix(nb_niveau);
				
				system("clear"); 
				
			    //On recupere la grille et la flotte de chaque joueur
				lecture_fichier_niveau(niveau[choix-1],&g,&f);//pour initialiser les grilles et la flotte à partir du fihier niveau. 
				lecture_fichier_niveau(niveau[choix-1],&g_adversaire,&f_adversaire);//pour initialiser la grille de l'adversaire
				
				
			    switch(mode){
			   
				case 1:
			
			    mode_un(g,f,type_navire); 
		   
			    break;
		   
			    case 2:
					 
			    mode_deux(g,g_adversaire,f,f_adversaire,type_navire,type_navire_adversaire);
						
			    break; 
					 
				case 3:
				//A faire avec l'intelligence artificiel
				
				for(i=0;i<f.nb_navires;i++){
		        f.t[i].nb_cases_non_touchees=type_navire[f.t[i].type -1].taille;
		        num_navire=f.t[i].numero;
		        }
				
				positionner_flotte_intelligemment(g,f,type_navire);
				
				i=0;
				
				do{
					
				afficher_grille(g);
				printf("%d\n",i);
				sleep(2);
				
				//taille=type_navire[f.t[i].type -1].taille;
		         //num_navire=f.t[i].numero;

				touche=chercher_coup(g,&f,&arriere,touche,&direction,&taille);
				
				i++;
		       	}while(f.nb_navires!=f.nb_navires_coules);
		       	
		       	afficher_adversaire_grille(g);
		       	free(g.t);
		       	printf("\n fin \n");	 
					 
				 break;
				 
				default :
				          printf("Au revoir!");	
				// mode_trois(g,g_adversaire,f,f_adversaire,type_navire,type_navire_adversaire);
					   
				 } 
             
             
             
         
		}while(mode!=0);
            
        
 return 0;
}
