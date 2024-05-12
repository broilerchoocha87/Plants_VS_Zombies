# pragma once

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    int choice;
    
    Player();
    
private:
    int gameState;/*Menu=0, l1=1,l2=2......*/
    int score;
    void setGameState(int state) {
    gameState = state;
  }

  int getGameState() const {
    return gameState;
  }

  void setScore(int newScore) {
    score = newScore;
  }

  int getScore() const {
    return score;
  }
};




#endif