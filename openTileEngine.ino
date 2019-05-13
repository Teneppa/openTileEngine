/*
    Name:       openTileEngine.ino
    Created:	3.1.2019 12.03.58
    Author:     Teemu Laurila
*/

/*--  --*/

//#define BOARD_VERSION_1
#define BOARD_VERSION_2

#include "mushroomLevels.h"
#include "levels.h"
#include "inputOutput.h"
#include "physics.h"
#include "mushroomGame.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "variableType.h"
#include "tilengine.h"
#include "gameObject.h"

/*-- M��rit� pinnit OLED-n�yt�lle --*/

const uint8_t OLED_DC = 6;
const uint8_t OLED_CS = 7;
const uint8_t OLED_RESET = 8;

Adafruit_SSD1306 oled(OLED_DC, OLED_RESET, OLED_CS);

/*-- Asetukset OLED-n�yt�lle --*/

void beginDisplay() {
	oled.begin(SSD1306_SWITCHCAPVCC);	// K�yt� sis�ist� j�nnitegeneraattoria

	// Miten p�in n�ytt� on asennettu?
	// V1 = 2 (k��nn� 180 astetta)
	// V2 = 0 (�l� k��nn� ollenkaan)

	#ifdef BOARD_VERSION_1
		oled.setRotation(2);				// Py�r�yt� kuvaa 180 astetta (V1)
	#endif

	#ifdef BOARD_VERSION_2
		oled.setRotation(0);				// Py�r�yt� kuvaa 0 astetta (V2)
	#endif
}

tilengine engine(bitmap_block, 16, 8, 8, 8);	// tilengine(kartan leveys, kartan korkeus,
								                //           laatan leveys, laatan korkeus);

#include "mushroomGame.h"
#include "bitmaps.h"
#include "mushroomLevels.h"

mushroomGame mGame(&engine);	// Anna pelille tile-enginen muistiosoite, jotta se voi k�ytt�� sit�

/* Piirtofunktio bittikartoille */
void bitmapDrawingFunction(dataType x, dataType y, bitmapDataType * bmp, dataType width, dataType height) {
	oled.drawBitmap(x, y, bmp, 8, 8, 1);
}

void setup() {

	//Serial.begin(115200);

	beginDisplay();			// M��rit� OLED -juttuja

	engine.assignBitmapDrawingFunction(bitmapDrawingFunction);	// M��rit� piirtofunktio palikoille
	mGame.assignBitmapDrawingFunction(bitmapDrawingFunction);	// M��rit� piirtofunktio pelaajalle

	mGame.initialize(8, 8);	// Player width and height
}

void loop() {
	oled.clearDisplay();	// Tyhjenn� puskuri

	mGame.run();			// Piirr� peli�

	oled.display();			// Siirr� puskuri n�yt�lle
}