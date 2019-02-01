#ifndef GAME_H
#define GAME_H


#include "GameContext.h"
#include "GameState.h"
#include "GameStateType.h"

#include "StartScreenState.h"

class Game
{
private:
  GameState* m_current_state;
  GameContext* m_context;

public:
  Arduboy arduboy;

  Game(void);
  ~Game(void);

  void setup(void);
  void loop(void);

  void change_state(const GameState* state);
  GameState* create_state(const GameStateType state_type);
  void handle_user_input(void);
};


#endif
