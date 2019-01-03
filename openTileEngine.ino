/*
    Name:       openTileEngine.ino
    Created:	3.1.2019 12.03.58
    Author:     Teemu Laurila
*/

#include "mushroomGame.h"
#include "gameEvent.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "variableType.h"
#include "tilengine.h"
#include "gameObject.h"

/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//==- Oled things -==\\<<//>>\\<<//>>\\<<//>>\\<<//>>*/

const uint8_t OLED_DC = 6;
const uint8_t OLED_CS = 7;
const uint8_t OLED_RESET = 8;

Adafruit_SSD1306 oled(OLED_DC, OLED_RESET, OLED_CS);

/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>*/

tilengine engine(16, 8, 8, 8);	// tilengine(kartan leveys, kartan korkeus,
								//			 laata leveys, laatan korkeus);

#include "mushroomGame.h"
#include "bitmaps.h"

mushroomGame * mGame;

void setup() {
	mGame->initialize(8, 8, bitmap_mushroom);	// Player width, height and bitmap
}

void loop() {
	mGame->draw(engine);
}