#include "Game.h"

#include "StartScreenState.h"

Game::Game(void)
{
}

Game::~Game(void)
{  
}

void Game::setup(void)
{
  auto & arduboy = m_context->arduboy;

  this->m_current_state = create_state(GameStateType::StartScreen);
  this->m_current_state->start();
}

void Game::menu_loop(void)
{
  auto & arduboy = m_context->arduboy;

  bool continue_loop = true;
  while(continue_loop)
  {
    /* Pause render until it's time for the next frame. */
    if (!arduboy.nextFrame()) return;

    /* Handle input from user. */
    handle_user_menu_input(continue_loop);
  }
}

void Game::game_loop(void)
{
  this->m_current_state = create_state(GameStateType::Gameplay);
  this->m_current_state->start();

  auto & arduboy = m_context->arduboy;

  while(true)
  {
    /* Pause render until it's time for the next frame. */
    if (!arduboy.nextFrame()) return;

    /* Handle input from user. */
//    bool continue_loop = handle_user_game_input();
//    if (continue_loop == false)
//      break;

    /* Display to screen. */
    arduboy.display();
  }
}

void Game::change_state(const GameState* state)
{
  m_current_state = state;
}

GameState* Game::create_state(const GameStateType state_type)
{
  switch(state_type)
  {
    case GameStateType::StartScreen: return new StartScreenState(m_context);
    default: return nullptr; 
  }
}

void Game::handle_user_menu_input(bool &continue_loop)
{
  auto & arduboy = m_context->arduboy;

  if (arduboy.pressed(A_BUTTON)) {
    continue_loop = false;
  } else if (arduboy.pressed(B_BUTTON)) {
    continue_loop = true;
//    play_lifelight();
    arduboy.clear();
    arduboy.print("B pressed");
    arduboy.display();
  }
}

void Game::handle_user_game_input(void)
{
  auto & arduboy = m_context->arduboy;

//  if (arduboy.pressed(UP_BUTTON)) {
//    arduboy.print("UP BUTTON");
//  } else if (arduboy.pressed(DOWN_BUTTON)) {
//    arduboy.print("DOWN BUTTON");
//  } else if (arduboy.pressed(LEFT_BUTTON)) {
//    arduboy.print("LEFT BUTTON");
//  } else if (arduboy.pressed(RIGHT_BUTTON)) {
//    arduboy.print("RIGHT BUTTON");
//  }

}

void Game::play_lifelight(void)
{
  auto & arduboy = m_context->arduboy;

  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print("Playing theme song: Lifelight");
  arduboy.display();

  arduboy.tunes.tone(329, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(369, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(391, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(329, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(391, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(587, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(554, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(493, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(554, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(659, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(523, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(493, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(440, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(391, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(440, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(493, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(440, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(391, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(440, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(369, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(440, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(587, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(659, 10.0446328125);
  delay(11.160703125);
  arduboy.tunes.tone(783, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(880, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(739, 482.142375);
  delay(535.71375);
  arduboy.tunes.tone(659, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(739, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(783, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(880, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(987, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(783, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(880, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(739, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(659, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(587, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(659, 1285.713);
  delay(1428.57);
  arduboy.tunes.tone(783, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(880, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(739, 482.142375);
  delay(535.71375);
  arduboy.tunes.tone(659, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(739, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(783, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(880, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(987, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(739, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(587, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(659, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(659, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(739, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(783, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(1174, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(987, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(880, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(880, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(880, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(783, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(698, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(783, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(587, 642.8565);
  delay(714.285);
  arduboy.tunes.tone(987, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(987, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(987, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(987, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(783, 241.0711875);
  delay(267.856875);
  arduboy.tunes.tone(659, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(587, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(523, 482.142375);
  delay(535.71375);
  arduboy.tunes.tone(523, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(493, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(523, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(440, 482.142375);
  delay(535.71375);
  arduboy.tunes.tone(880, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(880, 80.3570625);
  delay(89.285625);
  arduboy.tunes.tone(880, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(659, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(622, 562.4994375);
  delay(624.999375);
  delay(89.285625);
  arduboy.tunes.tone(739, 321.42825);
  delay(357.1425);
  arduboy.tunes.tone(1046, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(987, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 723.2135625);
  delay(803.570625);
  delay(89.285625);
  arduboy.tunes.tone(659, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(880, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(987, 160.714125);
  delay(178.57125);
  arduboy.tunes.tone(987, 1285.713);
  delay(1428.57);
}
