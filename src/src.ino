/*
Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include "Arduboy2.h"
#include <ArduboyTones.h>

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

const uint16_t score[] PROGMEM = {
 NOTE_G5,100, NOTE_C5,160, NOTE_REST,283, NOTE_G5,4, NOTE_G5,595, NOTE_G5,11, NOTE_REST,1788, NOTE_G5,35,
 NOTE_G5,864, NOTE_G5,16, NOTE_REST,283, NOTE_G5,4, NOTE_G5,595, NOTE_G5,11, NOTE_REST,588, NOTE_B4,600,
 NOTE_A4,508, NOTE_A4,91, NOTE_G4,1200, NOTE_G4,600, NOTE_G4,11, NOTE_G4,1188, NOTE_G4,600, NOTE_C5,35,
 NOTE_C5,1164, NOTE_C5,600, NOTE_C5,11, NOTE_C5,1696, NOTE_C5,91, NOTE_F4,1200, NOTE_F4,600, NOTE_F4,11,
 NOTE_F4,888, NOTE_F4,16, NOTE_F4,283, NOTE_F4,4, NOTE_F4,595, NOTE_C5,11, NOTE_C5,888, NOTE_C5,16,
 NOTE_C5,283, NOTE_C5,4, NOTE_C5,595, NOTE_C5,11, NOTE_C5,1696, NOTE_C5,91, NOTE_F4,1200, NOTE_F4,600,
 NOTE_F4,11, NOTE_F4,888, NOTE_F4,16, NOTE_F4,283, NOTE_F4,4, NOTE_F4,595, NOTE_C5,11, NOTE_C5,888,
 NOTE_C5,16, NOTE_C5,283, NOTE_C5,4, NOTE_C5,595, NOTE_C5,11, NOTE_C5,588, NOTE_B4,600, NOTE_A4,508,
 NOTE_A4,91, NOTE_G4,1200, NOTE_G4,600, NOTE_G4,11, NOTE_G4,588, NOTE_G4,11, NOTE_G4,588, NOTE_G4,11,
 NOTE_G4,588, NOTE_C5,11, NOTE_C5,1788, NOTE_C5,35, NOTE_C5,1673, NOTE_C5,91, NOTE_C5,600, NOTE_C5,11,
 NOTE_C5,588, NOTE_C5,11, NOTE_C5,588, NOTE_G4,11, NOTE_G4,888, NOTE_G4,16, NOTE_G4,283, NOTE_G4,4,
 NOTE_G4,595, NOTE_C5,11, NOTE_C5,1696, NOTE_REST,91,
 TONES_END
};


// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  arduboy.clear();

  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0) 
  arduboy.setCursor(4, 9);

  // then we print to screen what is in the Quotation marks ""
  arduboy.print(F("Hello, world!"));

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();

  sound.tones(score);

}
