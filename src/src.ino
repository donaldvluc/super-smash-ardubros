/**
 * src.ino
 * Anthony Luc (aluc)
 * Donald Luc (dluc)
 * Michael Wang (mwang6)
 * January 20th, 2019
 */

#include "Arduboy.h"

Arduboy arduboy;

void setup()
{
  arduboy.begin();
  arduboy.setTextSize(4);
  arduboy.setCursor(0,0);
  arduboy.print("Music\nDemo");
  arduboy.display();
}


int x = 0, y = 0;

void loop ()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  if (arduboy.pressed(UP_BUTTON)) {
    y-=1;
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    y+=1;
  } else if (arduboy.pressed(LEFT_BUTTON)) {
    x-=1;
  } else if (arduboy.pressed(RIGHT_BUTTON)) {
    x+=1;
  }

  if (arduboy.pressed(A_BUTTON)) {
    arduboy.invert(true);
  } else if (arduboy.pressed(B_BUTTON)) {
    arduboy.invert(false);
  }

  arduboy.clear();
  arduboy.setCursor(x,y);
  arduboy.print("Music\nDemo");
  arduboy.display();

  
  // play the tune if we aren't already
  if (!arduboy.tunes.playing()) {
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
  }
}
