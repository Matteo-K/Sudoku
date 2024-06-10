/*
A Faire :
procédure test() et ses fonctions
verifChargement()
verifFinParti()
retirer la documentation pour s'aider
*/

/**
* ... Documentation ...
*
* @file Sudoku.c
* @author KERVADEC Mattéo
* @version 1.2
* @date 06 novembre 2023
* @brief Jeu de Sudoku
*
* Jeu de Sudoku
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/******************************
 * Déclaration des constantes *
 ******************************/

#define TAILLE 9
const int VAL_NULL = 0;
const char CAR_NULL = '.';
const char SEP_HORIZON[30] = "  +-------+-------+-------+\n";
const char SEP_VERTICAL = '|';

/**************************
 * Déclarations des types *
 **************************/

/**
* @typedef int tGrille[TAILLE*TAILLE][TAILLE*TAILLE]
* @brief Définition d'un type de tableau en 2 dimensions d'entier
*/
typedef int tGrille[TAILLE][TAILLE];

/*******************************************
 * Déclaration des procédures et fonctions *
 *******************************************/

 /*********************
 * Déroulement du jeu *
 **********************/

/** // Fonctionne
* @fn void chargerGrille(tGrille g)
* @brief charge une grille de Sudoku é partir d'un fichier
*
* @param g type : tGrille. Grille du Sudoku
*/
void chargerGrille(tGrille g);

/** // Fonstionne
* @fn afficherGrille (tGrille tableau)
* @brief affiche la grille de Sudoku
*
* @param tableau type : tGrille. Grille du Sudoku
*/
void afficherGrille (tGrille tableau);

/** // Fonctionne / faire les tests
* @fn void saisir (int *variable)
* @brief vérifie que la variable soit correct
* @param int *variable : valeur de la variable demander
*
* Demande é l'utilisateur la valeur de la variable jusqu'é quelle soit correcte
*/
void saisir (int *variable);

/** // Fonctionne
* @fn int longueurf(tGrille grille)
* @brief compte le nombre de case vide
* @param tgrille grille : grille du Sudoku
*
* Parcour la grille
* Compte le nombre de zéro qui apparait
*/
int longueurf(tGrille grille);

/** // Fonctionne
* @fn void arret(int valeur)
* @brief arrête le programme
* @param int valeur : valeur saisie par le joueur
*
* Si le joueur saisie la valeur -1
* Le programme s'arrête
*
*/
void arret(int valeur);

/****************
 * Vérification *
 ****************/

/** // Fonctionne
* @fn bool possible(tGrille grille, int ligne, int colonne, int valeur);
* @brief vérifie si une valeur est possible
*
* @param grille tGrille : Grille du Sudoku
* @param ligne int : numero de ligne
* @param colonne int : numero de colonne
* @param valeur type : valeur a inserer
*
* @return bool : VRAI si la valeur peut étre ajoutée é la grille ; FAUX sinon
*
* vérifie si une valeur peut étre ajoutée dans une case
* - la valeur néest pas déjé présente sur la méme ligne que la case
* - la valeur néest pas déjé présente sur la méme colonne que la case
* - la valeur néest pas déjé présente dans le méme bloc que la case
* En cas déerreur, il affichera un message d'erreur explicite
* exemple : Erreur Répétition Ligne | la valeur 3 est déjé inséré dans la ligne
*/
bool possible(tGrille grille, int ligne, int colonne, int valeur);

/** // A finir
* @fn bool verifChargement(tGrille grille)
* @brief vérifie que la grille soit correcte pour le chargement
* @param tgrille grille : grille du Sudoku
*
* Vérifie que la grille soit correcte pour le chargement :
* - La grille doit être en deux dimensions
* - Le tableau doit contenir que des entiers entre 0 et 9
* - Le tableau ne doit pas être entièrement vide
*/
bool verifChargement(tGrille grille);

