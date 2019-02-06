/**
 * src.ino
 * Anthony Luc (aluc)
 * Donald Luc (dluc)
 * Michael Wang (mwang6)
 * January 20th, 2019
 */

#include "Arduboy.h"

/* Globals */
Arduboy arduboy;

/* Boundaries. */
int x = 0, y = 29;
int play = 0;

/* Sandbag variables. */
int bag_x = 85, bag_y = 29;

/* Percentage variables. */
int perc_x = 90, perc_y = 0;
int score = 0;

/*
 * Game and Watch Sprite Sheet
 */
 
const unsigned char PROGMEM neutral[] =
{
// Neutral 31 x 39
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x43, 0x43, 0x3, 0x7, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf8, 0x98, 0x1c, 0xc, 0xc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xc, 0xc, 0x1c, 0x98, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0xf, 0x1f, 0x1f, 0xcf, 0xf7, 0xf8, 0x7c, 0x3d, 0x1f, 0xf, 0xf, 0xf, 0xf, 0xf, 0x1f, 0x3d, 0x7c, 0xf8, 0xf7, 0xcf, 0x1f, 0x1f, 0xf, 0x7, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1c, 0x00
};

const unsigned char PROGMEM moving[] =
{
// Move 33 x 37
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x87, 0x9f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x43, 0x43, 0x3, 0x7, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x7, 0x7, 0x7, 0x3, 0x00, 0x1, 0x1, 0x3, 0x7, 0xf6, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0x18, 0x30, 0x30, 0x30, 0x30, 0x38, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x9c, 0xd, 0xf, 0x7, 0xf, 0xf, 0xf, 0xf, 0x7, 0xd, 0x1c, 0x38, 0xf0, 0xe0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x7, 0x7, 0xf, 0xf, 0xf, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6, 0xf, 0xf, 0xf, 0xf, 0x7, 0x7, 0x7, 0x3, 0x3, 0x1, 0x00
};

