/**
 * src.ino
 * Anthony Luc (aluc)
 * Donald Luc (dluc)
 * Michael Wang (mwang6)
 * January 20th, 2019
 */

#include "Game.h"

Game game;

void setup()
{
  game.setup();
}

void loop()
{
  game.menu_loop();
//  game.game_loop();
}
