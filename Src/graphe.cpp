#include <vector>
#include <iostream>
#include <assert.h>
#include <queue>
#include "graphe.hpp"
#include "board.hpp"


using namespace RR;
// ------------- Struct Noeud ------------- //

void Noeud::setValues(const Robot& rbt) {
  info = rbt;
}

void Noeud::addLink(Noeud* n) {
  linked.push_back(n);
}

bool Noeud::equalTo(const Robot& rbt) const {
  if(info.location == rbt.location && info.status == rbt.status)
    return true;
  return false;
}

void Noeud::display(const int& n, const bool& withLinks) const {
  std::cout << "Je suis le noeud numero " << n <<  " avec pour coordonnées : "
          << std::endl
          << "(" << info.location.line << "," << info.location.column << ") "
          << std::endl;
  if(withLinks) {
    std::cout << "Je pointe sur (normalement 7) : " << linked.size() << " noeud(s)"<< std::endl << std::endl;
  }
}


// ------------- Classe Graphe ------------- //

Graphe::Graphe(const Robot& rbt, const Board& board) {
  construitGraphe(rbt, board, false);
}

void Graphe::construitGraphe(const Robot& rbt, const Board& board, const bool& verbose) {

  //on crée le noeud vers lequel va pointer les déplacements détruit
  detruit = new Noeud();
  detruit->info.location = Location(-1,-1);
  detruit->info.status = Robot::Status::DEAD;

  std::cout<< "starting graph building"<< std::endl;

  //on crée le noeud initial
  Noeud* n0 = new Noeud();
  n0->setValues(rbt);
  noeuds.push_back(n0);
  nbsommet++;

  int visited = 0; //entier correspondant a l'indice du noeud étudié dans le tableau
  Robot transfer; //donnée pour copier celles du noeud en étude
  int tmp; //valeur tampon


  while(visited < nbsommet) {
    if( not(noeuds[visited]->info.location == Location(5,4)) ) {
      for(unsigned int i = 0; i < 7; i++) {
        transfer = noeuds[visited]->info;
        board.play(transfer,moves[i]);

        if(transfer.status == Robot::Status::DEAD) {
          noeuds[visited]->addLink(detruit);
        }
        else  {
          tmp = existeDeja(transfer);
          if(tmp != -1) {
            noeuds[visited]->addLink(noeuds[tmp]);
          } else {
            Noeud* n = new Noeud;
            n->setValues(transfer);
            noeuds.push_back(n);
            nbsommet++;
            noeuds[visited]->addLink(noeuds[nbsommet - 1]);
          }
        }
      }
      if(verbose) {
        noeuds[visited]->display(visited,true);
      }
      assert(nbsommet <= 128); // on a calculé qu'il peut y avoir au maximum 128 position possible du robot sur un plateau de 32 cases
    }
    visited++;
  }
  std::cout<<std::endl;
  std::cout<<"Done, "<< nbsommet << " cells produced" << std::endl;
}

int Graphe::existeDeja(const Robot& rbt) const {
  for(int i = 0; i < nbsommet; i++) {
    if(noeuds[i]->equalTo(rbt)){
      return i;
    }
  }
  return -1;
}

void Graphe::pluscourtChemin(const Robot& init, const Location& arrivee) {
  int info_noeuds[nbsommet][2];
  int i;
  for(i = 0; i < nbsommet; i++) {
    info_noeuds[i][0] = 100000; //la distance parcouru
    info_noeuds[i][1] = 100000; //la cellule parente
  }

  int tmp = existeDeja(init); // on retrouve le noeud de départ dans le graphe
  if(tmp == -1)
    return; //si jamais la position n'existe pas dans le graphe on termine le programme
  std::queue<int> file; //file d'indice a étudier

  file.push(tmp); //on ajoute l'indice noeud de départ
  info_noeuds[tmp][0] = 0;
  info_noeuds[tmp][1] = tmp; //on met comme parent lui-meme car c'est le point de départ

  int distD;
  int distA;

  while(!file.empty()) {
    tmp = file.front(); //on prend le dernier elem et on le retire de la file
    file.pop();
    distD = info_noeuds[tmp][0] + 1;
    for(i = 0; i < 7; i++) {
      distA = info_noeuds[i][0];
      if(distD < distA) {
        info_noeuds[i][0] = distD;
        info_noeuds[i][1] = tmp;
      }
    }
  }
}


Graphe::~Graphe(){
  delete detruit;
  for(long unsigned int i = 0; i < noeuds.size(); i++) {
    delete noeuds[i];
  }
}
