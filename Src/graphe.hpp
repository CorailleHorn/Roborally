#ifndef ROBORALLY_GRAPHE_HPP_
#define ROBORALLY_GRAPHE_HPP_

#include <vector>
#include "board.hpp"

struct Noeud {
  RR::Robot rbt;
  std::vector<Noeud*> linked;

  void setValues(const RR::Robot& rbt);
  void addLink(const Noeud& n);
};

class Graphe {
public:

  void initGraphe(const RR::Robot& rbt);
  void construitGraphe(RR::Robot& rbt, RR::Board* board);
  ~Graphe();

private:
  int nbsommet = 0;
  std::vector<Noeud*> noeuds;
};


#endif
