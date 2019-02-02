/**
 * src.ino
 * Anthony Luc (aluc)
 * Donald Luc (dluc)
 * Michael Wang (mwang6)
 * January 20th, 2019
 */

/* Includes */

#include "Arduboy.h"

/* Globals */

Arduboy arduboy;


/*
 * Game and Watch Sprite Sheet
 */

const unsigned char PROGMEM neutral[] =
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x7, 0x3, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x3, 0x7, 0x1f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc, 0x9e, 0xde, 0xde, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x7, 0x3, 0x33, 0x71, 0xf9, 0xf9, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0xf9, 0xf9, 0x71, 0x33, 0x3, 0x7, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7c, 0x78, 0x70, 0x70, 0x18, 0x4, 0x3, 0xc1, 0xe1, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe1, 0xc1, 0x3, 0x4, 0x18, 0x70, 0x70, 0x78, 0x7c, 0xff, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
};

void setup()
{
  arduboy.begin();
  arduboy.clear();
  arduboy.setTextSize(1);
  arduboy.setCursor(0,0);
  arduboy.print("SuperSmash\nArduBros\nA:Song\nB:Game");
  arduboy.display();
}

int x = 0;
int y = 0;

void loop ()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // Test Sprite
  arduboy.clear();
  arduboy.drawBitmap(x, y, neutral, 29, 37, WHITE);
  arduboy.display();
  

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
//  if (!arduboy.tunes.playing()) {
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(523, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(440, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(440, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(493, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(440, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(440, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(440, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 10.0446328125);
//    delay(11.160703125);
//    arduboy.tunes.tone(783, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(880, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(739, 482.142375);
//    delay(535.71375);
//    arduboy.tunes.tone(659, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(739, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(783, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(880, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(987, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(783, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(880, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(739, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(659, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 1285.713);
//    delay(1428.57);
//    arduboy.tunes.tone(783, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(880, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(739, 482.142375);
//    delay(535.71375);
//    arduboy.tunes.tone(659, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(739, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(783, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(880, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(987, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(739, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(659, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(739, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(783, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(1174, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(987, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(880, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(880, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(880, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(783, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(698, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(783, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(987, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(987, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(987, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(987, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(783, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(659, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(523, 482.142375);
//    delay(535.71375);
//    arduboy.tunes.tone(523, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(493, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(523, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(440, 482.142375);
//    delay(535.71375);
//    arduboy.tunes.tone(880, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(880, 80.3570625);
//    delay(89.285625);
//    arduboy.tunes.tone(880, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(659, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(622, 562.4994375);
//    delay(624.999375);
//    delay(89.285625);
//    arduboy.tunes.tone(739, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(1046, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(987, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 723.2135625);
//    delay(803.570625);
//    delay(89.285625);
//    arduboy.tunes.tone(659, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(880, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(987, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(987, 1285.713);
//    delay(1428.57);
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//    arduboy.tunes.tone(329, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(369, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(391, 321.42825);
//    delay(357.1425);
//    arduboy.tunes.tone(329, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(391, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(587, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(554, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(493, 241.0711875);
//    delay(267.856875);
//    arduboy.tunes.tone(554, 160.714125);
//    delay(178.57125);
//    arduboy.tunes.tone(659, 642.8565);
//    delay(714.285);
//  }
}
