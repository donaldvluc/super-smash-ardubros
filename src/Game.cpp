#include "Game.h"

void Game::setup(void)
{
  auto & arduboy = this->m_context.arduboy

  this->m_current_state = create_state(GameStateType::StartScreen);
  this->m_current_state->start();
}

void Game::loop(void)
{
  auto & arduboy = this->m_context.arduboy;

  /* Pause render until it's time for the next frame. */
  if (!(arduboy.nextFrame())) return;

  /* Handle input from user. */
  handle_user_input(void);

  /* Update game state. */
  if (arduboy.pressed(A_BUTTON)) {
    arduboy.invert(true);
  } else if (arduboy.pressed(B_BUTTON)) {
    arduboy.invert(false);
  }

  arduboy.clear();

  /* Display to screen. */
  arduboy.display();


}

void Game::change_state(const GameState state)
{
  m_state = state;
}

void handle_user_input(void)
{
  auto & arduboy = this->m_context.arduboy;

  if (arduboy.pressed(UP_BUTTON)) {
    arduboy.print("UP BUTTON");
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    arduboy.print("DOWN BUTTON");
  } else if (arduboy.pressed(LEFT_BUTTON)) {
    arduboy.print("LEFT BUTTON");
  } else if (arduboy.pressed(RIGHT_BUTTON)) {
    arduboy.print("RIGHT BUTTON");
  }

}

void create_state()
{
  
}
