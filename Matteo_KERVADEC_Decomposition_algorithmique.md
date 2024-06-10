Nom : KERVADEC Mattéo

Groupe TP : 1C2

# <span style="color:red">SAE 1.01 - Implémentation d'un besoin client</span>
## Décomposition du Sudoku en Algorithme

### // <span style="color:blue">la structure</span> //

    - type t_caseSudoku = structure
    // Décomposition des cases de la grille de Sudoku. (se rapproche de la programmation objet)
    Debut
        c_valeur : int;
            Valeur de la case

        c_estcorrect : booléen;
            Affiche la valeur en vert si la case entrée est correct

        c_estincorrect : booléen;
            Affiche la valeur en rouge si la case entrée est incorrect

        c_estcurseur : booléen;
            Affiche la valeur en orange si la case représente le curseur

    Fin

> La grille de Sudoku est décomposé en un tableau en 2 dimensions. Chacune des valeurs de cette grille à la partie cularité d'être en couleur. Pour cela, chaque case est une structure. Ainsi nous avons un tableau de type t_caseSudoku.

### // <span style="color:blue">Le Main</span> //

    ----------------------------------------------

    // Déclaration des constantes
    constante caractere PART_FIN := 1;
    constante caractere FIN := 'N';

    Programme Sudoku c'est 
    Debut
        // Déclaration des variables
        rejouer : caracter;
        partie : entier;
        t_grille : t_caseSudoku;
        // Réalisation d'une ou plusieurs parties de sudoku
        Faire
            // Définition de la difficulté et de la grille
            t_grille := difficulte();
            ecrireEcran("Bienvenue dans le jeu du Sudoku \n");
            help();
            // Execution du tour de jeu
            Faire
                partie := tour(ent t_grille);
                /* Si la partie est fini, alors la boucle s'arrète
                1 : fini
                0 : pas fini */
            Tant que (partie != PART_FIN);
            ecrireEcran("O : oui \nN : non \nVoulez-vous rejouer ? ");
            lireClavier(rejouer);
            tant que ((rejouer != 'N') && (rejouer != 'O')) faire
                ecrireEcran("Erreur de syntaxe ! \n Réponse erronée \nVoulez-vous rejouer ? ");
                lireClavier(rejouer);
            fin faire
        Tant que (rejouer != FIN);
        ecrireEcran("Merci d’avoir jouer. A bientôt");
    Fin

    ----------------------------------------------

### // <span style="color:blue">Fonction et Procédure d'affichage</span> //

    ----------------------------------------------

    - Procédure Affichage
    Affiche la grille de Sudoku.
    Si un caractère est en couleur, il l'affichera en couleur

    paramètre :
        tab (ent) : tableau de type t_caseSudoku
            tableau en 2 dimensions / grille principale du jeu

    résultat :
        affiche la grille

    ----------------------------------------------
    
    - Procédure AfficheSepHorizon
    Affiche une ligne de séparateur entre les 3 niveaux de la grille
    ex : - - - - - - - - - - - - - - -

    paramètre :
        ø

    résultat :
        Affiche une ligne de séparateur

    ----------------------------------------------

    - Procédure clrDefaut
    Met la couleur par défaut.
    Une case ne peut pas avoir plusieurs couleur, il y a des priorités

    paramètre :
        ø

    résultat :
        Met la couleur par défaut

    ----------------------------------------------

    - Procédure clrVert
    Met la couleur en vert.
    La case modifiée par le joueur est correcte

    paramètre :
        ø

    résultat :
        Met la couleur en vert

    ----------------------------------------------

    - Procédure clrRouge
    Met la couleur en rouge.
    La case modifiée par le joueur est incorrecte

    paramètre :
        ø

    résultat :
        Met la couleur en rouge

    ----------------------------------------------
    
    - Procédure clrOrange
    Met la couleur en Orange.
    La case représente le curseur de déplacement.
    Si le curseur est sur une case correcte (vert). La couleur de la case sera orange.
    Orange > Vert et Rouge

    paramètre :
        ø

    résultat :
        Met la couleur en orange

    ----------------------------------------------
