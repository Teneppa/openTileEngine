// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

/*-- Kun pelistä luodaan olio --*/
mushroomGame::mushroomGame(tilengine * engine) {
	player.x = 9;	// Aseta pelaajan koordinaateiksi (9,46)
	player.y = 46;

	localEngine = engine;
	playerPhysics.assignEnginePointer(localEngine);
}

/*-- Kun peli käynnistetään --*/
void mushroomGame::initialize(dataType width, dataType height) {
	player.width = width;		// Määritä pelaajan leveys ja korkeus
	player.height = height;
	player.hSpeed = 0;
	player.vSpeed = 0;
	io.begin();					// Aseta pinnien tilat

	key.x = 8;		// Määritä 'avaimen' koordinaati ja koko
	key.y = 8;
	key.width = 8;
	key.height = 8;
	key.bitmap = coin1;

	currentLevel = 0;	// Nollaa tämänhetkinen taso

	loadLevel(currentLevel);	// Lataa tämänhetkinen taso
	loadObjects(currentLevel);
}

/*--  --*/
void mushroomGame::assignBitmapDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y, bitmapDataType * bitmap, dataType width, dataType height)) {
	pointToBitmapDrawingFunction = getFunctionPointer;
}

/*-- Lataa haluttu taso --*/
void mushroomGame::loadLevel(dataType levelToLoad) {
	if (levelToLoad >= 0 && levelToLoad < numberOfMushroomLevels) {

		player.x = 9;
		player.y = 46;
		
		const mapDataType * pointerToStartOfTheMap = &mushroomMap[levelToLoad*8];
		loadMap(pointerToStartOfTheMap);
		
	}
}

bitmapDataType * mushroomGame::getBitmapById(dataType id) {
	if (id == 1) {
		return spike;
	}
}

/*-- Lataa halutun tason objektit --*/
void mushroomGame::loadObjects(dataType level) {
	if (level < 0 || level > numberOfMushroomLevels) {
		return;
	}

	dataType dataPerLevel = numberOfMushroomObjectVariables * numberOfMushroomObjects;
	loadedObjects[0].x = mushroomObjects[0 + level * dataPerLevel] * 8;
	loadedObjects[0].y = mushroomObjects[1 + level * dataPerLevel] * 8;
	loadedObjects[0].width = mushroomObjects[2 + level * dataPerLevel];
	loadedObjects[0].height = mushroomObjects[3 + level * dataPerLevel];
	loadedObjects[0].bitmap = getBitmapById(mushroomObjects[4 + level * dataPerLevel]);

	loadedObjects[1].x = mushroomObjects[5 + level * dataPerLevel] * 8;
	loadedObjects[1].y = mushroomObjects[6 + level * dataPerLevel] * 8;
	loadedObjects[1].width = mushroomObjects[7 + level * dataPerLevel];
	loadedObjects[1].height = mushroomObjects[8 + level * dataPerLevel];
	loadedObjects[1].bitmap = getBitmapById(mushroomObjects[9 + level * dataPerLevel]);
}

/*-- Pelin pääfunktio --*/
void mushroomGame::run() {

	/* Päivitä pelifunktiota n. 62,5 kertaa sekunnissa */
	if (millis() - oldMushroomUpdateTime > 8) {
		draw();	// Piirrä kartta ja pelaaja

		// Jos pelaaja osuu avaimeen
		if (key.collidesWithGameobject(&player)) {
			Serial.println(F("Player got the key!"));
			currentLevel += 1;
			loadLevel(currentLevel);
			loadObjects(currentLevel);
		}

		handleLoadedObjects();

		/*
		playerPhysics.calculateAccelerations(&player, millis() - oldUpdateTime);

		if (io.returnKey(io.KEY_JUMP) && localEngine->COLLISION_BELOW(&player)) {	// Jos hyppynappia painetaan
			player.vSpeed = -40;
		}

		if (io.returnKey(io.KEY_LEFT)) {
			player.hSpeed = -20;
		}

		if (io.returnKey(io.KEY_RIGHT)) {
			player.hSpeed = 20;
		}
		*/
		
		// Tarkista onko pelaaja ilmassa vai maassa
		if (!localEngine->COLLISION_BELOW(&player)) {
			playerPhysics.calculateGravity(&player, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		} else {
			if (io.returnKey(io.KEY_JUMP)) {	// Jos hyppynappia painetaan
				player.vSpeed = -80.0f;
				player.y -= 1;	// Nosta pelaajaa yhdellä pikselillä jotta tilengine ei luule että pelaaja olisi jo maassa
			}
		}

		// Jos pelaaja liikkuu vasemmalle
		if (!localEngine->COLLISION_LEFT(&player)) {
			if (io.returnKey(io.KEY_LEFT)) {
				player.x -= 1;

				// Jos pelaaja meni seinän sisään, siirrä pelaaja pois sieltä
				if (localEngine->COLLISION_LEFT(&player)) {
					player.x += 1;
				}
			}
		}

		// Jos pelaaja liikkuu oikealle
		if (!localEngine->COLLISION_RIGHT(&player)) {
			if (io.returnKey(io.KEY_RIGHT)) {
				player.x += 1;

				// Jos pelaaja meni seinän sisään, siirrä pelaaja pois sieltä
				if (localEngine->COLLISION_RIGHT(&player)) {
					player.x -= 1;
				}

			}
		}

		// Jos pelaaja törmää yllä olevaan palikkaan
		if (localEngine->COLLISION_ABOVE(&player)) {
			player.vSpeed = abs(player.vSpeed)/2;
		}

		/* DEBUG */

		/*
		Serial.println("Törmäys vasemmalle: " + String(localEngine->COLLISION_LEFT));
		Serial.println("Törmäys oikealle: " + String(localEngine->COLLISION_RIGHT));
		Serial.println("Törmäys alla: " + String(localEngine->COLLISION_BELOW));

		Serial.println();
		*/

		oldUpdateTime = millis();
	}
	
}


void mushroomGame::handleLoadedObjects() {
	// Jos pelaaja törmää objektiin 0 ja se on piikki
	if (loadedObjects[0].bitmap == getBitmapById(1)) {
		if (loadedObjects[0].collidesWithGameobject(&player)) {
			loadLevel(currentLevel);
		}
	}

	// Jos pelaaja törmää objektiin 1 ja se on piikki
	if (loadedObjects[1].bitmap == getBitmapById(1)) {
		if (loadedObjects[1].collidesWithGameobject(&player)) {
			loadLevel(currentLevel);
		}
	}
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();	// Piirrä kartta
	pointToBitmapDrawingFunction(player.x, player.y, bitmap_mushroom, player.width, player.height);	// Piirrä pelaaja
	//pointToBitmapDrawingFunction(key.x, key.y, coin1, key.width, key.height);

	localEngine->drawObject(&key);
	localEngine->drawObject(&loadedObjects[0]);
	localEngine->drawObject(&loadedObjects[1]);
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}

/*--  --*/
void mushroomGame::loadMap(const mapDataType * m) {
	localEngine->loadMap(m);
}