/** // A faire
* @fn bool verifFinParti(tGrille grille)
* @brief vérifie que la grille soit complète
* @param tgrille grille : grille du Sudoku
*
* Vérifie que la grille soit complète :
* - le tableau doit être en deux dimension
* - Le tableau doit contenir que des entiers entre 1 et 9
* - Le tableau ne doit pas contenir de case vide = 0
* - Un chiffre ne peut pas être présent plusieurs fois sur chaque ligne, colonne, bloc
* - La somme de toute les valeurs doit faire 405 soit 9 * 45 soit 9 * (1+2+3+4+5+6+7+8+9)
*/
bool verifFinParti(tGrille grille);

/*************
 * Les tests *
 *************/

/** // A faire
* @fn test(tGrille grille)
* @brief effectue les tests du cahier de test
* @param tgrille grille : grille du Sudoku
*
* Vérifie :
* - le chargement
* - l'affichage
* - la saisie de valeur
* - la fin de partie
*
*/
void test(tGrille grille);

/** // A faire
* @fn testChargement(tGrille grille)
* @brief effectue les tests de chargement
* @param tgrille grille : grille du Sudoku
*
*/
bool testChargement(tGrille grille);

/** // A faire
* @fn testAffichage(tGrille grille)
* @brief effectue les tests de l'affichage
* @param tgrille grille : grille du Sudoku
*
*/
bool testAffichage(tGrille grille);

/** // A faire
* @fn testSaisie(tGrille grille, int valeur)
* @brief effectue les tests de la saisie
* @param tgrille grille : grille du Sudoku
*
*/
bool testSaisie(tGrille grille, int valeur);

/** // A faire
* @fn testFinParti(tGrille grille)
* @brief effectue les tests de fin de partie
* @param tgrille grille : grille du Sudoku
*
*/
bool testFinParti(tGrille grille);

/***********************
 * Programme principal *
 ***********************/


int main() {
    // Déclaration des variables
    tGrille grilleSudoku;
    int numLigne, numColonne, valeur, longueur;
    bool chargement;

    // Saisie des données
    numLigne = VAL_NULL;
    numColonne = VAL_NULL;
    valeur = VAL_NULL;
    longueur = VAL_NULL;

    // Vérifie que la grille est correcte pour commencer
    do {
        chargerGrille(grilleSudoku);
        chargement = verifChargement(grilleSudoku);
        if (chargement != true){
            printf("Choisissez une grille correcte\n");
        }
    } while (chargement != true);

    // Calcul de la condition de fin
    longueur = longueurf(grilleSudoku);

    printf("\n   Saisir '-1' pour abandonner\n\n");

    test();
    // Tant que qu'il y a des cases vides
    while (longueur != VAL_NULL) {
        afficherGrille(grilleSudoku);

        // Demande les cordonnées de la case
        printf("Indices de la case ?\n");
        saisir(&numLigne);
        arret(numLigne);
        saisir(&numColonne);
        arret(numColonne);

        // Vérifie les cordonnées et demande la valeur
        if (grilleSudoku[numLigne-1][numColonne-1]!=VAL_NULL) {
            printf("IMPOSSIBLE, la case %d.%d n'est pas libre.\n",numLigne,numColonne);
        } else {
            printf("\nValeur a inserer ? \n");
            saisir(&valeur);
            arret(valeur);
            if (possible(grilleSudoku, numLigne, numColonne, valeur)) {
                grilleSudoku[numLigne-1][numColonne-1] = valeur;
                longueur --;
            }
        }
    }
    if (verifFinParti(grilleSudoku)) {
        printf("%s","Gagner !");
    }
    printf("Grille pleine, fin de partie");
    return EXIT_SUCCESS;
}



/*************************
 * Procédure et fonction *
 *************************/

void chargerGrille(tGrille g){
    char nomFichier[30];
    int abandon;

    FILE * f;
    FILE * file;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);

    // Si le joueur saisie -1, le jeu s'arrête
    if (sscanf(nomFichier, "%d", &abandon) != VAL_NULL) {
        arret(abandon);
    }
    f = fopen(nomFichier, "rb");
    if (f==NULL){
        printf("\n\033[0;31m Erreur \033[0;0m| sur le fichier %s\n", nomFichier);
    } else {
        fread(g, sizeof(int), TAILLE*TAILLE, f);
    }
    fclose(f);
}



