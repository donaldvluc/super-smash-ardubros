#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameContext.h"
#include "GameStateType.h"

/*
 * Game and Watch Sprite Sheet
 */

const unsigned char PROGMEM neutral[] =
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x7, 0x3, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x3, 0x7, 0x1f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc, 0x9e, 0xde, 0xde, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x7, 0x3, 0x33, 0x71, 0xf9, 0xf9, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0xf9, 0xf9, 0x71, 0x33, 0x3, 0x7, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7c, 0x78, 0x70, 0x70, 0x18, 0x4, 0x3, 0xc1, 0xe1, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe1, 0xc1, 0x3, 0x4, 0x18, 0x70, 0x70, 0x78, 0x7c, 0xff, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
};

class Game
{
private:
  GameState* m_current_state;
  GameContext* m_context = new GameContext();

public:
  Arduboy arduboy;
  Sprite sprite;

  Game(void);
  ~Game(void);

  void setup(void);
  void loop(void);

  void change_state(const GameState* state);
  GameState* create_state(const GameStateType state_type);
  void handle_user_input(void);
};


#endif