### // <span style="color:blue">Fonction et Procédure de vérification</span> //

> Les fonctions et procédures de vérifications sont nécessaires au fonctionnement du programme. Elle permet de vérifier que les valeurs qui sorte sont correcte et qu'ils ne renvoient pas d'autre résultat. Et ainsi envoyer des messages d'erreurs.

    ----------------------------------------------

    - Fonction verifEntier
    Vérifie que tout les éléments d'un tableau sont des entiers

    paramètres : 
        t_tab (ent) : tableau d'entier
            Tableau d'entier de 1 à 9

        estEntier (sort) : booléen
            Indique si la suite de nombre est composé uniquement d'entier

    résultat : 
        estEntier : booléen
            True si le tableau contient uniquement des entiers
            False sinon

    ----------------------------------------------

    - Fonction estModifiable
    Vérifie que la case du tableau vaut 0.
    Si False affiche une erreur dans la console

    paramètres : 
        t_tab (ent) : tableau de type t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

        x (ent) : entier
            Coordonnée de la colonne de la case

        y (ent) : entier
            Coordonnée de la ligne de la case

        modifiable (sort) : booléen
            Indique si la case est modifiable

    résultat : 
        modifiable : booléen
            True si la case vaut 0
            False sinon

    ----------------------------------------------

    - Fonction verifDepassement
    Indique au joueur que le curseur est sortie de la grille. 
    Et ne le déplace pas vers l'endroit voulu.
    Puis affiche une erreur dans la console

    Les indices de la grille doivent être entre 1 et 9

    paramètres :
        x (ent) : entier
            Indice de la colonne

        y (ent) : entier
            Indice de la ligne

        dpssmnt (sort) : booléen
            Indique si le curseur dépasse de la grille
    
    résultat :
        dpssmnt : booléen
            True si dépassement et affiche un message d'erreur de depassement de grille dans la console
            False sinon
    
    ----------------------------------------------

    - Fonction triBulle
    Trie un tableau d'entier dans l'ordre croissant avec la méthode de tri à bulle.
    L'utilisation de cette méthode pour son trie très rapide et son efficacité

    paramètre :
        t_tab (ent/sort) : tableau d'entier
            Tableau de chiffre entier à ranger dans l'ordre croissant

    résultat :
        t_tab : tableau d'entier
            Tableau trié dans l'ordre croissant

    ----------------------------------------------  

    - Fonction verifLigne
    Vérifie qu'une ligne, colonne ou carré remplit les conditions suivante :
        - Vérifie qu'un tableau trié contient tout les chiffres de 1 à 9.
        - Vérifie que le tableau trié ne contient pas de doublon.
        - Vérifie que la somme des chiffres du tableau vaut 45 (1+2+...+9 = 45).

    paramètres :
        t_ligne (ent) : tableau de type entier
            Tableau de chiffre entier qui contient 9 éléments

        ligneCorrect (sort) : booléen
            Indique si la ligne répond aux conditions

    résultat :
        ligneCorrect : booléen
            True si les conditions sont remplis
            False sinon
        
    ----------------------------------------------    

    - Fonction selectLigne
    Prend une ligne du tableau suivant l'indice du premier élément de la colonne
    
    paramètres :
        t_tab (ent) : tableau de type t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

        x (ent) : int
            L'indice du premier élément de la colonne

        t_ligne (sort) : tableau d'entier
            Liste d'élément d'une ligne du tableau t_tab

    résultat :
        t_ligne : tableau d'entier
            Extrait d'une ligne du tableau principale

    ----------------------------------------------

    - Fonction selectColonne
    Prend une colonne du tableau suivant l'indice du premier élément de la ligne
    
    paramètres :
        t_tab (ent) : tableau de type t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

        y (ent) : int
            L'indice du premier élément de la ligne

        t_colonne (sort) : tableau d'entier
            Liste d'élément de la colonne du tableau t_tab
    résultat :
        t_colonne : tableau d'entier
            Extrait d'une colonne du tableau principale

    ----------------------------------------------

    - Fonction selectCarre
    Prend un carré du tableau suivant les indices du centre d'un carré avec la ligne et la colonne
    
    paramètres :
        t_tab (ent) : tableau de type t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

        Les indices du centre d'un carré

        x (ent) : int
            L'indice de la colonne 

        y (ent) : int
            L'indice de la ligne

        t_carre (sort) : tableau d'entier
            Liste d'élément d'un carré du tableau t_tab

    résultat :
        t_carre : tableau d'entier
            Extrait d'un carré du tableau principale

    ----------------------------------------------

    - Fonction verifGrilleComplete
    Parcour le tableau et vérifie si le tableau est complet avec les fonctions si-dessus.
    Il vérifie les lignes, les colonnes et les carrés

    paramètres : 
        t_tab (ent) : tableau de type t_caseSudoku
            Tableau en 2 dimensions

        estComplet (sort) : booléen
            Indique si la grille est complète

    résultat :
        estComplet : Booléen
            True si complet
            False sinon
    
