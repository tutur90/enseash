# enseash

Creation d'un mini shell en C pour les ENSEARQUE


## Question 1

Dans cette question nous avons simplement utiliser la fonction write pour ecrire notre message de bienvenue

[!Q1](/img/Q1.png)

## Question 2

Dans cettequestion nous avons utiliser une boucle infinie while(1) pour
-dans la question a : lire la commande saisie a l'aide de la fonction read
-dans la question b : executer la commande saisie avec execlp en utilisant un fork pour creer un processus parent et enfant
-dans la question c : simplement retourner au prompt en utilisant write

[!Q2](/img/Q2.png)

## Question 3

On compare le texte en entrée à la chaîne de caractères “exit” en utilisant la fonction strcmp qui renvoie 0 si les deux chaînes de caractères sont identiques pour pouvoir arreter la boucle infine et quitter notre shell.

[!Q3](/img/Q3.png)

Pour nous assurer qu'il n' y est pas plusieurs proces en cours du fait de la fonction fork, nous avons gerer tout les cas possible de pid = fork(), en utilisant exit() a chaque fois. Sans ca, lors que nous tapions 'exit', nous quittions seulement le processus en cours et non le shell.

## Question 4

Pour éviter les répétitions, on écrit une fonction qui sert à formater une chaîne de caractère en y intégrant le code de sortie.

[!Q4](/img/Q4.png)

## Question 5

Pour cette question notre objectif etait de mesurer le temps d' execution d'une fonction, pour ce faire nous calculons la difference entre le debut et la fin de l'execution a l'aide de la fonction clock_gettime() de la librairie clock

[!Q5](/img/Q5.png)

## Question 6

Dans cette question, nous voulons pouvoir ajouter des arguments lorsque nous ecrivons une commande, pour cela nous creeons une fonctions getCommand qui tokenize la chaine d'entrer pour pouvoir ensuite la commande et ces arguments.

[!Q6](/img/Q6.png)

## Question 7

Nous avons mis en place un systeme de redirection qui permet d'ecrir dans un fichier l'output ou de lire un input

[!Q7](/img/Q7.png)