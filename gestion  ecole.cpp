#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Date {
    int jour;
    int mois;
    int annee;
};

struct Matiere {
    char nomM[20];
    float note;
};

struct etudiant {
    char nome[20];
    char prenome[20];
    int numeu;
    int age;
    struct Date date;
    struct Matiere matiere;
    int nbmatiere;
};

void menu() {
    printf(" MENU: \n 1- Ajouter un etudiant  \n 2- Modifier un etudiant \n 3- Lister les etudiants  \n 4- Rechercher un etudiant \n 5- Supprimer un etudiant \n 6- Gestion des notes  \n Votre choix :  ");
}

void ajouter(struct etudiant *&t, int &taille) {
    int i, nu;
    if (taille == 0) {
        t = (struct etudiant *)malloc(sizeof(struct etudiant));
    } else {
        t = (struct etudiant *)realloc(t, sizeof(struct etudiant) * (taille + 1));
    }
    printf("Veuiller saisir un numero : ");
    scanf("%d", &nu);
    for (i = 0; i < taille; i++) {
        while ((nu == t[i].numeu)) {
            printf("Entrer son numero unique : ");
            scanf("%d", &nu);
            i = 0;
        }
    }
    t[taille].numeu = nu;
    printf("Ajouter le nom d etudiant : ");
    scanf("%s", t[taille].nome);
    printf("Ajouter le prenom de l etudiant : ");
    scanf("%s", t[taille].prenome);
    printf("Ajouter son age : ");
    scanf("%d", &t[taille].age);
    do {
        printf("Veuillez saisir le jour : ");
        scanf("%d", &t[taille].date.jour);
    } while ((t[taille].date.jour < 1) || (t[taille].date.jour > 31));
    do {
        printf("Veuillez saisir le mois : ");
        scanf("%d", &t[taille].date.mois);
    } while ((t[taille].date.mois < 1) || (t[taille].date.mois > 31));
    printf("Veuillez saisir l annee : ");
    scanf("%d", &t[taille].date.annee);
    printf("Ajouter le nombre de matiere : ");
    scanf("%d", &t[taille].nbmatiere);
    printf("Ajouter la matiere : ");
    scanf("%s", t[taille].matiere.nomM);
    printf("Ajouter la note : ");
    scanf("%f", &t[taille].matiere.note);
    taille++;
    printf("Appuyer pour avancer  ");
    getch();
    system("cls");
}

void modifier(char c[20], struct etudiant *t, int taille) {
    int i;
    printf("Donner le nom d etudiant a modifier : ");
    scanf("%s", c);
    for (i = 0; i < taille; i++) {
        if (strcmp(t[i].nome, c) == 0) {
            printf("Donner un noveau nom : ");
            scanf("%s", t[i].nome);
            printf("Donner un nouveau prenom : ");
            scanf("%s", t[i].prenome);
            printf("Donner son nouveau numero d etudiant : ");
            scanf("%d", &t[i].numeu);
            printf("Donner son nouveau age : ");
            scanf("%d", &t[i].age);
            printf("Ajouter un nouveau nombre de matiere : ");
            scanf("%d", &t[i].nbmatiere);
            printf("Ajouter un nouveau nom de matiere : ");
            scanf("%s", t[i].matiere.nomM);
            printf("Ajouter une nouvelle note : ");
            scanf("%f", &t[i].matiere.note);
            do {
                printf("Entre un nouveau jour : ");
                scanf("%d", &t[i].date.jour);
            } while ((t[i].date.jour < 1) || (t[i].date.jour > 31));
            do {
                printf("Entrer un nouveau mois : ");
                scanf("%d", &t[i].date.mois);
            } while ((t[i].date.mois < 1) || (t[i].date.mois > 12));
            printf("Entrer une nouvelle annee : ");
            scanf("%d", &t[i].date.annee);
            printf("Appuyer pour avancer ");
        }
    }
    getch();
    system("cls");
}

void lister(struct etudiant *t, int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("%s| %d | %d | %d | %s | %s |%d |%d | %d | %f",
               t[i].matiere.nomM, t[i].date.annee, t[i].date.mois, t[i].date.jour, t[i].nome, t[i].prenome,
               t[i].numeu, t[i].age, t[i].nbmatiere, t[i].matiere.note);
    }
}

int rechercher(char nom[20], struct etudiant *t, int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        if (strcmp(t[i].nome, nom) == 0) {
            return i;
        }
    }
    return -1;
}

void supprimer(char nom[20], struct etudiant *&t, int &taille) {
    int pos, i;
    printf("Entrer le nom d etudiant  a supprimer : ");
    scanf("%s", nom);
    pos = rechercher(nom, t, taille);
    if (pos == -1) {
        printf("Etudiant INTROUVABLE ! ");
    } else {
        for (i = pos; i < taille; i++) {
            t[i] = t[i + 1];
        }
        taille = taille - 1;
        realloc(t, sizeof(struct etudiant) * (taille));
    }
}



int main() {
    int choix;
    struct etudiant *t = NULL;
    int taille = 0;
    char nome[20];
    char prenome[20];
    int nume;
    char nom[20];
    char c[20];
    do {
        menu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter(t, taille);
                break;
            case 2:
                modifier(c, t, taille);
                break;
            case 3:
                lister(t, taille);
                break;
            case 4:
                rechercher(nom, t, taille);
                break;
            case 5:
                supprimer(nom, t, taille);
                break;
        }
        getch();
        system("cls");
    } while(choix!=5);
}
