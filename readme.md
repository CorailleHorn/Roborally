Auteurs: Saury jean et Mhenni Hassen

Projet visant a créer un graphe en c++ pour représenter les déplacements d'un robot dans un jeu dont le code était fourni, puis d'analyser dans le graphe le plus court chemin en emprunter (utilisation de l'algorithme Djikstra) et enfin d'appliquer le résultat au jeu (résultat donné dans le terminal).

Pour compiler : make 
Pour lancer : ./test_board 
Pour lancer l'application web (afficher la graph): ./app board.txt 

Partie 1 : Structures de données.
Dans cette partie on va devoir stocker un graphe du jeu, donc les différents nœuds, arrêtes du graphe de jeu. on a définit la procédure construitGraphe dans graphe.hpp qui prend on paramètre un board , un booléen et qui affiche le graphe ainsi que le nombre de nœuds.

Partie 2 : Plus court chemin dans un graphe.
A partir du graphe , on doit trouver le plus court chemin d'une position initiale à une position d'arrivée . On a donc définit la fonction pluscourtChemin de type std::vector<int> dans graphe.hpp et qui prend en paramètre un tableau de int (vector) dans lequel on va utiliser l'algorithme de Dijkstra. 

Partie 3:Joueur artificiel.
En utilisant les deux fonctions définis précédemment le joueur artificiel doit choisir les 5 meilleures cartes parmi les 9 piochées afin de faire le plus court chemin de sa position initial à la position d’arrivée. On a définit la fonction playcard dans card.hpp pour réaliser cela. Et on s'assurera la validité de chaque noeuds/ chemins dans djikstra a chaques itérations. 


