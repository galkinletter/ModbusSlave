/*
 * cModbusSlave.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: SAK
 */

#include "cModbusSlave.h"

cModbusSlave::cModbusSlave(HardwareSerial *serial,  uint8_t myAddress) {
	this->stream 			= serial;
	this->isPackageReady 	= false;
	this->CRC_errorsCounter = 0;
	this->myAddress			= myAddress;
}

void cModbusSlave::Run(void){

	this->packageSlicing();

	this->packageHandler();
}


void cModbusSlave::packageHandler(void){
	if (this->isPackageReady){
		this->isPackageReady = false;

		do{
			if (this->isCRC_ok() == false){
				this->incrementCRCerrorsCounter();
				break;
			}

			if(this->isAddressMy() == false){
				break;
			}

			//TODO: We have to implement function handling here.
			break;
		}while(false);
	}
}

void cModbusSlave::incrementCRCerrorsCounter(void){
	if (this->CRC_errorsCounter < 0xFFFF){
		this->CRC_errorsCounter ++;
	}
}

bool cModbusSlave::isAddressMy(void){
	bool returnValue = false;

	uint8_t address = this->inBuffer[POSITION_ADDRESS];

	if (address == this->myAddress){
		returnValue = true;
	}
	else{
		returnValue = false;
	}

	return returnValue;
}


