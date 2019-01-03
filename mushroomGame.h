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

struct mushroomGame {

	gameObject * player;

	void initialize(dataType width, dataType height, bitmapDataType * bitmap);

	mushroomGame();
	void draw(tilengine &engine);
	void loadMap(uint16_t * map);
};

#endif

