# Prog-C-ESIPE-S2
Ensemble de mes TPs de C - ESIPE INFO 1 - S2

Portfolio disponible à cette adresse :
*Prochainement disponible*

Ensemble de mes productions disponible sur GitHub :
https://github.com/Tietienne/Prog-C-ESIPE-S2

# Compilation et exécution

Tous les TPs sont munis d'un makefile, il faut utiliser la commande :

"*make*"

Puis lancer l'exécutable qui en ressort ("*./ExoX*" ou "./main" ou ...)

La commande "*make clean*" est aussi disponible afin de nettoyer tous les fichiers compilés et les exécutables.

A l'exception des TPs 11 et 13, qui utilise la bibliothèque libMLV, tous les autres TPs n'ont aucune perte de mémoire ou d'erreurs (vérification avec valgrind).

**ATTENTION :** Il est nécessaire d'installer la bibliothèque GNU readline pour compiler le TP15. Sous Debian-like, il faut utiliser la commande : "*sudo apt-get install libreadline-dev*".

# Contenu détaillé des TPs

- TP 9 :

Allocation de mémoires sur des nombres, sur des tableaux à 2 dimensions, échange de mémoire entre 2 éléments, premières vérifications avec valgrind

- TP 10 :

Fonction d'échange de zone mémoire générique, utilisation de listes chaînées pour trier des personnes

- TP 11 :

Jeu de taquin graphique simple sans ajouts particuliers (utilisation de la bibliothèque libMLV)

- TP 12 :

Comptage de mots différents dans un fichier : façon naïve (liste chaînée), façon intelligente (table de hachage)

- TP 13 :

Problème des huits dames graphique simple sans ajouts particuliers (utilisation de la bibliothèque libMLV) : manipulation des bits

- TP 14 :

Programme affichant les 10 fichiers les plus volumineux dans un répertoire donné en argument

- TP 15 :

Programme simulant une calculatrice en polonais inversé (utilisation de la bibliothèque GNU readline)
