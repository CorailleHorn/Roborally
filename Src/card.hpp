#ifndef PROJET_CARDS_HPP
#define PROJET_CARDS_HPP

#include "board.hpp"
#include "graphe.hpp"
#include <string>
#include <random>
#include <vector>
using namespace RR;

class card {

public:
  card(); //constructeur
  int getcard(); //prendre une carte au hasard
  void drawcard(); //le robot prend 9 cartes au hasard
  void playcard(); //ajouter les 5 cartes jouer par le robots
  void shuffle(); //melanger les cartes
private:
  Noeud* start;
  const std::vector<Robot::Move> moves = {
        Robot::Move::FORWARD_1,
        Robot::Move::FORWARD_2,
        Robot::Move::FORWARD_3,
        Robot::Move::BACKWARD_1,
        Robot::Move::TURN_LEFT,
        Robot::Move::TURN_RIGHT,
        Robot::Move::U_TURN
    };
    std::vector<int> draw; //tableau de 9 cartes
    std::vector<Robot::Move> play; //tableau de 5 cartes


};

#endif
