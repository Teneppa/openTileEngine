#pragma once

#ifndef _BITMAPS_h
#define _BITMAPS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Mushroom player 8x8
bitmapDataType PROGMEM bitmap_mushroom[] = {
  0x3C, 0x5A, 0x5A, 0xFF, 0x24, 0x24, 0x24, 0x66,
};

// Wall block 8x8
const unsigned char PROGMEM bitmap_block[] = {
  0xFF, 0xC3, 0x81, 0x99, 0x99, 0x81, 0xC3, 0xFF,
};

#endif