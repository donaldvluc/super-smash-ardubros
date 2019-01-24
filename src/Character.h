#pragma once


class Character
{
private:
  State *m_state;
  int m_xpos;
  int m_ypos;

public:
  void move_left(void);
  void move_right(void);
  void move_up(void);
  void move_down(void);

  void change_state(const State state) override;
}