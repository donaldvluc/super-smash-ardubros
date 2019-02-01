#pragma once

#include "GameContext.h"
#include "GameState.h"

#include "Character.h"

class Game
{
private:
  GameState m_state;
  GameContext m_context;

public:
  Arduboy arduboy;

  Game(void);

  void setup(void);
  void loop(void);

  void change_state(const GameState state);
};
