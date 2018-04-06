/*
 * cModbusSlave.h
 *
 *  Created on: Mar 31, 2018
 *      Author: SAK
 */

#ifndef CMODBUSSLAVE_H_
#define CMODBUSSLAVE_H_

#include "Arduino.h"

#define BUFFER_SIZE			64
#define POSITION_ADDRESS	0
#define CHAR_TIMEOUT		2

class cModbusSlave {
public:
	cModbusSlave(HardwareSerial *serial, uint8_t myAddress);
	void Run(void);

private:
	HardwareSerial *stream;

	bool isPackageReady;

	uint8_t inBuffer[BUFFER_SIZE];
	uint8_t inBufferLength;

	uint16_t CRC_errorsCounter;

	uint8_t myAddress;

	uint32_t slicingLastVisitTime;

	void packageSlicing(void);

	void packageHandler(void);

	bool isCRC_ok(void);

	bool isAddressMy(void);

	void incrementCRCerrorsCounter(void);

};

#endif /* CMODBUSSLAVE_H_ */
