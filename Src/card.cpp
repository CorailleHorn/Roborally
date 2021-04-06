#include "card.hpp"
#include "board.hpp"
#include "graphe.hpp"

#include <iostream>
#include <random>
#include <vector>
using namespace RR;

card::card() {
}

int card::getcard(){

  return rand()% 6 + 0;
}

void card::drawcard(){
  srand(time(0));
  int carte;
  for(int i=0;i<9;i++)
  {
    carte=getcard();
    draw.push_back(carte);
  }
  std::cout<<"les cartes piochées :"<<std::endl;
  for(int i=0;i<9;i++)
  {
    afficheMouvement(draw[i]);
  }
}



void card::playcard(std::vector<Robot::Move> cards){
  if(cards.size()>5)
  {
    shuffle();
  }
  //else
  //{
    //while(not(Robot(Location(5,4), Robot::Status::EAST))){
      //play.push_back();
    //}
  //}
}

std::vector<Robot::Move> card::getchosencards(){
  return play;
}

void card::shuffle(){
  start->info.location = Location(0,1);
  drawcard();
}