### // <span style="color:blue">Fonction et Procédure de Déroulement du Programme</span> //    

    ----------------------------------------------
    
    - Fonction difficulte
    Demande au joueur la difficulté du jeu.
    Puis le jeu choisi aléatoirement une grille parmit celles pré-enregistré

    parmètre :
        t_grille (sort) : t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

    résultat : 
        t_grille : t_caseSudoku
            Tableau incomplèt qui contient des éléments de 1 à 9.
            Et des 0 comme éléments vide

    ----------------------------------------------

    - Fonction tour
    Procède à un tour du programme.
    Demande à l'utilisateur l'action qu'il veut faire puis renvoie au commande si-dessous suivant l'action.
    Et affiche la grille de sudoku suivant les cas

    parmètres :
        t_grille (ent) : t_caseSudoku
            Tableau en 2 dimensions / grille principale du jeu

        partie (sort) : entier (soit 1 ou 0)
            Indique au main si la partie est fini

    résultat : 
        partie : entier (soit 1 ou 0)
            Indique au main si la partie est fini
            1 : fini
            0 : pas fini

    ----------------------------------------------

    - Procédure regle
    Affiche dans la console les règles du Sudoku

    paramètre :
        ø
    
    résultat :
        Affiche les règles

    ----------------------------------------------

    - Procédure help
    Affiche à l'utilisateur toute les commandes nécessaire pour joueur au jeu

    paramètre :
        ø
    
    résultat :
        Affiche le menu aide

    ----------------------------------------------

    - Fonction deplacementD
    Modifie la position de la colonne du curseur en additionnant 1.
    Afin de déplacer le curseur vers la droite

    paramètre :
        x (ent/sort) : entier
        Coordonnée de la colonne du curseur

    résultat :
        x : entier
        Coordonnée de la colonne du curseur
        avec x = x+1

    ----------------------------------------------

    - Fonction deplacementG
    Modifie la position de la colonne du curseur en soustrayant 1.
    Afin de déplacer le curseur vers la gauche

    paramètre :
        x (ent/sort) : entier
        Coordonnée de la colonne du curseur

    résultat :
        x : entier
        Coordonnée de la colonne du curseur
        avec x = x-1

    ----------------------------------------------

    - Fonction deplacementH
    Modifie la position de la ligne du curseur en soustrayant 1.
    Afin de déplacer le curseur vers le haut

    paramètre :
        y (ent/sort) : entier
        Coordonnée de la ligne du curseur

    résultat :
        y : entier
        Coordonnée de la ligne du curseur
        avec y = y-1

    ----------------------------------------------

    - Fonction deplacementB
    Modifie la position de la ligne du curseur en additionnant 1.
    Afin de déplacer le curseur vers le haut

    paramètre :
        y (ent/sort) : entier
        Coordonnée de la colonne du curseur

    résultat :
        y : entier
        Coordonnée de la colonne du curseur
        avec y = y+1

    ----------------------------------------------

    - Procédure ecrire
    Permet à l'utilisateur de pouvoir modifier la grille

    parmètre :
        tab (ent/sort) : tableau de type t_caseSudoku

    résultat :
        tab  : tableau de type t_caseSudoku
            avec une case x,y du curseur modifier

    ----------------------------------------------