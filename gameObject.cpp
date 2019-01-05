// 
// 
// 

#include "gameObject.h"

gameObject::gameObject() {

}

gameObject::gameObject(dataType width, dataType height, bitmapDataType * bitmap) {

}

gameObject::~gameObject() {

}

dataType gameObject::getHeight() {

}

dataType gameObject::getWidth() {

}

bool gameObject::collidesWithGameobject(gameObject * obj) {
	/* Tämänhetkinen objekti */
	dataType thisX = x;
	dataType thisY = y;
	dataType thisWidth = width;
	dataType thisHeight = height;

	/* Syötetty objekti */
	dataType thatX = obj->x;
	dataType thatY = obj->y;
	dataType thatWidth = obj->width;
	dataType thatHeight = obj->height;

	/* AABB törmäystesti */
	if (thisX < thatX + thatWidth &&
		thisX + thisWidth > thatX &&
		thisY < thatY + thatHeight &&
		thisY + thisHeight > thatY) {

		return true;
	}

	return false;
}