// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

/*-- Kun pelistä luodaan olio --*/
mushroomGame::mushroomGame(tilengine * engine) {
	player.x = 8;	// Aseta pelaajan koordinaateiksi (8,8)
	player.y = 8;

	localEngine = engine;
}

/*-- Kun peli käynnistetään muista määrittää pelaajan koko --*/
void mushroomGame::initialize(dataType width, dataType height) {
	player.width = width;
	player.height = height;
}

/*--  --*/
void mushroomGame::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToPlayerDrawingFunction = getFunctionPointer;
}

/*-- Pelin pääfunktio --*/
void mushroomGame::run() {

	/* Päivitä pelifunktiota n. 62,5 kertaa sekunnissa */
	if (millis() - oldMushroomUpdateTime > 16) {
		draw();	// Piirrä kartta ja pelaaja

		localEngine->checkCollision(&player);	// Laske törmäykset pelaajalle

		if (!localEngine->COLLISION_BELOW) {
			playerPhysics.calculateGravity(&player, 0.2, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		}

		oldUpdateTime = millis();
	}
	
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();	// Piirrä kartta
	pointToPlayerDrawingFunction(player.x, player.y);	// Piirrä pelaaja
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}