// tilengine.h

#ifndef _TILENGINE_h
#define _TILENGINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"
#include "gameObject.h"

struct tilengine {
	tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight);
	~tilengine();	// Poista karttapuskuri kun sit‰ ei en‰‰ tarvita

	mapDataType * mapBuffer;       // Puskuri kartalle

	void assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));
	void loadMap(mapDataType * getMap);	// M‰‰rittele kartan koko ja tallennusmuoto

	void(*pointToTileDrawingFunction)(dataType, dataType);	// Hae osoitin piirtofunktioon

	bool checkTile(dataType getX, dataType getY);

	void drawMap();

	/* Ruutujen koko, m‰‰r‰ ja varaama muisti */
	dataType width;
	dataType height;
	dataType tileWidth;
	dataType tileheight;
	dataType tilecount;
	
	/* Erilaiset tˆrm‰ykset */
	bool COLLISION_BELOW(gameObject * obj);
	bool COLLISION_ABOVE(gameObject * obj);
	bool COLLISION_LEFT(gameObject * obj);
	bool COLLISION_RIGHT(gameObject * obj);
};

#endif

