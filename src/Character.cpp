#include "Character.h"

Character::Character(void)
  : m_x(0), m_y(0)
{
}

Character::Character(int x, int y)
  : m_x(x), m_y(y)
{
}

void Character::move_left(void)
{
  if (m_x > 0) --m_x;
}

void Character::move_right(void)
{
  if (m_x < m_game.arduboy.width) ++m_x;
}

void Character::move_up(void)
{
  if (m_y > 0) --m_y;
}

void Character::move_down(void)
{
  if (m_y < m_game.arduboy.height) ++m_y;
}

void Character::change_state(const CharacterState state)
{
  m_state = state;
}