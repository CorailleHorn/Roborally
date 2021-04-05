#include "graphe.hpp"
#include <vector>
#include "board.hpp"

// ------------- Struct Noeud ------------- //

void Noeud::setValues(const RR::Robot& rbt) {
  rbt.location = init.location;
  rbt.satus = init.status;
}

void Noeud::addLink(const Noeud& n) {
  linked.push_back(n);
}


// ------------- Classe Graphe ------------- //

void Graphe::initGraphe(const RR::Robot& rbt) {
  Noeud n0;
  n0.setValues(rbt);
  noeuds.assign(n0);
  nbsommet++;
}
