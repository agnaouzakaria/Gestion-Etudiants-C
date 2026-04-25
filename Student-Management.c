#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure contenant les informations de l'étudiant
typedef struct Etudiant
{
    int apogee;
    char nom[20];
    char prenom[20];
    char filiere[10]; 
    struct Etudiant *suivant;
    struct Etudiant *precedent;
} etudiant;

// Variables globales pour la gestion de la liste
etudiant *debut;
etudiant *fin;
int taille;

// Initialisation de la liste
void initialiser()
{
    debut = NULL;
    fin = NULL;
    taille = 0;
}

// Création d'un nouveau noeud avec allocation dynamique
etudiant* cree_noeud(int apo, char *nm, char *pr, char *fil)
{
    etudiant *nv = (etudiant*)malloc(sizeof(etudiant));
    if(nv == NULL) return NULL;
    
    nv->apogee = apo;
    strcpy(nv->nom, nm);
    strcpy(nv->prenom, pr);
    strcpy(nv->filiere, fil);
    nv->precedent = NULL;
    nv->suivant = NULL;
    return nv;
}

// Cas particulier : insertion dans une liste vide
void inserer_liste_vide(etudiant *e)
{
    if(taille > 0) return;
    debut = e;
    fin = e;
    e->suivant = NULL;
    e->precedent = NULL;
    taille++;
}

// Insertion au début de la liste
void inserer_debut(etudiant *e)
{
    if(e == NULL) return;
    if(taille == 0) inserer_liste_vide(e);
    else {
        e->suivant = debut;
        debut->precedent = e;
        debut = e;
        debut->precedent = NULL;
        taille++;
    }
}

// Insertion à la fin de la liste
void inserer_fin(etudiant *e)
{
    if(e == NULL) return;
    if(taille == 0) inserer_liste_vide(e);
    else {
        fin->suivant = e;
        e->precedent = fin;
        fin = e;
        e->suivant = NULL;
        taille++;
    }
}

// Suppression d'un noeud par position (1..n)
int supp_noeud(int pos)
{
    if(taille <= 0 || debut == NULL || pos < 1 || pos > taille) return 0;

    etudiant *supp = debut;
    
    for(int i = 1; i < pos; i++) {
        supp = supp->suivant;
    }

    if(supp == debut) { 
        debut = debut->suivant;
        if(debut != NULL) debut->precedent = NULL;
        else fin = NULL;
    } 
    else if(supp == fin) { 
        fin = fin->precedent;
        if(fin != NULL) fin->suivant = NULL;
        else debut = NULL;
    } 
    else { 
        supp->precedent->suivant = supp->suivant;
        supp->suivant->precedent = supp->precedent;
    }

    free(supp); 
    taille--;
    return 1;
}

// Affichage de la liste sous forme de tableau
void afficher()
{
    etudiant *courant = debut;
    printf("\n| %-10s | %-10s | %-10s | %-10s |\n", "Apogee", "Nom", "Prenom", "Filiere");
    printf("------------------------------------------------------------\n");
    while(courant != NULL) {
        printf("| %-10d | %-10s | %-10s | %-10s |\n", courant->apogee, courant->nom, courant->prenom, courant->filiere);
        courant = courant->suivant;
    }
    printf("------------------------------------------------------------\n\n");
}

int main()
{
    initialiser();
    
    // Exemple de test
    inserer_debut(cree_noeud(1234, "Agnaou", "Zakaria", "SIR"));
    inserer_fin(cree_noeud(5678, "Ahmed", "Ali", "IDIA"));
    inserer_fin(cree_noeud(9012, "Omar", "Yassine", "GI"));
    
    afficher();
    
    printf("Suppression de la position 2...\n");
    supp_noeud(2);
    
    afficher();

    return 0;
}
