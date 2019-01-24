/**
 * src.ino
 * Anthony Luc (aluc)
 * Donald Luc (dluc)
 * Michael Wang (mwang6)
 * January 20th, 2019
 */

#include "Game.h"

Arduboy arduboy;

void setup()
{
  game.setup();
}

void loop()
{
  game.loop();
}