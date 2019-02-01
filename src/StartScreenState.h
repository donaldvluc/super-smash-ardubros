#ifndef START_SCREEN_STATE_H
#define START_SCREEN_STATE_H

#include "GameContext.h"
#include "GameState.h"

class StartScreenState : public GameState
{
private:
  GameContext m_context;

public:
  StartScreenState(GameContext context);
  ~StartScreenState(void);
  void start(void);
};

#endif
