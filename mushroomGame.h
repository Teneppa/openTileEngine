// mushroomGame.h

#ifndef _MUSHROOMGAME_h
#define _MUSHROOMGAME_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "tilengine.h"
#include "variableType.h"
#include "gameObject.h"

/*
uint16_t mushMap[8] = {
	0b1111111111111111,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000001000101,
	0b1000000011000001,
	0b1111111111111111
};
*/

// Mushroom player 8x8
const unsigned char PROGMEM mushroom[] = {
  0x3C, 0x5A, 0x5A, 0xFF, 0x24, 0x24, 0x24, 0x66,
};

gameObject player(8, 8, mushroom);

struct mushroomGame {
	mushroomGame();
	void draw(tilengine &engine);
	void loadMap(uint16_t * map);
};

#endif

