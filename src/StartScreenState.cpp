#include "StartScreenState.h"

StartScreenState::StartScreenState(GameContext context)
{
  m_context = context;
}

void StartScreenState::start(void)
{
  auto & arduboy = m_context.arduboy;

  arduboy.begin();
  arduby.setFrameRate(60);
  arduboy.clear();
  arduboy.setTextSize(4);
  arduboy.setCursor(0,0);
  arduboy.print("Super\nSmash\nArdubros");
  arduboy.display();
}