#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"projet.h"





///******Gestion des actions utilisateur****///

/***Fonction qui permet de voir si la position donner d'un navire est bonne ou pas ***/
/*** ie, il n'y a pas de navire qui sort de la grille ni des navires qui se coupent****/
/***Chaque navire qoit etre separer d'une case que ca soit en diagonale en ligne ou en colonne***/

int valider_position(GRILLE *g,POSITION arriere,int direction,int taille){
	
	int i0,i1,j0,j1;
	int i,j;


	if(arriere.l<0 || arriere.l>=g->nbl || arriere.c<0 || arriere.c>=g->nbc){
         
	return 0;
	}	
	
	switch(direction){
		
		 case 0://a droite
				if(arriere.c+taille-1>=g->nbc){
                                  
					return 0;
				}
				 
				i0=arriere.l-1;
				i1=arriere.l+1;
				j0=arriere.c-1;
				j1=arriere.c+taille;
		
	
	          
                        break;
	
	        case 1://vers le bas
	          if(arriere.l+taille-1>=g->nbl){
                      
				return 0;
		      }
		      i0=arriere.l-1;
			  i1=arriere.l+taille;
			  j0=arriere.c-1;
			  j1=arriere.c+1;
			  
                         
			  break;
			  
	   case 2://vers la gauche		  
             if(arriere.c+1<taille){
                     
			 return 0;
		     }
		     i0=arriere.l-1;
		     i1=arriere.l+1;
		     j0=arriere.c-taille;
		     j1=arriere.c+1;
		     
		     break;
		     
	   case 3://vers le haut
				if(arriere.l+1<taille){
			
				return 0;	
				}
		        i0=arriere.l-taille;
		        i1=arriere.l+1;
		        j0=arriere.c-1;
		        j1=arriere.c+1;
		     
		     break;
     }	

         
     
     i0=(i0<0)? 0:i0;
     i1=(i1>=g->nbl)? g->nbl-1:i1;
     j0=(j0<0)? 0:j0;
     j1=(j1>=g->nbc)? g->nbc-1:j1;
   
   
     for(i=i0;i<=i1;i++){
		 for(j=j0;j<=j1;j++){
		   if(lire_navire_a(g,i,j)!=0){
			   
                
                     return 0;
		   }
		    
		 }
	 }
	 
     
	 return 1;
		     	     
}


/**********Fonction qui enregistre la position valide et qui initialise  la grille a remplire********/

POSITION enregistrer_position( GRILLE *g,FLOTTE *f,POSITION arriere,int num_navire,int direction,int taille){
	int i;
	
	f->t[num_navire-1].arriere=arriere;
	f->t[num_navire-1].direction=direction;
	
    switch(direction){
    			
					case 0://DIRECTION VERS LA DROITE	
            			    
    						//f->t[num_navire-1].avant.l=arriere.l;
    						//f->t[num_navire-1].avant.c=arriere.c+taille-1;
    						
    						
    						for(i=0;i<taille;i++){
								g->t[arriere.l*g->nbc+arriere.c+i]=num_navire;
							}
                                    
                          break;
        			case 1://DIRECTION VERS LE BAS
	                       
	                       //f->t[num_navire-1].avant.l=arriere.l+taille-1;
    					   //f->t[num_navire-1].avant.c=arriere.c;
    						
						  	for(i=arriere.l;i<=arriere.l+taille-1;i++)
		                            g->t[i*g->nbc+arriere.c]=num_navire;
 						  break;
                    case 2://DIRECTION VERS LA GAUCHE
                    
                    
						   //f->t[num_navire-1].avant.l=arriere.l;
    					   //f->t[num_navire-1].avant.c=arriere.c-taille+1;
    						    						
                          for(i=arriere.c-taille+1;i<=arriere.c;i++)
                                    g->t[g->nbc*arriere.l+i]=num_navire;
                           
                          break;
                   case 3://DIRECTION VERS LE HAUT
                          //f->t[num_navire-1].avant.l=arriere.l-taille+1;
    					  //f->t[num_navire-1].avant.c=arriere.c;
    					  
                          for(i=arriere.l-taille+1;i<=arriere.l;i++)
                                    g->t[i*g->nbc+arriere.c]=num_navire;
                     
                          break;
                    
                     }			

            return arriere;

   }
   
   

   
   /****ON verifie si un coup est dans la grille ou hors de la grille****/
   
  int valider_coup(POSITION arriere,GRILLE g){
	  
	  if(arriere.l<0 || arriere.l>= g.nbl || arriere.c>=g.nbc || arriere.c<0){
		  
		  return 0;
	  }
	  
	 return 1; 
	  
	} 
	
	
	
	/****On ecrit le coup qui est valide dans la grille****/
	/****Si il n'y a pas de bateau on met le coup à l'eau ***/
	/****Si le bateau n'etait jamais toucher on met Toucher**/
	/****Si tout le bateau est toucher on Met couler****/
	
 int effectuer_coup(POSITION entrer,GRILLE *g,FLOTTE *f, TYPE_NAVIRE *type){
	 
	 int i,j,taille,num_navire;
	 int direction;
	 POSITION arriere;
	 
	 if(valider_coup(entrer,*g)==0){
		 
		 return 0;
		 
	 } //on verifi si le coup est valide et on retourne 0 si il ne l'est pas
	 
	if((num_navire=lire_navire_a(g,entrer.l,entrer.c))==0){//Si il n'y a pas de navire dans la case on ecrit 1 pour a l'eau
		
		ecrire_etat_a(g,entrer.l,entrer.c,1);
		
	return 1; 
	
	//sinon il y a un bateau
	
	 }else{   
		 
			taille=type[f->t[num_navire-1].type-1].taille;

            //Si le navire est intacte On ecrit 2 pour toucher et on decremente le nombre de case toucher 
            
			if(lire_etat_a(g,entrer.l,entrer.c)==0){   

				ecrire_etat_a(g,entrer.l,entrer.c,2);
				f->t[num_navire-1].nb_cases_non_touchees--;
                
               //Si toute les cases sont touchés on incremente le nombre de navire coules et on recupere la position et la direction 
               
				if(f->t[num_navire-1].nb_cases_non_touchees==0){
					f->nb_navires_coules++;
					direction=f->t[num_navire-1].direction;
					arriere=f->t[num_navire-1].arriere;
				
				//On passe au different cas possible de la direction du navire	
					
					switch(direction){
					case 0://direction vers le droite		

							
							for(i=arriere.c;i<arriere.c+taille;i++){
							   
								ecrire_etat_a(g,arriere.l,i,3);
						   
							}
			 
						 
							
					break;
						
					case 1 ://direction vers le bas
					   
					  
						
							for(i=arriere.l;i<taille+arriere.l;i++){	
								ecrire_etat_a(g,i,arriere.c,3);
							 
							} 
							
																			
					
					break;
						
					case 2 ://direction vers la gauche		   
							   
							
							
								for(i=arriere.c-taille+1;i<=arriere.c;i++){
									 ecrire_etat_a(g,arriere.l,i,3);
									 
								}
								
					break;	
					case 3 ://direction vers le haut
					 
							
								
								for(i=arriere.l-taille+1;i<=arriere.l;i++){
								
								ecrire_etat_a(g,i,arriere.c,3);
								
								}	
								
							
										 
					break;	   
					
					
				}




				return 3;


									
			}								   
		 
		 
		 
			return 2;
		 
		}  
				
					 
	}		
		
}
