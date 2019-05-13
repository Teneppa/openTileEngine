/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\*/
/*<<																																				    >>*/
/*<<										T�m� kirjasto hoitaa tilemap -muodossa olevien karttojen piirt�misen										>>*/
/*<<									  T�ss� kirjastossa on my�s checkTile-funktio jota voi k�ytt�� t�rm�yksiss�										>>*/
/*<<																																				    >>*/
/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\*/

#include "tilengine.h"

/*-- Kun luot olion, tallenna leveys ja korkeus sek� varaa muistia kartalle --*/
tilengine::tilengine(bitmapDataType * getTileBitmap, dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight) {
	
	tileBitmap = getTileBitmap;

	tileWidth = getTileWidth;
	tileHeight = getTileHeight;

	tilecount = getEngineWidth * getEngineHeight / 16;	// Laske tarvittavan tilan m��r�
	width = getEngineWidth;						// Tallenna kartan leveys ja korkeus
	height = getEngineHeight;

	mapBuffer = new mapDataType[tilecount];		// Varaa muistia kartalle

}

/*-- Kun olio tuhotaan, vapauta kartan viem� muisti --*/
tilengine::~tilengine() {
	delete[] mapBuffer;			// Vapauta kartan viem� muisti
}

/*-- T�ll� funktiolla voi m��ritt�� tilenginen k�ytt�m�n piirtofunktion palikoille --*/
void tilengine::assignBitmapDrawingFunction(void(*getBitmapFunctionPointer)(dataType x, dataType y, bitmapDataType * bitmap, dataType width, dataType height)) {
	pointToBitmapDrawingFunction = getBitmapFunctionPointer;
}

/*-- T�ll� funktiolla voi tarkistaa onko kyseisess� koordinaatissa palikkaa --*/
bool tilengine::checkTile(dataType getX, dataType getY) {

	uint8_t x = width - 1 - ((getX - getX % 8) / 8);	// Laske ruudun sijainti puskurissa
	uint8_t y = (getY - getY % 8) / 8;

	return ((mapBuffer[y] & (1 << x)) >> x);  // Tarkista onko ruudussa mit��n
}

/*-- T�ll� funktiolla ladataan kartta mapBufferiin --*/
void tilengine::loadMap(const mapDataType *getMap) {
	memcpy(mapBuffer, getMap, sizeof(uint16_t)* width * height / 16);	// Siirr� kartta karttapuskuriin
}

/*<<//>><<\\>><<//>>\\>><<//>><<//>> N�ill� funktiolla tarkistetaan t�rm�ykset objektin ja kartan v�lill� <<//>><<\\>><<//>>\\>><<//>><<//>>*/

/*= Tarkista oikea yl�- ja alakulma =*/
bool tilengine::COLLISION_RIGHT(gameObject * obj) {
	if (checkTile(obj->x + obj->height - 1, obj->y) || checkTile(obj->x + obj->width - 1, obj->y + obj->height - 1)) {return true;}

	return false;
}

/*-- Tarkista vasen yl�- ja alakulma --*/
bool tilengine::COLLISION_LEFT(gameObject * obj) {
	if (checkTile(obj->x, obj->y) || checkTile(obj->x, obj->y + obj->height-1)) { return true; }

	return false;
}

/*-- Tarkista onko objekti maassa --*/
bool tilengine::COLLISION_BELOW(gameObject * obj) {
	if (checkTile(obj->x, obj->y + obj->height) || checkTile(obj->x + obj->width-1, obj->y + obj->height)) { return true; }

	return false;
}

/*-- Tarkista onko objektin yl�puolella mit��n --*/
bool tilengine::COLLISION_ABOVE(gameObject * obj) {
	if (checkTile(obj->x, obj->y - 1) || checkTile(obj->x + obj->width - 1, obj->y - 1)) { return true; }

	return false;
}

/*<<//>><<\\>><<//>>\\>><<//>><<//>><<\\>><<//>>\\>><<//>><<//>><<\\>><<//>>\\>><<//>><<//>><<\\>><<//>>\\>><<//>><<//>><<\\>><<//>>\\>><<//>>*/

/*-- T�m� funktio piirt�� kartan --*/
void tilengine::drawMap() {
	for (dataType y = 0; y < height; y++) {
		for (dataType x = 0; x < width; x++) {

			if (((mapBuffer[y] & (1 << x)) >> x)) { // Check if there is a bitmap to draw on this tile
				dataType xpos = dataType((width - 1) * tileWidth - x * tileWidth); // Get the coordinates for the bitmap
				dataType ypos = dataType(y * tileHeight);
				pointToBitmapDrawingFunction(xpos, ypos, tileBitmap, tileWidth, tileHeight);	// K�yt� funktio-osoitinta piirt�miseen
			}

		}
	}
}

/*-- T�m� funktio piirt�� objektin --*/
void tilengine::drawObject(gameObject * obj) {
	pointToBitmapDrawingFunction(obj->x, obj->y, obj->bitmap, obj->width, obj->height);
}