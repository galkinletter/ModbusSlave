/*
 * cModbusSlave.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: SAK
 */

#include "cModbusSlave.h"

cModbusSlave::cModbusSlave(HardwareSerial *serial,  uint8_t myAddress, cModbusRegisters *modbusReg) {
	this->stream 				= serial;
	this->isPackageReady 		= false;
	this->myAddress				= myAddress;
	this->CRC_errorsCounter 	= 0;
	this->slicingLastVisitTime 	= 0;
	this->inBufferLength		= 0;
    this->modbusRegister        = modbusReg;
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

			functionsHandler();

//			stream->write(inBuffer, inBufferLength);

			break;
		}while(false);

		isPackageReady = false;
		inBufferLength = 0;
	}
}

bool cModbusSlave::functionsHandler(void){
	uint8_t functionCode = 0;

	functionCode = inBuffer[POSITION_FUNCTION];
	stream->print("Function code:");
	stream->println(functionCode);
	switch (functionCode) {
	case 0x03:
	case 0x04:
		function_0x03_Handler();
		break;
	case 0x06:

		break;
	default:
		// TODO: We have to implement exceptions handling
		break;
	}


return true;
}

void cModbusSlave::function_0x03_Handler(void){
	uint16_t registersAmount = 0;
	uint16_t registerFirst = 0;

	registersAmount = inBuffer[4];
	registersAmount = registersAmount << 8;
	registersAmount |= inBuffer[5];

	registerFirst  = inBuffer[3];


	uint8_t registerNumber = inBuffer[2];
	uint16_t returnedValue;

	this->modbusRegister->getRegisterValue(registerNumber, &returnedValue);

	// TODO : We have to find how to get register value

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


