/*
 * cEcho.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: SAK
 */

#include "cEcho.h"
#include "stdint.h"

cEcho::cEcho(HardwareSerial *serial) {
	this->serial = serial;
	this->bufferLength = 0;
}

void cEcho::Run(void){
	uint8_t bufferLengthCurrent = 0;

	bufferLengthCurrent = serial->available();

	if (bufferLengthCurrent != 0 ){
		if (bufferLengthCurrent == this->bufferLength){
			serial->println(bufferLength, DEC);
					serial->readBytes(buffer, bufferLength);
					serial->write(buffer, bufferLength);
		}
		else{
			this->bufferLength = bufferLengthCurrent;
		}
	}
}

