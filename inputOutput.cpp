// 
// 
// 

#include "inputOutput.h"

bool inputOutput::returnKey(dataType nKey) {
	if (nKey >= 0 && nKey < keyAmount) {
		return digitalRead(keyList[nKey]);
	}

	return false;
}