void afficherGrille (tGrille tableau) {
    // Ecriture des cordonnées horizontale
    // Déclaration des variables
    int indice;

    // Initialisation d'un espace
    printf("  ");

    for (indice = 1;indice < TAILLE+1;indice++){
        if ((indice-1)%3 == VAL_NULL) {
            printf("  ");
        }
        printf("%-2d",indice);
    }
    printf("\n");

    // Ecriture du reste de la grille
    // Déclarations des variables
    for (int ligne = VAL_NULL;ligne < TAILLE; ligne ++) {
        if (ligne%3 == VAL_NULL) {
            printf("%s",SEP_HORIZON);
        }
        printf("%-2d",ligne+1);
        for (int colonne = VAL_NULL; colonne < TAILLE; colonne ++) {
            if ((colonne%3) == VAL_NULL) {
                printf("%-2c",SEP_VERTICAL);
            }
            if (tableau[ligne][colonne] == VAL_NULL) {
                printf("%-2c",CAR_NULL);
            } else {
                printf("%-2d",tableau[ligne][colonne]);
            }
        }
        printf("%-2c\n",SEP_VERTICAL);
    }

    printf("%s",SEP_HORIZON);
}



void saisir (int *variable) {
    // Déclaration des variables
    char valeur[10];

    // Demande une valeur et vérifie si c'est entier entre 1 et 9 ou -1
    do {
        printf("Saisir une valeur : ");
        scanf("%s",valeur);
        sscanf(valeur, "%d", &(*variable));
    } while (((*variable < 1) || (*variable > 9)) && *variable != -1); // Vérifier que les valeurs ne soient pas autre que des entiers
}



bool possible(tGrille grille, int ligne, int colonne, int valeur) {
    // Déclaration des variables
    bool possibilite;
    int blocLMin;
    int blocCMin;

    // Initialisation des variables de vérification
    possibilite = true;

    // Initialisation des variables de calcul de cordonné de bloc
    blocLMin = ((ligne-1)/3)*3;
    blocCMin = ((colonne-1)/3)*3;

    for (int id = VAL_NULL;id < TAILLE;id++){
        // Vérification de la valeur dans une ligne
        if (grille[ligne-1][id] == valeur) {
            possibilite = false;
            printf("\033[0;31m Erreur \033[0;0m| La valeur %d est presente dans \nla ligne %d\n",valeur,ligne);
        }

        // Vérification de la valeur dans une colonne
        if (grille[id][colonne-1] == valeur) {
            possibilite = false;
            printf("\033[0;31m Erreur \033[0;0m| La valeur est presente dans \nla colonne %d\n",valeur,colonne);
        }
    }
    if (possibilite != false) {
        // Vérification de la valeur dans un bloc
        for (int idL = blocLMin; idL < (((ligne-1)/3)*3)+3;idL++) {
            for (int idC = blocCMin; idC < (((colonne-1)/3)*3)+3;idC ++) {
                printf("ligne : %d | colonne : %d | valeur : %d | grille : %d\n",idL,idC,valeur,grille[idL][idC]);
                if (grille[idL][idC] == valeur) {
                    possibilite = false;
                    printf("\033[0;31m Erreur \033[0;0m| La valeur %d est presente dans le bloc\n a la ligne %d\n et la colonne %d\n",valeur,idL,idC);
                }
            }
        }
    }

    return possibilite;
}



int longueurf(tGrille grille) {

    int longueur;
    longueur = VAL_NULL;

    for (int idL = VAL_NULL;idL < TAILLE;idL++){
        for (int idC = VAL_NULL; idC < TAILLE;idC++){
            if (grille[idL][idC] == VAL_NULL){
                longueur ++;
            }
        }
    }
    return longueur;
}



