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
	inputOutput io;					// Luo olio n�pp�imi� hallitsevalle kirjastolle

	gameObject key;

	dataType currentLevel = 0;

	void loadLevel(dataType levelToLoad);

	void initialize(dataType width, dataType height);
	void assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));	// Hae osoitin piirtofunktioon
	void(*pointToPlayerDrawingFunction)(dataType, dataType);	// Osoitin piirtofunktioon

	void assignKeyDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));	// Hae osoitin piirtofunktioon
	void(*pointToKeyDrawingFunction)(dataType, dataType);	// Osoitin piirtofunktioon

	longDataType oldUpdateTime = 0;		// Milloin peli on viimeksi p�ivitetty
	longDataType oldMushroomUpdateTime = 0;

	mushroomGame(tilengine * engine);
	void run();		// Hoida piirt�minen, fysiikat ja muut t�ss� funktiossa
	void draw();
	void loadMap(mapDataType * m);
	void loadMap(const mapDataType * m);
};

#endif

