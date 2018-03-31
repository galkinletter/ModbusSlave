/*
 * cEcho.h
 *
 *  Created on: Mar 24, 2018
 *      Author: SAK
 */

#ifndef CECHO_H_
#define CECHO_H_

#include "Arduino.h"


class cEcho {
public:
	cEcho(HardwareSerial *serial);
	void Run(void);
private:
	HardwareSerial *serial;
	uint8_t bufferLength;
	uint8_t buffer[64];

};

#endif /* CECHO_H_ */
