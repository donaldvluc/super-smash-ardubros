#ifndef START_SCREEN_STATE_H
#define START_SCREEN_STATE_H

#include "GameState.h"

class StartScreenState : public GameState
{
private:
public:
  StartScreenState(GameContext* context);
  ~StartScreenState(void);
  void start(void);
};

#endif
