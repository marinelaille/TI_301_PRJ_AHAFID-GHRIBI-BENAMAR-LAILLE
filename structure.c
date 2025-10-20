//
// Created by marin on 20/10/2025.
//

#include "structure.h"
#include <stdio.h>


cellule *createCellule(int sommet_arrivee, float proba) {
    cellule *new = (cellule *)malloc(sizeof(cellule));
    new->sommet_arrivee = sommet_arrivee;
    new->proba = proba;
    new->suiv = NULL;
    return new;
}

liste createListe() {
    liste l;
    l.head = NULL;
    return l;
}

void ajouterCellule(liste *l, int sommet_arrivee, float proba) {
    cellule *new = createCellule(sommet_arrivee, proba);
    new->suiv = l->head;
    l->head = new;
}

liste_adjacence createListeAdj(int taille) {
    liste_adjacence g;
    g.taille = taille;
    g.tab = (liste *)malloc(taille * sizeof(liste));
    for (int i = 0; i < taille; i++) {
        g.tab[i] = createListe();
    }
    return g;
}

void afficherListe(liste l) {
    cellule *temp = l.head;
    while (temp != NULL) {
        printf("-> (%d, %.2f) ", temp->sommet_arrivee, temp->proba);
        temp = temp->suiv;
    }
    printf("\n");
}

void afficherListeAdj(liste_adjacence g) {
    for (int i = 0; i < g.taille; i++) {
        printf("Sommet %d : ", i + 1);
        afficherListe(g.tab[i]);
    }
}

liste_adjacence readGraph(const char *filename) {
    FILE *file = fopen(filename, "rt");

    int nbvert, depart, arrivee;
    float proba;

    if (file == NULL) {
        perror("Erreur d’ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d", &nbvert);
    liste_adjacence g = createListeAdj(nbvert);

    while (fscanf(file, "%d %d %f", &depart, &arrivee, &proba) == 3) {
        ajouterCellule(&g.tab[depart - 1], arrivee, proba);
    }

    fclose(file);
    return g;
}

