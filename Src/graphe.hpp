#ifndef ROBORALLY_GRAPHE_HPP_
#define ROBORALLY_GRAPHE_HPP_

#include <vector>
#include <iostream>
#include "board.hpp"
using namespace RR;

struct Noeud {
  RR::Robot info;
  std::vector<Noeud*> linked;
  int indice;

  void setValues(const Robot& rbt, const int& ind);
  void addLink(Noeud* n);
  bool equalTo(const Robot& rbt) const;
  void display(const bool& withLinks) const;
};

class Graphe {
public:

  Graphe(const Robot& d, const Board& board, const Location& a);
  void construitGraphe(const Board& board, const bool& verbose);
  int existeDeja(const Robot& rbt) const;

  void pluscourtChemin();
  ~Graphe();

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
  std::vector<Robot::Status> positions = {
        Robot::Status::NORTH,
        Robot::Status::SOUTH,
        Robot::Status::EAST,
        Robot::Status::WEST
  };

  int nbsommet = 0;
  std::vector<Noeud*> noeuds;
  Noeud* detruit;

  Robot depart;
  Location arrivee;
};
void afficheMouvement(const int& indice);


#endif
