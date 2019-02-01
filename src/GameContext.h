#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

// Idea: maybe use to handle game camera and following across stage/map

#include <Arduboy.h>

class GameContext
{
private:
  const static int m_w = 10;
  const static int m_h = 10;
public:
  Arduboy arduboy;
  GameContext(void);
  ~GameContext(void);
};

#endif
