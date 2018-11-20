#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"


/*****Fonction qui permet d'ecrire dans les 8 premiers bits d'une case de la grille***/
/*****On prend que 2^8 dans la base 2****/
int lire_navire_a(GRILLE *g,int l,int c){
	
	return g->t[l*g->nbc+c]%256;	
}

/****Fonction qui permet de lire les bits 8 et 9*****/

int lire_etat_a(GRILLE *g,int l,int c){

 return g->t[l*g->nbc+c]/256;	

}

/****Fonction qui permet d'ecrire l'etat d'un bateau, si il est a l'eau toucher ou couler****/

void ecrire_etat_a(GRILLE *g,int l,int c,int new){
	
	
	int temp;
	 temp=g->t[l*g->nbc+c]%256;
     g->t[l*g->nbc+c]=new*256+temp;

}



int affiche_menu_niveau_et_lire_choix(int nb_niveaux){
	
        int choix,i;
        
	do{
       
        /* affichage du tableau niveau */
		 printf("\n");
		 printf("\n**************** CHOISISSEZ UN NIVEAU*****************\n");
		 printf(" choisissez un niveau entre 1 et %d\n",nb_niveaux);
		 printf("Votre choix:");
	     scanf("%d",&choix);

	}while(choix>nb_niveaux || choix<0 );
	
	//On attribu la valeur du fichier du choix voul

return choix;

}


/****Afficher menu mode permet de savoir si on veut jouer tout seul******/
 /***              a deux ou contre l'ordinateur                   ******/

int affiche_menu_mode_et_lire_choix(void){

	int choix;

	do{

	printf("Choisissez un mode de jeu parmi: les propositions suivantes:\n");
	puts("taper 1 pour jouer seul");
	puts("taper 2 pour jouer a 2 joueur");
	puts("taper 3 pour jouer contre l'ordinateur");
        puts("tapez 0 pour quiter le programme");
        printf("Votre choix:");
	scanf("%d",&choix);

	}while(choix!=1 && choix!=2 && choix!=3 &&choix!=0 );

return choix;

}

/******Fonction qui permet de demander le coup qu'on veut faire et de l'ecrir sur le clavier***/

