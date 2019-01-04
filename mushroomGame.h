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
#include "physics.h"

struct mushroomGame {
	gameObject	player;				// Luo olio pelaajalle
	physics		playerPhysics;		// Luo fysiikkaolio pelaajan fysiikkojen laskemiseen
	tilengine * localEngine;		// Luo osoitin tile-enginelle

	void initialize(dataType width, dataType height);
	void assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));	// Hae osoitin piirtofunktioon
	void(*pointToPlayerDrawingFunction)(dataType, dataType);	// Osoitin piirtofunktioon

	longDataType oldUpdateTime = 0;		// Milloin peli on viimeksi päivitetty
	longDataType oldMushroomUpdateTime = 0;

	mushroomGame(tilengine * engine);
	void run();		// Hoida piirtäminen, fysiikat ja muut tässä funktiossa
	void draw();
	void loadMap(mapDataType * m);
};

#endif

