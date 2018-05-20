/*
 * cDatabase.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: SAK
 */

#include "cDatabase.h"

#include "Database.h"
#include "DatabaseDescription.h"
#include <string.h>


cDatabase::cDatabase() {

}


    int8_t cDatabase::getParameterValue(uint32_t parameterId, uint8_t *parameterValue){
    	int8_t erroreCode = FIELD_ABSENT;

        if(parameterId < STORAGE_SIZE){
        	erroreCode = TYPE_INCORRRECT;
        	if(DB[parameterId].dataType == UINT8){
        		(*parameterValue) = STORAGE[DB[parameterId].startIndex];
        		erroreCode = SUCCESSFUL;
        	}
        }
    	return erroreCode;
    }

	int8_t cDatabase::getParameterValue(uint32_t parameterId, uint16_t *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT16){
				memcpy(&parameterValue, &STORAGE[DB[parameterId].startIndex], DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}

	int8_t cDatabase::getParameterValue(uint32_t parameterId, uint32_t *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT32){
				memcpy(&parameterValue, &STORAGE[DB[parameterId].startIndex], DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}

	int8_t cDatabase::getParameterValue(uint32_t parameterId, float *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == FLOAT){
				memcpy(&parameterValue, &STORAGE[DB[parameterId].startIndex], DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}


	int8_t cDatabase::setParameterValue(uint32_t parameterId, uint8_t *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT8){
				memcpy(&STORAGE[DB[parameterId].startIndex], &parameterValue, DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}

	int8_t cDatabase::setParameterValue(uint32_t parameterId, uint16_t *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT16){
				memcpy(&STORAGE[DB[parameterId].startIndex], &parameterValue, DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}

	int8_t cDatabase::setParameterValue(uint32_t parameterId, uint32_t *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT16){
				memcpy(&STORAGE[DB[parameterId].startIndex], &parameterValue, DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}

	int8_t cDatabase::setParameterValue(uint32_t parameterId, float *parameterValue){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			erroreCode = TYPE_INCORRRECT;
			if(DB[parameterId].dataType == UINT16){
				memcpy(&STORAGE[DB[parameterId].startIndex], &parameterValue, DB[parameterId].dataType);
				erroreCode = SUCCESSFUL;
			}
		}
		return erroreCode;
	}


	int8_t cDatabase::setParameterToDefault(uint32_t parameterId){
		int8_t erroreCode = FIELD_ABSENT;

		if(parameterId < STORAGE_SIZE){
			memcpy(&STORAGE[DB[parameterId].startIndex], &STORAGE_DEFAULT[DB[parameterId].startIndex], DB[parameterId].dataType);
			erroreCode = SUCCESSFUL;
		}
		return erroreCode;
	}

	int8_t cDatabase::resetDatabase(void){
		int8_t erroreCode = 0;

		memcpy(STORAGE, STORAGE_DEFAULT, STORAGE_SIZE);
		erroreCode = SUCCESSFUL;

		return erroreCode;
	}