const unsigned char PROGMEM neutralA[] =
{
// Neutral B 59 x 39
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x43, 0x43, 0x3, 0x7, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x6e, 0x6f, 0x6f, 0x6f, 0xde, 0xdc, 0xd0, 0xd0, 0xd0, 0xe0, 0xf0, 0x60, 0x18, 0xf8, 0xf8, 0xfa, 0xfa, 0xfa, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x70, 0x20, 0x00, 0x00, 0x00, 0x10, 0x30, 0xb1, 0xff, 0xff, 0x43, 0x47, 0xe7, 0xee, 0xee, 0xfc, 0xfc, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0x7c, 0x3d, 0x1f, 0xf, 0xf, 0xf, 0xf, 0xe, 0x1e, 0x3c, 0x7c, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2, 0x7, 0xf, 0xf, 0x8, 0xc, 0x4, 0x6, 0x6, 0x3, 0x1, 0x00, 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM neutralB[] =
{
// Neutral B 58 x 37
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3f, 0x3f, 0x3f, 0x1e, 0xc, 0xc, 0xc, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0xc0, 0xc0, 0xc7, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x43, 0x43, 0x3, 0x7, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xe0, 0xc0, 0x60, 0x38, 0xff, 0xfc, 0xc0, 0x00, 0x00, 0x70, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xf0, 0xf0, 0x30, 0x18, 0x18, 0x18, 0x30, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0x1e, 0x3f, 0x3f, 0x3f, 0x1e, 0x00, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x00, 0x1f, 0x1f, 0x1f, 0x30, 0x30, 0x18, 0x1f, 0x7, 0x1, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x7, 0xf, 0xf, 0xf, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x87, 0xdf, 0xfd, 0xf0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM downA[] =
{
// Down A 57 x 38
0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7c, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0x1f, 0x1f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xe1, 0xe1, 0xe0, 0x90, 0xc1, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0xb8, 0xb8, 0xbc, 0x7e, 0x7e, 0x7e, 0xbe, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf2, 0x3, 0x1, 0x1, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xe0, 0xf8, 0xfc, 0x3e, 0x1e, 0xf, 0x7, 0x7, 0x7, 0x7, 0x7, 0xf, 0x1e, 0x3e, 0xfc, 0xf8, 0xe0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0x60, 0x70, 0x20, 0x00, 0x00, 0xe, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8, 0x1c, 0xc, 0xe, 0x6, 0x6, 0x7, 0x3, 0x3, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM aerialA[] =
{
// Down A 65 x 39
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3f, 0x3f, 0x3f, 0x1e, 0xc, 0xc, 0xc, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0xc0, 0xc0, 0xc7, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x43, 0x43, 0x3, 0x7, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xf0, 0xf0, 0x30, 0x18, 0x18, 0x18, 0x30, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0x1e, 0x3f, 0x3f, 0x3f, 0x1e, 0x20, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0x70, 0xe0, 0xe0, 0xf0, 0xf8, 0xd8, 0x88, 0xd8, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x7, 0xf, 0xf, 0xf, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xe1, 0xe7, 0xff, 0xfd, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8, 0x00, 0x7, 0x3e, 0x3d, 0x1d, 0xd, 0xb, 0x1b, 0x1b, 0x3b, 0x5d, 0xd, 0x1d, 0x3d, 0x7d, 0x44, 0x00, 0x1, 0x1, 0x3, 0x3, 0xf, 0x1f, 0x1d, 0x8, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x7, 0xf, 0x1f, 0x1f, 0x3f, 0x3f, 0x3e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM sandbag[] =
{
// Sandbag 17 x 41
0xfc, 0xfe, 0x16, 0x77, 0xe3, 0xe3, 0x23, 0x23, 0x23, 0x23, 0x23, 0xe3, 0xe3, 0x77, 0xf6, 0xfe, 0xfc, 0xff, 0xff, 0xe8, 0x70, 0x00, 0x00, 0x70, 0xe8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM sandbag_hit[] =
{
// Sandbag 24 x 41
0xf0, 0xf8, 0x98, 0x9c, 0x8c, 0x8e, 0xc6, 0xc6, 0x27, 0x23, 0x23, 0x33, 0x73, 0x73, 0xf, 0x3f, 0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x7, 0x1f, 0xff, 0xff, 0xf9, 0xb1, 0xc0, 0x80, 0x00, 0x18, 0x28, 0x70, 0x60, 0x00, 0x00, 0x3, 0x1f, 0x7f, 0xfe, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x1f, 0xff, 0xff, 0x31, 0x58, 0x14, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00
};

void redraw()
{
  arduboy.clear();
  arduboy.invert(true);
  arduboy.setCursor(x,y);
  
  // Sandbag
  arduboy.drawBitmap(bag_x, bag_y, sandbag, 17, 41, WHITE);
  
  // Damage
  arduboy.setTextSize(2);
  arduboy.setCursor(perc_x,perc_y);
  arduboy.print(score);
}

void hit(int hit)
{
  arduboy.clear();
  arduboy.invert(true);
  arduboy.setCursor(x,y);
  arduboy.drawBitmap(x, y, neutral, 31, 39, WHITE);

  // Increase Damage
  score += hit;
  arduboy.setTextSize(2);
  arduboy.setCursor(perc_x,perc_y);
  arduboy.print(score);

  // Draw Hit animation
  arduboy.tunes.tone(550, 50);
  arduboy.drawBitmap(bag_x, bag_y, sandbag_hit, 24, 41, WHITE);
  arduboy.display();
  delay(100);
  redraw();
}

void setup()
{
  arduboy.begin();
  arduboy.setTextSize(1);
  arduboy.setCursor(0,0);
  arduboy.print("SuperSmash\nArduBros\n\nA:Game\nB:Song");
  arduboy.display();
}

void loop ()
{
  while (play == 0) {
    if (!(arduboy.nextFrame()))
      return;
      
    arduboy.clear();
    arduboy.setCursor(x,y);
    arduboy.print("SuperSmash\nArduBros\nA:Song\nB:Game");
    arduboy.display();
    
    if (arduboy.pressed(B_BUTTON)) {
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
    else if (arduboy.pressed(A_BUTTON)) {
      play = 1;
    }
  }

  /* GAME */
  if (!(arduboy.nextFrame()))
      return;
    
  if (arduboy.pressed(UP_BUTTON) && y > 0) {
    int i = 5;
    // Go up
    while (i > 0) {
      y-=5;
      delay(50);
      redraw();
      arduboy.drawBitmap(x, y, neutral, 31, 39, WHITE);
      arduboy.display();
      i-=1;
      if (arduboy.pressed(A_BUTTON)) {
        redraw();
        arduboy.drawBitmap(x, y, neutralA, 59, 39, WHITE);
        arduboy.display();
        // hit detection
        if (x >= 28) {
          delay(30);
          hit(9);
        }
      }
    }
    // Go down
    while (i < 5) {
      y+=5;
      delay(50);
      redraw();
      arduboy.drawBitmap(x, y, neutral, 31, 39, WHITE);
      arduboy.display();
      i+=1;
      if (arduboy.pressed(A_BUTTON)) {
        redraw();
        arduboy.drawBitmap(x, y, neutralA, 59, 39, WHITE);
        arduboy.display();
        // hit detection
        if (x >= 28) {
          delay(30);
          hit(9);
        }
      }
    }
  } else if (arduboy.pressed(DOWN_BUTTON) && y < 30) {
    //down A code
    int i = 0;
    while (i < 5) {
      delay(50);
      if (arduboy.pressed(A_BUTTON)) {
        redraw();
        arduboy.drawBitmap(x, y, downA, 57, 38, WHITE);
        arduboy.display();
        // hit detection
        if (x >= 29) {
          delay(100);
          hit(11);
        }
        delay(400);
      }
      i+=1;
    }
  } else if (arduboy.pressed(LEFT_BUTTON) && x > 0) {
    x-=1;
    redraw();
    arduboy.drawBitmap(x, y, moving, 33, 37, WHITE);
    arduboy.display();
    delay(20);
  } else if (arduboy.pressed(RIGHT_BUTTON) && x < 96) {
    x+=1;
    redraw();
    arduboy.drawBitmap(x, y, moving, 33, 37, WHITE);
    arduboy.display();
    delay(20);
  }

  if (arduboy.pressed(A_BUTTON)) {
    redraw();
    arduboy.drawBitmap(x, y, neutralA, 59, 39, WHITE);
    arduboy.display();
    // hit detection
    if (x >= 28) {
      delay(100);
      hit(8);
    }
    delay(300);
  }
  else if (arduboy.pressed(B_BUTTON)) {
    redraw();
    arduboy.drawBitmap(x, y, neutralB, 58, 37, WHITE);
    arduboy.display();
    // hit detection
    if (x >= 29) {
      delay(100);
      hit(15);
    }
    delay(300);
  }

  // Character
  arduboy.clear();
  arduboy.invert(true);
  arduboy.setCursor(x,y);
  arduboy.drawBitmap(x, y, neutral, 31, 39, WHITE);

  // Sandbag
  arduboy.drawBitmap(bag_x, bag_y, sandbag, 17, 41, WHITE);
  
  // Damage
  arduboy.setTextSize(2);
  arduboy.setCursor(perc_x,perc_y);
  arduboy.print(score);
  arduboy.display();
//  if (score >= 100) {
//    arduboy.setTextSize(3);
//    arduboy.setCursor(0,0);
//    arduboy.print("YOU WIN");
//    arduboy.display();
//  }
}