/**
* arrête le programme
*/
void arret(int valeur) {
    if (valeur == -1) {
        printf("fin de partie");
        exit(EXIT_FAILURE);
    }
}



/****************
 * Vérification *
 ****************/

/**
* - La grille doit être en deux dimensions
* - Le tableau doit contenir que des entiers entre 0 et 9
* - Un chiffre ne peut pas être présent plusieurs fois sur chaque ligne, colonne, bloc
* - Le tableau ne doit pas être entièrement vide
*/
bool verifChargement(tGrille grille) {
    // Déclaration des variables
    bool chargement;
    int valeur;
    int compteur; // Arrète l'écriture d'erreur excessif si compteur == 1; pour éviter la surcharge console
    char * strValeur;

    // Initialisation des variables
    chargement = true;
    compteur = VAL_NULL;

    // Vérification que la grille est en deux dimensions

    if (chargement != false) {

        /*


        A voir fonction itoa()



        */
        // Vérification que les valeurs sont tous des entiers
        /*
        for (int idL = VAL_NULL; idL < TAILLE; idL++) {
            for (int idC = VAL_NULL; idC < TAILLE; idC++) {
                itoa(grille[idL][idC],strValeur,10);
                if (sscanf(strValeur,"%d",&valeur) == VAL_NULL) {
                    printf("\033[0;31m Erreur \033[0;0m| La grille possede une valeur qui n'est pas un entier (%s)\n",strValeur);
                    chargement = false;
                    compteur = 1;
                }
            }
        }
        */
        if (chargement != false) {

            // Vérification que toute les valeurs soit des chiffres entre 1 et 9
            for (int ligne = VAL_NULL;ligne < TAILLE;ligne++){
                for (int colonne = VAL_NULL;colonne < TAILLE;colonne++){
                    valeur = grille[ligne][colonne];
                    if (((valeur < VAL_NULL) || (valeur > 9)) && compteur == VAL_NULL) {
                        if (valeur < VAL_NULL) {
                            printf("\033[0;31m Erreur \033[0;0m| La grille possede une valeur inferieur a zero\n");
                        } else {
                            printf("\033[0;31m Erreur \033[0;0m| La grille possede une valeur superieur a zero (%d)\n",valeur);
                        }
                        chargement = false;
                        compteur = 1;
                    }
                }
            }

            if (chargement != false) {

                // Vérification que la grille ne contiennent pas que des 0
                if (longueurf(grille) == TAILLE*TAILLE){
                    chargement = false;
                }
            }
        }
    }
    return chargement;
}



/**
* - le tableau doit être en deux dimension
* - Le tableau doit contenir que des entiers entre 1 et 9
* - Le tableau ne doit pas contenir de case vide = 0
* - Un chiffre ne peut pas être présent plusieurs fois sur chaque ligne, colonne, bloc
* - La somme de toute les valeurs doit faire 405 soit 9 * 45 soit 9 * (1+2+3+4+5+6+7+8+9)
*/
bool verifFinParti(tGrille grille) {
    // Déclaration des variables
    bool partFin;

    // Initialisation des variables
    partFin = true;

    // Vérifie que la grille est en deux dimensions

    if (partFin != false) {

        // Vérifie que la grille contient que des entiers
        // Vérifie que la grille contient que des chiffres entre 1 et 9
        // Calcul la somme de toute les valeur de la grille

        if (partFin != false) {

                // Vérifie qu'un chiffre n'est pas plusieurs fois sur chaque ligne, colonne, bloc
                // Parcour une diagonale de la grille en essayant chaque chiffre sur la case.
        }
    }
}



/*********
 * Tests *
 *********/



/**
* Vérifie :
* - le chargement
* - l'affichage
* - la saisie de valeur
* - la fin de partie
*
*/
void test(tGrille grille){

}



bool testChargement(tGrille grille){

}



bool testAffichage(tGrille grille){

}



bool testSaisie(tGrille grille, int valeur){

}



bool testFinParti(tGrille grille){

}
