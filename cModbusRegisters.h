/*
 * cModbusRegisters.h
 *
 *  Created on: Apr 21, 2018
 *      Author: SAK
 */

#ifndef CMODBUSREGISTERS_H_
#define CMODBUSREGISTERS_H_

#include "cDatabase.h"
#include <stdint.h>

class cModbusRegisters {
public:
	cModbusRegisters(cDatabase *ptrDatabase);

	int8_t getRegisterValue(uint16_t registerNumber, uint16_t *registerValue);

	void setRegisterValue(uint16_t registerNumber, uint16_t registerValue);

	uint8_t initLookupTable(uint32_t *ptrLookupTable, uint16_t lookupTableLength);

private:
	cDatabase 	*DB;
	uint32_t	*lookupTable;
	uint32_t	lookupTableLength;

	int8_t getDatabaseId(uint16_t registerNumber, uint32_t *databaseId);
};

#endif /* CMODBUSREGISTERS_H_ */
