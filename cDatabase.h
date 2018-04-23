/*
 * cDatabase.h
 *
 *  Created on: Apr 21, 2018
 *      Author: SAK
 */

#ifndef CDATABASE_H_
#define CDATABASE_H_

#include "stdint.h"

class cDatabase {
public:
	cDatabase();

	int8_t getParameterValue(uint32_t parameterId, uint16_t *parameterValue);
};

#endif /* CDATABASE_H_ */
