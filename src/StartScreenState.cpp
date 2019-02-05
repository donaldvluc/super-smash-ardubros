#include "StartScreenState.h"

StartScreenState::StartScreenState(GameContext* context)
{
  m_context = context;
}

StartScreenState::~StartScreenState()
{
}

void StartScreenState::start(void)
{
  auto & arduboy = m_context->arduboy;

  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.setTextSize(1);
  arduboy.setCursor(0,0);
  arduboy.print("Super Smash Ardubros\nmade by the boys");
  arduboy.setCursor(0,40);
  arduboy.print("Press A to play or B\nfor the intro song");
  arduboy.display();
}
