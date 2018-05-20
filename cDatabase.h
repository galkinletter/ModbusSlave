/*
 * cDatabase.h
 *
 *  Created on: Apr 21, 2018
 *      Author: SAK
 */

#ifndef CDATABASE_H_
#define CDATABASE_H_

#include <stdint.h>



enum{
	OUT_OF_RANGE    = -1,
	TYPE_INCORRRECT = -2,
	FIELD_ABSENT    = -3,
	SUCCESSFUL      =  1

};



class cDatabase {
public:
	cDatabase();

	int8_t getParameterValue(uint32_t parameterId, uint8_t *parameterValue);
	int8_t getParameterValue(uint32_t parameterId, uint16_t *parameterValue);
	int8_t getParameterValue(uint32_t parameterId, uint32_t *parameterValue);
	int8_t getParameterValue(uint32_t parameterId, float *parameterValue);


	int8_t setParameterValue(uint32_t parameterId, uint8_t *parameterValue);
	int8_t setParameterValue(uint32_t parameterId, uint16_t *parameterValue);
	int8_t setParameterValue(uint32_t parameterId, uint32_t *parameterValue);
	int8_t setParameterValue(uint32_t parameterId, float *parameterValue);


	int8_t setParameterToDefault(uint32_t parameterId);

	int8_t resetDatabase(void);

};

#endif /* CDATABASE_H_ */
