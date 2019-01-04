// 
// 
// 

#include "inputOutput.h"

bool inputOutput::returnKey(dataType nKey) {
	if (nKey >= 0 && nKey < keyAmount) {
		return !digitalRead(keyList[nKey]);
	}

	return false;
}

/* - Aseta pinnien tilat - */
void inputOutput::begin() {
	for (dataType n = 0; n < keyAmount; n++) {
		pinMode(keyList[n], INPUT_PULLUP);
	}
}