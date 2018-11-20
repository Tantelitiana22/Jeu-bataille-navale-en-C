#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"



/*****Fonction qui permet d'afficher la grille du joueur au mode 2 ou 3****/

void afficher_grille(GRILLE g){
	
	int i,j;
	int etat,navire;
	
	
	printf("\n  ");
	
	//Pour afficher le numero de colonne
	
		for(i=0;i<g.nbc;i++){
		
		
		printf("%3d",i+1);	
			
		}
		printf("\n  ");
  
		for(i=0;i<g.nbc;i++){
		
		
		printf("---");	
			
		}
		printf("\n");
	
	
	
	for(i=0;i<g.nbl;i++){
		
		
		printf("%c|",'A'+i);
		
		for(j=0;j<g.nbc;j++){
			
			
		etat=lire_etat_a(&g,i,j);
		navire=lire_navire_a(&g,i,j);
		
		
			if(navire==0){
				
					if(etat==0){
						
						printf(" ~~");//Pas de navire ni coup effectuer
					   
						
							
					}else{
					
					printf("  x");//coup a l'eau
						
					}
				
			}else if(etat==0){
						
					printf("%3d",g.t[i*g.nbc+j]);	//afficher le numero de navire
						
			}else if(etat==2){
				    
				    printf("  T"); //Afficher si c'est toucher
				     
			}else if(etat==3){
			
			printf("  C");	// Afficher couler si c'est coule
				
			}
			
		}
		
	   printf("\n");

    }
   

}





/******Fonction qui afficher la grille de l'adversaire sans montrer sa flotte*****/


void afficher_adversaire_grille(GRILLE g){


	int i,j;
	int etat,navire;
	
	
	printf("\n  ");
	
	//Pour afficher le numero de colonne
	
		for(i=0;i<g.nbc;i++){
		
		
		printf("%3d",i+1);	
			
		}
		printf("\n  ");
  
		for(i=0;i<g.nbc;i++){
		
		
		printf("---");	
			
		}
		printf("\n");
	
	
	
	for(i=0;i<g.nbl;i++){
		
		
		printf("%c|",'A'+i);
		
		for(j=0;j<g.nbc;j++){
			
			
		etat=lire_etat_a(&g,i,j);
		navire=lire_navire_a(&g,i,j);
		
		
			if(navire==0){
				
					if(etat==0){
						
						printf(" ~~");//Pas de navire ni coup effectuer
					   
						
							
					}else{
					
					printf("  x");//coup a l'eau
						
					}
				
			}else if(etat==0){
						
				        printf(" ~~");  	//afficher des vagues au lieux d'afficher des navires
						
			}else if(etat==2){
				    
				    printf("  T"); //Afficher si c'est toucher
				     
			}else if(etat==3){
			
			printf("  C");	// Afficher couler si c'est coule
				
			}
			
		}
		
	   printf("\n");

    }

	
	
	
	
    
 }  



