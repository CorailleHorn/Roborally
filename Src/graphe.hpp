#ifndef ROBORALLY_GRAPHE_HPP_
#define ROBORALLY_GRAPHE_HPP_

#include <vector>
#include "board.hpp"

struct Noeud {
  RR::Robot rbt;
  std::vector<Noeud*> linked;
};

class Graphe {
public:

  void initGraphe(RR::Robot init, RR::Board* board);
  ~Graphe();

private:
  int nbsommet = 0;
  std::vector<Noeud*> noeuds;
};


#endif
