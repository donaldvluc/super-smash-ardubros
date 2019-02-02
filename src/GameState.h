#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameContext.h"

class GameState
{
private:
public:
  virtual void start(void);
protected:
  GameContext* m_context;
};

#endif
