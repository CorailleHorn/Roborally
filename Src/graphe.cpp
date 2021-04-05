#include <vector>
#include <iostream>
#include <assert.h>
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

void Noeud::display(const int& n, const bool& withLinks) {
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
  construitGraphe(rbt, board);
}

void Graphe::construitGraphe(const Robot& rbt, const Board& board) {

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
    noeuds[visited]->display(visited,true);
    assert(nbsommet <= 128); // on a calculé qu'il peut y avoir au maximum 128 position possible du robot sur un plateau de 32 cases
    //std::cout<< visited + " cell analyzed"<< std::endl;
    visited++;
  }
  std::cout<< visited + " cell analyzed"<< std::endl;
}

int Graphe::existeDeja(const Robot& rbt) const {
  for(int i = 0; i < nbsommet; i++) {
    if(noeuds[i]->equalTo(rbt)){
      return i;
    }
  }
  return -1;
}

Graphe::~Graphe(){
  delete detruit;
  for(long unsigned int i = 0; i < noeuds.size(); i++) {
    delete noeuds[i];
  }
}
