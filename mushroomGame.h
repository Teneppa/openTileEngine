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
#include "bitmaps.h"

struct mushroomGame {
	gameObject player;				// Luo olio pelaajalle
	tilengine * localEngine;		// Luo osoitin tile-enginelle

	void initialize(dataType width, dataType height);
	void assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));	// Hae osoitin piirtofunktioon
	void(*pointToPlayerDrawingFunction)(dataType, dataType);	// Osoitin piirtofunktioon

	mushroomGame(tilengine * engine);
	void draw();
	void loadMap(mapDataType * m);
};

#endif

