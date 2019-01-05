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
	tilengine(bitmapDataType * getTileBitmap, dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight);
	~tilengine();	// Poista karttapuskuri kun sit‰ ei en‰‰ tarvita

	mapDataType * mapBuffer;       // Puskuri kartalle

	void assignBitmapDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y, bitmapDataType * bitmap, dataType width, dataType height));
	void loadMap(const mapDataType *getMap);	// M‰‰rittele kartan koko ja tallennusmuoto

	void(*pointToBitmapDrawingFunction)(dataType, dataType, bitmapDataType *, dataType, dataType);	// Hae osoitin piirtofunktioon
	bool checkTile(dataType getX, dataType getY);

	bitmapDataType * tileBitmap;

	void drawMap();

	/* Ruutujen koko, m‰‰r‰ ja varaama muisti */
	dataType width;
	dataType height;
	dataType tileWidth;
	dataType tileHeight;
	dataType tilecount;
	
	/* Erilaiset tˆrm‰ykset */
	bool COLLISION_BELOW(gameObject * obj);
	bool COLLISION_ABOVE(gameObject * obj);
	bool COLLISION_LEFT(gameObject * obj);
	bool COLLISION_RIGHT(gameObject * obj);
};

#endif

