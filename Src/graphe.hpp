#ifndef ROBORALLY_GRAPHE_HPP_
#define ROBORALLY_GRAPHE_HPP_

#include <vector>
#include "board.hpp"
using namespace RR;

struct Noeud {
  RR::Robot info;
  std::vector<Noeud*> linked;

  void setValues(const Robot& rbt);
  void addLink(Noeud* n);
};

class Graphe {
public:

  Graphe(const Robot& rbt, const Board& board);
  void construitGraphe(const Robot& rbt, const Board& board);
  //~Graphe();

private:
  std::vector<Robot::Move> moves = {
        Robot::Move::FORWARD_1,
        Robot::Move::FORWARD_2,
        Robot::Move::FORWARD_3,
        Robot::Move::BACKWARD_1,
        Robot::Move::TURN_LEFT,
        Robot::Move::TURN_RIGHT,
        Robot::Move::U_TURN
      };
  int nbsommet = 0;
  std::vector<Noeud*> noeuds;
  Noeud* detruit;
};


#endif