POSITION afficher_menu_coup_et_lire_choix(GRILLE g){
	
	POSITION position;
	int col,lin;
	char ligne;
	
	
	do{
	printf("Entrez un coup de la forme A3 par exemple\n");
	printf("Un lettre en majuscule entre A et %c et un chiffre compris entre 1 et %d\n",'A'+g.nbl-1,g.nbc);
	printf("votre coup: ");
	vider_buffer_clavier();
	do{
	scanf("%c",&ligne);
     }while(ligne<'A' && ligne>'Z');
     
	scanf("%d",&col);
	
	 lin=ligne-'A';
	 col--;
    }while(lin>g.nbl-1|| col>g.nbc-1|| lin<0 || col<0);
    
    
    position.l=lin;
    position.c=col;
    
    return position;

}

 /*** POSITIONNER LES FLOTTES PAR LE JOUEUR****/
   
   void positionner_flotte_manuelement(GRILLE g,FLOTTE f){
	   
	   int j,k;
    int i,num_navire,taille,direction,nb_navire,nb_niveau,nb_type;
    STRING *niveau=NULL;
    TYPE_NAVIRE *type_navire=NULL;
	POSITION arriere;
	   
	   lecture_fichier_parametres(NOM_FICHIER_JEU, &niveau,&nb_niveau,&type_navire,&nb_type);
	   
	   
	    /* pour chaque navire, initialisation du nombre de cases non touchees */
		 for(i=0;i<f.nb_navires;i++){
		    f.t[i].nb_cases_non_touchees=type_navire[f.t[i].type -1].taille;
		 }

	   
	   
	for(i=0;i<f.nb_navires;i++){
		        
		     system("clear");
	        // on affiche la grille apres chaque initialisation	
            afficher_grille(g);
            
            
            
            
				//AFFIHER D'ABORD AVANT DE METTRE LES NAVIRES*////
		
		    printf ("Numero\t Type\t Taille\t\t Nom\n");
		    printf("%d\t %d\t %d\t\t %s \n", f.t[i].numero, f.t[i].type, f.t[i].nb_cases_non_touchees,  type_navire[f.t[i].type-1].nom);
		       
		    taille=type_navire[f.t[i].type -1].taille;
		    num_navire=f.t[i].numero;

			
			do{
				
		   	     int col,lin;
		   	
	             char ligne;
	
	
	            do{
	
	                printf("Entrer la position en queue du navire %s: ",type_navire[f.t[i].type-1].nom);
	   
	                  /**ON ENTRE LA POSITION**/
	 
			        vider_buffer_clavier();
		            scanf("%c",&ligne);
		            scanf("%d",&col);
		            
		            
		            lin=ligne-'A';
		            
		             col--;
		 
		 
	     
	                      //On verifie si on ne sort pas du grille
                }while(lin>g.nbl-1|| col>g.nbc-1|| lin<0 || col<0);
         
                arriere.l=lin;
                arriere.c=col;
            
         //continuer a la maison (transmition par valeur
		
		 
		          printf("\n");
    
                do{
				
				
				
				     printf("Entrer une direction:\n");
				     puts("Droit:0");
				     puts("Bas:1 ");
				     puts("Gauche:2");
				     puts("Haut:3");
				     scanf("%d",&direction);
				
				    if(direction>3 || direction<0){
					
					printf("Entrer une direction donnée dans la consigne\n");
				    }
				
				//On verifie si la direction est bien entre 0 et 3
			    }while(direction>3 || direction<0);
			
			    if(valider_position(&g,arriere,direction,taille)==0){
			    printf("Position invalide ou direction invalide,a refaire!\n"); 
					   
				}
				
		   
		        printf("val %d\n",valider_position(&g,arriere,direction,taille));
		        
		   //On verifie si le coup est valide
		}while(valider_position(&g,arriere,direction,taille)==0);
		
			
			
		enregistrer_position( &g, &f,arriere,num_navire,direction,taille);
			
			
    
    }   
	   afficher_grille(g);  	   
	   
 }
 
  

/***On positionne la flotte automatiquement mais pas a la main avec cette fonction***/			
				
  int positionner_flotte_intelligemment(GRILLE g,FLOTTE f, TYPE_NAVIRE* type_navire){
		
	int direction,num_navire,i=0,taille,nb_niveau,nb_type,j,nb_tentative=0;
	int nb_ligne,nb_colonne;
	POSITION arriere;
    	
					
			
		
		while(i<f.nb_navires){
			
			taille=type_navire[f.t[i].type -1].taille;
			num_navire=f.t[i].numero;
			
			srand(time(NULL));
			do{
				
			nb_ligne=rand()%g.nbl;
			nb_colonne=rand()%g.nbc;
			direction=rand()%4;
			
			arriere.l=nb_ligne;
			arriere.c=nb_colonne;
			
			
		    if(nb_tentative==N_MAX){
			return EXIT_FAILURE;
	     	}
			
			nb_tentative++;
			
	    	}while(valider_position(&g,arriere,direction,taille)==0 );

		    enregistrer_position(&g,&f,arriere,num_navire,direction,taille);	
					
			i++;
			
		}
			
	   return EXIT_SUCCESS;
    }			
	 
	 
	 
	 
	 
	 /*****Pour vider le buffer creer par la touche entre***********/

 void vider_buffer_clavier(void){
	 char c;
	 do{
		 scanf("%c",&c);
		 
	 }while(c!='\n' && c!=EOF);
	 
	 
 }
 
 

 
/*****Par tres important mais qui permet d'ajouter plus securite pour les deux joueur au niveau 2***/
/*****On verifie si le code entrer par le joueur est bon pou que l'aure ne puis pas voir sa flotte***/

int verifier_code(char Mon_code[],char Code_a_verifier[]){
	int i;

    for(i=0;i<10 && Mon_code[i]!=EOF;i++){
	
		if(Mon_code[i]!=Code_a_verifier[i]){
		return 0;	
		}
		
	    return 1;	
		
	}
	
		
}




