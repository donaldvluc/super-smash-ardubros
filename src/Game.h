#pragma once

#include "Character.h"

class Game
{
private:
  GameState *m_state;

public:
  Arduboy arduboy;

  Game(void);

  void setup(void);
  void loop(void);

  void change_state(const GameState state) override;
}

