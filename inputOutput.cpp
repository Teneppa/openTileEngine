// 
// 
// 

#include "inputOutput.h"

bool inputOutput::returnKey(dataType nKey) {
	if (nKey >= 0 && nKey < keyAmount) {

		if (nKey == 0) {
			if (analogRead(keyList[nKey]) < 500) {
				return 1;
			} else {
				return 0;
			}
		}

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