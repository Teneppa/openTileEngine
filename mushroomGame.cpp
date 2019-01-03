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

/*--  --*/
void mushroomGame::initialize(dataType width, dataType height, bitmapDataType * bitmap) {
	player.bitmap = bitmap;
	player.width = width;
	player.height = height;
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}