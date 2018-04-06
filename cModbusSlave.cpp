/*
 * cModbusSlave.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: SAK
 */

#include "cModbusSlave.h"

cModbusSlave::cModbusSlave(HardwareSerial *serial,  uint8_t myAddress) {
	this->stream 				= serial;
	this->isPackageReady 		= false;
	this->myAddress				= myAddress;
	this->CRC_errorsCounter 	= 0;
	this->slicingLastVisitTime 	= 0;
	this->inBufferLength		= 0;

}

void cModbusSlave::Run(void){

	packageSlicing();

	packageHandler();

}

void cModbusSlave::packageSlicing(void){

	uint8_t bufferLengthCurrent = 0;
	uint32_t currentTime = 0;
	uint32_t timeOut = 0;

	currentTime = millis();

	timeOut = currentTime - slicingLastVisitTime;

	if (timeOut > CHAR_TIMEOUT){
		bufferLengthCurrent = stream->available();

		if ((bufferLengthCurrent > 0) && (!isPackageReady)){
			if (bufferLengthCurrent == inBufferLength){
				isPackageReady = true;
			}
			inBufferLength = bufferLengthCurrent;
		}
		slicingLastVisitTime = millis();
	}

}

void cModbusSlave::packageHandler(void){
	if (isPackageReady){

		stream->readBytes(inBuffer, inBufferLength);

		do{
			if (isCRC_ok() == false){
				incrementCRCerrorsCounter();
				break;
			}

			if(isAddressMy() == false){
				break;
			}

			//TODO: We have to implement function handling here.

			stream->write(inBuffer, inBufferLength);

			break;
		}while(false);

		isPackageReady = false;
		inBufferLength = 0;
	}
}

bool cModbusSlave::isCRC_ok(void){
	uint16_t crc;
	bool isCRC_OK = false;

	crc = inBuffer[inBufferLength - 2];
	crc = crc << 8;
	crc = crc | inBuffer[inBufferLength - 1];

	isCRC_OK = (crc == 0xDEAD);

	return isCRC_OK;
}

void cModbusSlave::incrementCRCerrorsCounter(void){
	if (CRC_errorsCounter < 0xFFFF){
		CRC_errorsCounter ++;
	}
}

bool cModbusSlave::isAddressMy(void){
	bool returnValue = false;

	uint8_t address = inBuffer[POSITION_ADDRESS];

	if (address == myAddress){
		returnValue = true;
	}
	else{
		returnValue = false;
	}

	return returnValue;
}


