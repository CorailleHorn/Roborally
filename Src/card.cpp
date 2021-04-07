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
  std::cout <<std::endl;
}



void card::playcard(const Robot& d, const Board& board, const Location& a){
  drawcard();//piocher 9 cartes
  Graphe g(d, a);
  g.construitGraphe(board, false);
  std::vector<int> solutions = g.pluscourtChemin(draw);
  if(solutions.size() <= 5) {
    for(int j = solutions.size() - 1; j > -1; j--) {
      afficheMouvement(solutions[j]);
    }
  }
  else {
    std::cout << "Pas de solutions trouvé pour le tirage actuel"<< std::endl;
  }

}