int verificateur_carre(GRILLE g,int l,int c){ //si il y a un navire coule a cote de la case,on n'ecrit pas sur cette case,On optimise les coups

int i0,i1,j0,j1,i,j;

	i0=l-1;
	i1=l+1;
	j0=c-1;
	j1=c+1;
	
	i0=(i0<0)? 0:i0;
    i1=(i1>=g.nbl)? g.nbl-1:i1;
    j0=(j0<0)? 0:j0;
    j1=(j1>=g.nbc)? g.nbc-1:j1;
    
    
    for(i=i0;i<=i1;i++){
		 for(j=j0;j<=j1;j++){
		   if(lire_etat_a(&g,i,j)==3){
			   
                  return 0;
		   }
		    
		 }
	 }
	 
	 
	 
	 

	return 1;	
	
}	

int impossible_navire(GRILLE g,int l, int c){
	
	int somme=0;
	
	int i0,i1,j0,j1,i,j;

	i0=l-1;
	i1=l+1;
	j0=c-1;
	j1=c+1;
	
	i0=(i0<0)? 0:i0;
    i1=(i1>=g.nbl)? g.nbl-1:i1;
    j0=(j0<0)? 0:j0;
    j1=(j1>=g.nbc)? g.nbc-1:j1;
    
	somme=lire_etat_a(&g,l,j0)+lire_etat_a(&g,l,j1)+lire_etat_a(&g,i0,c)+lire_etat_a(&g,i1,c);
	 
	 if(somme==4){
		 return 0;
	 }else if((i0==0||j0==0 || i1==g.nbl-1 ||j1==g.nbc-1) && somme==3){
		 
		 return 0;
	 }
	 return 1;
	
}
	



//On va retourner touche

