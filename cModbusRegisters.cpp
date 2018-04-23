/*
 * cModbusRegisters.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: SAK
 */

#include "cModbusRegisters.h"

cModbusRegisters::cModbusRegisters(cDatabase *ptrDatabase) {
	this->DB 					= ptrDatabase;
	this->lookupTable 			= NULL;
	this->lookupTableLength 	= 0;
}

int8_t cModbusRegisters:: getRegisterValue(uint16_t registerNumber, uint16_t *registerValue){
	uint32_t databaseId = 0xDEAD;
	int8_t errorCode = 0;

	errorCode = this->getDatabaseId(registerNumber, &databaseId);

	if (errorCode){
		errorCode = this->DB->getParameterValue(databaseId, registerValue);
	}

	return errorCode;
}

int8_t cModbusRegisters::getDatabaseId(uint16_t registerNumber, uint32_t *databaseId){
	int8_t returnValue = 0;

	if (registerNumber < this->lookupTableLength){
		*databaseId = this->lookupTable[registerNumber];
		returnValue = 1;
	}
	else{
		returnValue = 0;
	}

	return databaseId;
}

uint8_t cModbusRegisters::initLookupTable(uint32_t *ptrLookupTable, uint16_t lookupTableLength){
	uint8_t returnValue = 0;

	if ((ptrLookupTable != NULL) && (lookupTableLength != 0)){
		this->lookupTable 		= ptrLookupTable;
		this->lookupTableLength = lookupTableLength;
		returnValue = 0;
	}
	else{
		returnValue = 1;
	}

	return returnValue;
}



