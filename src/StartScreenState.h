#pragma once

#include "GameContext.h"

class StartScreenState
{
private:
  GameContext m_context;

public:
  StartScreenState(GameContext context);
  void start(void);
}