int chercher_coup(GRILLE g, FLOTTE *f,POSITION *arriere,int touche,int *direction,int *taille){
	
	
	int l,c,i,verifie ; 
	int num_navire;
	
	if(touche==0){
		
		do{
			l=rand()%(g.nbl);
			c=rand()%(g.nbc);
		}while(lire_etat_a(&g,l,c)!=0 );
		
		
		    if(verificateur_carre(g,l,c)==1){
			 arriere->l=l;
			 arriere->c=c;
		    }else{
				
			touche=0;
			return touche;	
				
			}
			
			if(impossible_navire(g,l,c)==0){
				touche=0;
			return touche;
				
			}
			
			
			
	    if((num_navire=lire_navire_a(&g,arriere->l,arriere->c))==0){
			
			ecrire_etat_a(&g,arriere->l,arriere->c,1);
			
			touche=0;
			return touche;
			
		}else{
			        *taille=f->t[num_navire-1].nb_cases_non_touchees;
			        
					if(lire_etat_a(&g,arriere->l,arriere->c)==0){
                  
                    ecrire_etat_a(&g,arriere->l,arriere->c,2);
                   
                    f->t[num_navire-1].nb_cases_non_touchees--;
                      
					touche=1;
					return touche;	
						
					}else{
					
					touche=0;
					return touche;	
						
					}	
			
			
		}
	     
	     
	}else if(touche==1){
		
		if(arriere->l+1<g.nbl && lire_etat_a(&g,arriere->l+1,arriere->c)==0){
			
			
			if((num_navire=lire_navire_a(&g,arriere->l+1,arriere->c))==0){
				   
				    
				    if(verificateur_carre(g,arriere->l+1,arriere->c)==0){
				    
						if(lire_etat_a(&g,arriere->l,arriere->c+1)==0){
						
						ecrire_etat_a(&g,arriere->l,arriere->c+1,1);
						*direction=0;
						touche=2;
						}else{
						ecrire_etat_a(&g,arriere->l,arriere->c-1,2);
						*direction=0;
						arriere->c=arriere->c-1;
						touche=2;	
							
						}
				    
				    }else{
				    
					    ecrire_etat_a(&g,arriere->l+1,arriere->c,1);	
						touche=1;
					}
					
					    return touche;	
						
			
		    }else{
			
			ecrire_etat_a(&g,arriere->l+1,arriere->c,2);
			
			arriere->l=arriere->l+1;
			*direction=1; //Vers le bas
			
			
			f->t[num_navire-1].nb_cases_non_touchees--;
			touche=2;
				
			            if(f->t[num_navire-1].nb_cases_non_touchees==0){
									 for(i=arriere->l-*taille+1;i<=arriere->l;i++){
								
								         ecrire_etat_a(&g,i,arriere->c,3);
								
							            }
							f->nb_navires_coules++;
							         
							touche=0;
				    
							
						}
				return touche;
				
			}	
			
		}else if(arriere->l-1>=0 && lire_etat_a(&g,arriere->l-1,arriere->c)==0){
			
			
			if((num_navire=lire_navire_a(&g,arriere->l-1,arriere->c))==0){
			
				if(verificateur_carre(g,arriere->l-1,arriere->c)==0){
				    
				    if(lire_etat_a(&g,arriere->l,arriere->c-1)==0){
					
					ecrire_etat_a(&g,arriere->l,arriere->c-1,1);
					*direction=0;
					touche=2;
				    }else{
					ecrire_etat_a(&g,arriere->l,arriere->c+1,2);
					*direction=0;
					arriere->c=arriere->c+1;
					touche=2;	
						
					}
				
			    }else{
					ecrire_etat_a(&g,arriere->l-1,arriere->c,1);	
					touche=1;	
				}
				
				return touche;
			
		    }else{
			
			ecrire_etat_a(&g,arriere->l-1,arriere->c,2);
			
			f->t[num_navire-1].nb_cases_non_touchees--;
		
			arriere->l=arriere->l-1;
		    *direction=3; //vers le haut
			touche=2;
		    
			
		    }
		
		           
		
		
			            if(f->t[num_navire-1].nb_cases_non_touchees==0){
									 for(i=arriere->l;i<=arriere->l+*taille-1;i++){
										
											  ecrire_etat_a(&g,i,arriere->c,3);
											}
							f->nb_navires_coules++;   
							touche=0;
							
						}
			
			
			return touche;		     
		
		
	    }else if(arriere->c+1<g.nbc && lire_etat_a(&g,arriere->l,arriere->c+1)==0){
			
			
			if((num_navire=lire_navire_a(&g,arriere->l,arriere->c+1))==0){
			
				ecrire_etat_a(&g,arriere->l,arriere->c+1,1);
				touche=1;	
					
					return touche;
			
		    }else{
			ecrire_etat_a(&g,arriere->l,arriere->c+1,2);
			f->t[num_navire-1].nb_cases_non_touchees--;
			arriere->c=arriere->c+1;
			*direction=0;//vers la droite
			touche=2;
				
				
			}
			      
					if(f->t[num_navire-1].nb_cases_non_touchees==0){
									 for(i=arriere->c-*taille+1;i<=arriere->c;i++){
											  ecrire_etat_a(&g,arriere->l,i,3);
									 }
									 
					         f->nb_navires_coules++;				 
									 
							touche=0;
				   
						}	
			return touche;		
	
	    }else  if(arriere->c-1>=0 && lire_etat_a(&g,arriere->l,arriere->c-1)==0){
			
			
			if((num_navire=lire_navire_a(&g,arriere->l,arriere->c-1))==0){
										
				     ecrire_etat_a(&g,arriere->l,arriere->c-1,1);
					touche=1;
					return touche;
			
		    }else{
			
			ecrire_etat_a(&g,arriere->l,arriere->c-1,2);
			f->t[num_navire-1].nb_cases_non_touchees--;
			arriere->c=arriere->c-1;
			*direction=2;//vers la droite
			touche=2;
				
			}
			
				if(f->t[num_navire-1].nb_cases_non_touchees==0){
									 for(i=arriere->c;i<=arriere->c+*taille-1;i++){
										
											  ecrire_etat_a(&g,arriere->l,i,3);
									 }
									 
					         f->nb_navires_coules++;				 
									 
							touche=0;
				   
						}	
			
			
			return touche;
					 
	   }
	    
	    
    }else if(touche==2){
		
		switch(*direction){
					
			case 0: //droite
			
			    if(arriere->c+1<g.nbc && lire_etat_a(&g,arriere->l,arriere->c+1)==0){
						
					if((num_navire=lire_navire_a(&g,arriere->l,arriere->c+1))==0){
						
						    if(verificateur_carre(g,arriere->l,arriere->c)==0){
								 
								 *direction=2;
							
							    do{
								  arriere->c=arriere->c-1;
								  
								}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
	
								ecrire_etat_a(&g,arriere->l,arriere->c,2);
									
								 f->t[num_navire-1].nb_cases_non_touchees--;
								  touche=2;
								
							    if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
								for(i=arriere->c-*taille+1;i<=arriere->c;i++){
										
									ecrire_etat_a(&g,arriere->l,i,3);
							    }
									 
					                f->nb_navires_coules++;				 
									 
							        touche=0;
				   
						            }	
								
								 
								
									
						    }else{
							
							    ecrire_etat_a(&g,arriere->l,arriere->c+1,1);
							
							     *direction=2;
							
							    do{
								  arriere->c=arriere->c-1;
								  
								 }while(lire_etat_a(&g,arriere->l,arriere->c)==2);
								 
								arriere->c=arriere->c+1;
								 touche=2;	
							
						    }
						return touche;
						
					}else{
					
						arriere->c=arriere->c+1;
						ecrire_etat_a(&g,arriere->l,arriere->c,2);	
					    f->t[num_navire-1].nb_cases_non_touchees--;
					    *direction=0;
					     touche=2;
					     
							if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									 for(i=arriere->c-*taille+1;i<=arriere->c;i++){
										
											  ecrire_etat_a(&g,arriere->l,i,3);
									 }
									 
					         f->nb_navires_coules++;				 
									 
							touche=0;
				   
						    }
						    
						return touche;    
						    		
						
					}
					
				}else{	
						
						*direction=2;
						  do{
							  arriere->c=arriere->c-1;
							  
							}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
							arriere->c=arriere->c+1;
							
						return touche=2;
					
						}	
				
				break;
				
				
			case 1:
			
			    if(arriere->l+1<g.nbl && lire_etat_a(&g,arriere->l+1,arriere->c)==0){
						
					if((num_navire=lire_navire_a(&g,arriere->l+1,arriere->c))==0){
						
						
						    if(verificateur_carre(g,arriere->l+1,arriere->c)==0){
						
								*direction=3;
								
								  do{
									  arriere->l=arriere->l-1;
									  
									}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
									ecrire_etat_a(&g,arriere->l,arriere->c,2);
								     f->t[num_navire-1].nb_cases_non_touchees--;
								     touche=2;
								
									if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									 for(i=arriere->l-*taille+1;i<=arriere->l;i++){
										
											  ecrire_etat_a(&g,i,arriere->c,3);
									 }
									 
					                    f->nb_navires_coules++;				 
									 
							            touche=0;
		          		   
						            }
								
							}else{	
								
								ecrire_etat_a(&g,arriere->l+1,arriere->c,1);
							
								*direction=3;
								
								  do{
									  arriere->l=arriere->l-1;
									  
									}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
										arriere->l=arriere->l+1;
								touche=2;	
								
							}
									
								return touche;
								
						
					}else{
					
						arriere->l=arriere->l+1;
						ecrire_etat_a(&g,arriere->l,arriere->c,2);	
					    f->t[num_navire-1].nb_cases_non_touchees--;
					    *direction=1;
					     touche=2;
					     
							if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									 for(i=arriere->l-*taille+1;i<=arriere->l;i++){
										
											  ecrire_etat_a(&g,i,arriere->c,3);
									 }
									 
					         f->nb_navires_coules++;				 
									 
							touche=0;
				   
						    }
						    
						
						return touche;    
						    		
						
					}
					
				}else{	
						
						*direction=3;
						  do{
							  arriere->l=arriere->l-1;
							  
							}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
							arriere->l=arriere->l+1;
							
						return touche=2;
					
						}	
				
				break;
			
			case 2:
					
			    if(arriere->c-1>=0 && lire_etat_a(&g,arriere->l,arriere->c-1)==0){
						
					if((num_navire=lire_navire_a(&g,arriere->l,arriere->c-1))==0){
						
						    if(verificateur_carre(g,arriere->l,arriere->c-1)==0){
								*direction=0;
								
								  do{
									  arriere->c=arriere->c+1;
									  
									}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
									
									ecrire_etat_a(&g,arriere->l,arriere->c,2);
									f->t[num_navire-1].nb_cases_non_touchees--;
								    touche=2;
								    
								    if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									    for(i=arriere->c;i<=arriere->c+*taille-1;i++){
										
											  ecrire_etat_a(&g,arriere->l,i,3);
									    }
									 
					                    f->nb_navires_coules++;				 
									 
							            touche=0;
				   
						            }   
								    	
							}else{
							
								ecrire_etat_a(&g,arriere->l,arriere->c-1,1);
								*direction=0;
								
								  do{
									  arriere->c=arriere->c+1;
									  
									}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
									arriere->c=arriere->c-1;
								touche=2;	
								
							}	
									
								return touche;
						
					}else{
					
						arriere->c=arriere->c-1;
						ecrire_etat_a(&g,arriere->l,arriere->c,2);
						
					    f->t[num_navire-1].nb_cases_non_touchees--;
					    *direction=2;
					     touche=2;
					        
					      
							if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									 for(i=arriere->c;i<=arriere->c+*taille-1;i++){
										
											  ecrire_etat_a(&g,arriere->l,i,3);
									 }
									 
					         f->nb_navires_coules++;				 
									 
							touche=0;
				   
						    }
						    
						return touche;    
						    		
						
					}
					
				}else{	
						
						*direction=0;
						  do{
							  arriere->c=arriere->c+1;
							  
							}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
							arriere->c=arriere->c-1;
							
						return touche=2;
					
						}	
				
				break;
			
			case 3:
					
			    if(arriere->l-1>=0 && lire_etat_a(&g,arriere->l-1,arriere->c)==0){
						
					if((num_navire=lire_navire_a(&g,arriere->l-1,arriere->c))==0){
						
							if(verificateur_carre(g,arriere->l-1,arriere->c)==0){
								
								*direction=1;
								
								do{
								 arriere->l=arriere->l+1;
									  
								}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
								
								
								
									ecrire_etat_a(&g,arriere->l,arriere->c,2);
									f->t[num_navire-1].nb_cases_non_touchees--;
								     touche=2;
									if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									      for(i=arriere->l;i<=arriere->l+*taille-1;i++){
										
											  ecrire_etat_a(&g,i,arriere->c,3);
											 
									        }
									 
					                    f->nb_navires_coules++;				 
								 	 
							            touche=0;
				    
						            }		
											
									
						    }else{
								
								ecrire_etat_a(&g,arriere->l-1,arriere->c,1);
								
								*direction=1;
								
								  do{
									  arriere->l=arriere->l+1;
									  
									}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
									
									arriere->l=arriere->l-1;
							}
							
						return touche;
						
					}else{
					
						arriere->l=arriere->l-1;
						ecrire_etat_a(&g,arriere->l,arriere->c,2);	
					    f->t[num_navire-1].nb_cases_non_touchees--;
					     touche=2;
					     *direction=3;
					     
							if(f->t[num_navire-1].nb_cases_non_touchees==0){
								
									 for(i=arriere->l;i<=arriere->l+*taille-1;i++){
										
											  ecrire_etat_a(&g,i,arriere->c,3);
											 
									 }
									 
					         f->nb_navires_coules++;				 
								 	 
							touche=0;
				   
						    }
						    
						return touche;    
						    		
						
					}
					
				}else{	
						
						*direction=1;
						  do{
							  arriere->l=arriere->l+1;
							  
							}while(lire_etat_a(&g,arriere->l,arriere->c)==2);
							arriere->l=arriere->l-1;
							
						return touche=2;
					
					}	
				
				break;
				
		}		
				
	} 	
		
}	
