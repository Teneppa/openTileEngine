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

#endif