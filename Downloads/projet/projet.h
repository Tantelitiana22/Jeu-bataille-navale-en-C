#define NOM_FICHIER_JEU "jeu.txt"
#define MAX_LENGTH_STRING 20
#define N_MAX 100000


typedef char STRING[MAX_LENGTH_STRING];

typedef struct{
   int l,c;
}POSITION;

typedef struct{
   int numero,taille;
   STRING nom;
}TYPE_NAVIRE;

typedef struct{
   int nbl,nbc;
   int *t;
}GRILLE;

typedef struct{
   int numero,type,nb_cases_non_touchees,direction;
   POSITION arriere;
   
}NAVIRE;

typedef struct{
   int nb_navires, nb_navires_coules;
   NAVIRE *t;
}FLOTTE;

/*******Lecture des fichiers et initialisation de la grille******/

int lecture_fichier_parametres(char*, STRING**,int*,TYPE_NAVIRE**,int*);
int lecture_fichier_niveau(char*,GRILLE*,FLOTTE*);


/***affiche les menus niveau mode coup et lire choix***/
int affiche_menu_niveau_et_lire_choix(int);
int affiche_menu_mode_et_lire_choix(void);
POSITION afficher_menu_coup_et_lire_choix(GRILLE );


/***Fonction de gestion des grilles*****/

int lire_navire_a(GRILLE *,int,int );
int lire_etat_a(GRILLE *,int,int);
void ecrire_etat_a(GRILLE *,int ,int ,int );


/***Gestion des actions utilisateur***/

int valider_position(GRILLE *,POSITION ,int ,int );
POSITION enregistrer_position( GRILLE *,FLOTTE *,POSITION ,int ,int ,int );
int valider_coup(POSITION ,GRILLE );
int effectuer_coup(POSITION ,GRILLE *,FLOTTE *,TYPE_NAVIRE *);

/***Positionnement de navire***/
void positionner_flotte_manuelement(GRILLE ,FLOTTE );
 int positionner_flotte_intelligemment(GRILLE ,FLOTTE ,TYPE_NAVIRE*);


void vider_buffer_clavier(void);

/****afficher la grille****/
void afficher_grille(GRILLE );
void afficher_adversaire_grille(GRILLE );

/****Les modes****/
void mode_un(GRILLE ,FLOTTE , TYPE_NAVIRE *);
void mode_deux(GRILLE ,GRILLE,FLOTTE,FLOTTE,TYPE_NAVIRE *,TYPE_NAVIRE *);
void mode_trois(GRILLE,GRILLE,FLOTTE,FLOTTE,TYPE_NAVIRE *,TYPE_NAVIRE *);

/**Pour faire un petit code pour le niveau 3*/
int verifier_code(char [],char []);
int verificateur_carre(GRILLE ,int,int);
int impossible_navire(GRILLE,int,int);


/***Pour le niveau 3, c'est la fonction qui permet de jouer contre l'ordinateur***/
int chercher_coup(GRILLE , FLOTTE *,POSITION *,int,int *,int *);

