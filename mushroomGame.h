// mushroomGame.h

#pragma once

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
#include "inputOutput.h"
#include "mushroomLevels.h"

struct mushroomGame {
	gameObject	player;				// Luo olio pelaajalle
	physics		playerPhysics;		// Luo fysiikkaolio pelaajan fysiikkojen laskemiseen
	tilengine * localEngine;		// Luo osoitin tile-enginelle
	inputOutput io;					// Luo olio näppäimiä hallitsevalle kirjastolle

	gameObject key;

	gameObject loadedObjects[2];

	dataType currentLevel = 0;

	void loadLevel(dataType levelToLoad);
	void loadObjects(dataType level);

	void handleLoadedObjects();

	bitmapDataType * getBitmapById(dataType id);

	void initialize(dataType width, dataType height);
	void assignBitmapDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y, bitmapDataType * bitmap, dataType width, dataType height));	// Hae osoitin piirtofunktioon
	void(*pointToBitmapDrawingFunction)(dataType, dataType, bitmapDataType *, dataType, dataType);	// Osoitin piirtofunktioon

	longDataType oldUpdateTime = 0;		// Milloin peli on viimeksi päivitetty
	longDataType oldMushroomUpdateTime = 0;

	mushroomGame(tilengine * engine);
	void run();		// Hoida piirtäminen, fysiikat ja muut tässä funktiossa
	void draw();
	void loadMap(mapDataType * m);
	void loadMap(const mapDataType * m);
};

#endif

