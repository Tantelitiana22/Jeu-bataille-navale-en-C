
#define NOM_MAX 20 
#define NOM_FICHIER_JEU "jeu.txt"
#define MAX_LENGTH_STRING 20

typedef char STRING[MAX_LENGTH_STRING];

typedef char NOM[NOM_MAX];


typedef struct{

  int numero,taille;
  NOM nom;

}TYPE_NAVIRE;

//Pour la dimension//
typedef struct{
int nbLigne;
int nbCol;	
}DIM;



typedef struct{
DIM dim;
int nbNavire;
int numType;
int NombreNumType;

}TYPE_NIVEAU;

//position du navire//

typedef struct{
int l,c;	
	
}POSITION;	


//structure de la grille//
typedef struct{

int ligne,col;

int *grille;

}GRILLE;


//structure du navire//
typedef struct{
int numero;
int type;
POSITION av,ar;
int casePasTouche;


}NAVIRE;


//structure de la fa flotte//
typedef struct{

int nbTotalNavire;
int nbNavireCoule;
NAVIRE *navire;
 
 }FLOTTE;


//Affichage des fichiers 
/*NOM *tableauNiveau(FILE *fichier,int *nb_niveaux);
void afficherNiveau(NOM *niveau,int nb_niveaux);
TYPE_NAVIRE *tailleNavire(FILE *fichier,int *nb_type);
void afficherNavire(TYPE_NAVIRE niveau[],int nb_type);

TYPE_NIVEAU *RecupNiveau(FILE *fich,DIM*dim); 
void AffiNiveau(FILE *fichier,TYPE_NIVEAU *niveau);
*/




int lecture_fichier_parametres(char*, STRING**,int*,TYPE_NAVIRE**,int*);
int lecture_fichier_parametres2(char*, STRING**,int*,TYPE_NAVIRE**,int*);
int lecture_fichier_niveau(char*,GRILLE*,FLOTTE*);



//gestion des grilles
GRILLE initialiseGrille(void);
int lire_navire_a(GRILLE *g,int c,int l);
int lire_etat_a(GRILLE *g,int c,int l);
void erire_etat_a(GRILLE *g,int c,int l,int new);



//gestion des actions utilisateur
int valider_position(GRILLE *g,POSITION arriere,int diretion,int taille);
