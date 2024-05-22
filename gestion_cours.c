#include "cours.h"


cours *listeCours = NULL;
int listeCoursSize = 0;

void ajouterCours() {

    cours *newCours = (cours *)malloc(sizeof(cours));

    printf("Nom du cours: ");
    scanf("%s", newCours->nom);

    printf("Code du cours: ");
    scanf("%s", newCours->codeCours);

    printf("Nombre d'etudiants: ");
    scanf("%d", &newCours->NbEtudiants);

    newCours->etudiants = (char **)malloc(newCours->NbEtudiants * sizeof(char *));
    for (int i = 0; i < newCours->NbEtudiants; i++) {
        newCours->etudiants[i] = (char *)malloc(50 * sizeof(char)); 
        printf("Nom etudiant %d: ", i + 1);
        scanf("%s", newCours->etudiants[i]);
    }


    listeCours = (cours *)realloc(listeCours, (listeCoursSize + 1) * sizeof(cours));
    listeCours[listeCoursSize++] = *newCours;

}

void printCourses(cours *listeCours, int listeCoursSize) {
    for (int i = 0; i < listeCoursSize; i++) {
        printf("Cour nom %d: %s\n", i + 1, listeCours[i].nom);
        printf("Cour code %d: %s\n", i + 1, listeCours[i].codeCours);
        printf("Cour NbEtudiants %d: %d\n", i + 1, listeCours[i].NbEtudiants);
        for (int j = 0; j < listeCours[i].NbEtudiants; j++) {
            printf("Cour etudiant %d: %s\n", j + 1, listeCours[i].etudiants[j]);
        }
    }
}



void supprimerCours() {
    if (listeCoursSize == 0) {
        printf("Il n'y a pas de cours a supprimer.\n");
        return;
    }

    char codeCours[225];
    printf("Entrez le code du cours a supprimer: ");
    scanf("%s", codeCours);

    int index = -1;
    for (int i = 0; i < listeCoursSize; i++) {
        if (strcmp(listeCours[i].codeCours, codeCours) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Le cours avec le code %s nexiste pas.\n", codeCours);
        return;
    }


    for (int i = 0; i < listeCours[index].NbEtudiants; i++) {
        free(listeCours[index].etudiants[i]);
    }
    free(listeCours[index].etudiants);

    for (int i = index; i < listeCoursSize - 1; i++) {
        listeCours[i] = listeCours[i + 1];
    }

    listeCours = (cours *)realloc(listeCours, (listeCoursSize - 1) * sizeof(cours));
    listeCoursSize--;
    printf("Le cours avec le code %s a EtE supprimE.\n", codeCours);
}

void rechercherCours() {
    if (listeCoursSize == 0) {
        printf("Il n'y a pas de cours a rechercher.\n");
        return;
    }

    char codeCours[225];
    printf("Entrez le code du cours a rechercher: ");
    scanf("%s", codeCours);

    int index = -1;
    for (int i = 0; i < listeCoursSize; i++) {
        if (strcmp(listeCours[i].codeCours, codeCours) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Le cours avec le code %s nexiste pas.\n", codeCours);
        return;
    }

    printf("Cour nom: %s\n", listeCours[index].nom);
    printf("Cour code: %s\n", listeCours[index].codeCours);
    printf("Cour NbEtudiants: %d\n", listeCours[index].NbEtudiants);
    for (int j = 0; j < listeCours[index].NbEtudiants; j++) {
        printf("Cour etudiant %d: %s\n", j + 1, listeCours[index].etudiants[j]);
    }
}



int main() {
    int choix;

    do {
        printf("\nMenu de gestion des cours:\n");
        printf("1. Ajouter un cours\n");
        printf("2. Supprimer un cours\n");
        printf("3. Rechercher un cours\n");
        printf("4. Afficher tous les cours\n");
        printf("0. Quitter\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterCours();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            case 2:
                supprimerCours();
                break;
            case 3:
                rechercherCours();
                break;
            case 4:
                printCourses(listeCours, listeCoursSize);
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}