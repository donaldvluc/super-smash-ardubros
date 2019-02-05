#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameContext.h"
#include "GameStateType.h"

class Game
{
private:
  GameState* m_current_state;
  GameContext* m_context = new GameContext();

public:
  Arduboy arduboy;

  Game(void);
  ~Game(void);

  void setup(void);
  void menu_loop(void);
  void game_loop(void);

  void change_state(const GameState* state);
  GameState* create_state(const GameStateType state_type);
  bool handle_user_menu_input(void);
  void handle_user_game_input(void);

  void play_lifelight(void);
};


#endif
