#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1-a : Structure de l'étudiant
typedef struct Etudiant
{
    int apogee;
    char nom[20];
    char prenom[20];
    char filiere[10]; // تصحيح الاسم و زيادة المساحة
    struct Etudiant *suivant;
    struct Etudiant *precedent;
} etudiant;

// 1-b : Variables globales
etudiant *debut;
etudiant *fin;
int taille;

// 2-a : Initialiser la liste
void initialiser()
{
    debut = NULL;
    fin = NULL;
    taille = 0;
}

// 2-b : Créer un nouveau noeud
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

// 2-c : Insertion dans une liste vide
void inserer_liste_vide(etudiant *e)
{
    if(taille > 0) return;
    debut = e;
    fin = e;
    e->suivant = NULL;
    e->precedent = NULL;
    taille++;
}

// 2-d : Insertion au début
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

// 2-e : Insertion à la fin
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

// 2-f : Supprimer un étudiant par sa position
int supp_noeud(int pos)
{
    if(taille <= 0 || debut == NULL || pos < 1 || pos > taille) return 0;

    etudiant *supp = debut;
    
    // البحث عن العنصر المراد حذفه
    for(int i = 1; i < pos; i++) {
        supp = supp->suivant;
    }

    if(supp == debut) { // حذف العنصر الأول
        debut = debut->suivant;
        if(debut != NULL) debut->precedent = NULL;
        else fin = NULL;
    } 
    else if(supp == fin) { // حذف العنصر الأخير
        fin = fin->precedent;
        if(fin != NULL) fin->suivant = NULL;
        else debut = NULL;
    } 
    else { // حذف عنصر في الوسط
        supp->precedent->suivant = supp->suivant;
        supp->suivant->precedent = supp->precedent;
    }

    free(supp); // تصحيح: مسح الكائن بالكامل فقط
    taille--;
    return 1;
}

// دالة العرض
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
    
    // إضافة بيانات تجريبية
    inserer_debut(cree_noeud(1234, "Agnaou", "Zakaria", "SIR"));
    inserer_fin(cree_noeud(5678, "Ahmed", "Ali", "IDIA"));
    inserer_fin(cree_noeud(9012, "Omar", "Yassine", "GI"));
    
    printf("Affichage de la liste :");
    afficher();

    printf("Suppression de la position 2...\n");
    supp_noeud(2);
    
    afficher();

    return 0;
}