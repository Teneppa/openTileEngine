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

struct mushroomGame {

	gameObject * player;
	tilengine * localEngine;

	void initialize(dataType width, dataType height, bitmapDataType * bitmap);

	mushroomGame(tilengine * engine);
	void draw();
	void loadMap(mapDataType * m);
};

#endif

