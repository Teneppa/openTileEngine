/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\*/
/*<<																																				    >>*/
/*<<										T‰m‰ kirjasto hoitaa tilemap -muodossa olevien karttojen piirt‰misen										>>*/
/*<<									  T‰ss‰ kirjastossa on myˆs checkTile-funktio jota voi k‰ytt‰‰ tˆrm‰yksiss‰										>>*/
/*<<																																				    >>*/
/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\*/

#include "tilengine.h"

/*-- Kun luot olion, tallenna leveys ja korkeus sek‰ varaa muistia kartalle --*/
tilengine::tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight) {
	
	tilecount = getEngineWidth * getEngineHeight / 16;	// Laske tarvittavan tilan m‰‰r‰
	width = getEngineWidth;						// Tallenna kartan leveys ja korkeus
	height = getEngineHeight;

	mapBuffer = new mapDataType[tilecount];		// Varaa muistia kartalle

}

/*-- Kun olio tuhotaan, vapauta kartan viem‰ muisti --*/
tilengine::~tilengine() {
	delete[] mapBuffer;			// Vapauta kartan viem‰ muisti
}

/*-- T‰ll‰ funktiolla voi m‰‰ritt‰‰ tilenginen k‰ytt‰m‰n piirtofunktion palikoille --*/
void tilengine::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToTileDrawingFunction = getFunctionPointer;
}

/*-- T‰ll‰ funktiolla voi tarkistaa onko kyseisess‰ koordinaatissa palikkaa --*/
bool tilengine::checkTile(dataType getX, dataType getY) {

	uint8_t x = width - 1 - ((getX - getX % 8) / 8);	// Laske ruudun sijainti puskurissa
	uint8_t y = (getY - getY % 8) / 8;

	return ((mapBuffer[y] & (1 << x)) >> x);  // Tarkista onko ruudussa mit‰‰n
}

/*-- T‰ll‰ funktiolla ladataan kartta mapBufferiin --*/
void tilengine::loadMap(mapDataType *getMap) {
	memcpy(mapBuffer, getMap, sizeof(uint16_t)* width * height / 16);	// Siirr‰ kartta karttapuskuriin
}

/*-- T‰ll‰ funktiolla tarkistetaan tˆrm‰ykset objektin ja kartan v‰lill‰ --*/
void tilengine::checkCollision(gameObject * obj) {

	/* Tyhjenn‰ kaikki tˆrm‰ysmuuttujat */
	COLLISION_BELOW =	false;
	COLLISION_ABOVE =	false;
	COLLISION_LEFT  =	false;
	COLLISION_RIGHT =	false;

	dataType xpos = obj->x;		// Objektin koordinaatit
	dataType ypos = obj->y;

	dataType sprWidth = obj->width;		// Objektin koko
	dataType sprHeight = obj->height;

	/* Tarkista vasen yl‰- ja alakulma */
	if (checkTile(xpos, ypos) || checkTile(xpos, ypos + sprHeight)) {
		COLLISION_LEFT = true;
	}

	/* Tarkista oikea yl‰- ja alakulma */
	if (checkTile(xpos + sprWidth, ypos) || checkTile(xpos + sprWidth, ypos + sprHeight)) {
		COLLISION_RIGHT = true;
	}

	/* Tarkista onko objekti maassa */
	if (checkTile(xpos, ypos + sprHeight + 1) || checkTile(xpos + sprWidth, ypos + sprHeight + 1)) {
		COLLISION_BELOW = true;
	}

	/* Tarkista onko objektin yl‰puolella mit‰‰n */
	if (checkTile(xpos, ypos - 1) || checkTile(xpos + sprWidth, ypos - 1)) {
		COLLISION_ABOVE = true;
	}
}

/*-- T‰ll‰ funktiolla tarkistetaan tˆrm‰ykset mahdollisesta uudesta sijainnista --*/
void tilengine::checkCollision(gameObject * obj, dataType xOffset, dataType yOffset) {

}

/*-- T‰m‰ funktio piirt‰‰ kartan --*/
void tilengine::drawMap() {
	for (dataType y = 0; y < height; y++) {
		for (dataType x = 0; x < width; x++) {

			if (((mapBuffer[y] & (1 << x)) >> x)) { // Check if there is a bitmap to draw on this tile
				dataType xpos = dataType((width - 1) * 8 - x * 8); // Get the coordinates for the bitmap
				dataType ypos = dataType(y * 8);
				pointToTileDrawingFunction(xpos, ypos);            // K‰yt‰ funktio-osoitinta piirt‰miseen
			}

		}
	}
}