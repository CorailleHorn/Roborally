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



void card::playcard(){
  drawcard();//piocher 9 cartes
}
