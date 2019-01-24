#pragma once

#include "Arduboy.h"

class Character
{
private:
  Game *m_game;
  CharacterState *m_state;
  int m_x;
  int m_y;

public:
  Character(void);
  Character(int x, int y);

  void move_left(void);
  void move_right(void);
  void move_up(void);
  void move_down(void);

  void change_state(const CharacterState state) override;
}

