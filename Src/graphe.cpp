#include "graphe.hpp"
#include <vector>
#include "board.hpp"
using namespace RR;
// ------------- Struct Noeud ------------- //

void Noeud::setValues(const Robot& rbt) {
  info.location = rbt.location;
  info.status = rbt.status;
}

void Noeud::addLink(Noeud* n) {
  linked.push_back(n);
}


// ------------- Classe Graphe ------------- //

Graphe::Graphe(const Robot& rbt, const Board& board) {
  construitGraphe(rbt, board);
}

void Graphe::construitGraphe(const Robot& rbt, const Board& board) {
  //on crée le noeud vers lequel va pointer les déplacements détruit
  detruit->info.location = Location(-1,-1);
  detruit->info.status = Robot::Status::DEAD;

  //on crée le noeud initial
  Noeud* n0;
  n0->setValues(rbt);
  noeuds.push_back(n0);
  nbsommet++;

}
