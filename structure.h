//
// Created by marin on 20/10/2025.
//

#ifndef STRUCTURE_H
#define STRUCTURE_H
// Une cellule représente une arête

typedef struct cellule {
    int sommet_arrivee;
    float proba;
    struct cellule *suiv;
} cellule;

// Une liste représente l’ensemble des arêtes sortantes d’un sommet
typedef struct {
    cellule *head;
} liste;

// Une liste d’adjacence : tableau de listes
typedef struct {
    int taille;
    liste *tab;
} liste_adjacence;


#endif //STRUCTURE_H
