#ifndef PROJET_CARDS_HPP
#define PROJET_CARDS_HPP

#include "board.hpp"

#include <random>
#include <vector>

class card {
public:
  card(); //constructeur
  int getcard(); //prendre une carte au hasard
  void drawcard(); //le robot prend 9 cartes au hasard
  std::vector<RR::Robot::move)> get9cards(); //afficher les 9 cartes piochées
  int playcard(std::vector<RR::Robot::move> cards); //ajouter les 5 cartes jouer par le robots
  std::vector<RR::Robot::move)> getchosencards();//afficher les 5 cartes choisis par le robot
  void shuffle(); //melanger les cartes
private:
  const std::vector<RR::Robot::Move> moves = {
        Robot::Move::FORWARD_1,
        Robot::Move::FORWARD_2,
        Robot::Move::FORWARD_3,
        Robot::Move::BACKWARD_1,
        Robot::Move::TURN_LEFT,
        Robot::Move::TURN_RIGHT,
        Robot::Move::U_TURN
    };
    std::vector<RR::Robot::Move> draw; //tableau de 9 cartes
    std::vector<RR::Robot::Move> play; //tableau de 5 cartes


}

#endif //PROJET_CARDS_HPP
