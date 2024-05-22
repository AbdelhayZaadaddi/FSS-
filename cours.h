#ifndef COURS_H
#define COURS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la definition de la structure cours
typedef struct cours {
    char nom[225];
    char codeCours[225];
    int NbEtudiants;
    char **etudiants;

} cours;

extern cours *liste_cours;

#endif