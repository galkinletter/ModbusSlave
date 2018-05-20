/*
 * Database.h
 *
 *  Created on: 20 трав. 2018 р.
 *      Author: MaGol
 */

#ifndef DATABASE_H_
#define DATABASE_H_


#include <stdint.h>
#include "DatabaseDescription.h"


#define STORAGE_SIZE   2


typedef struct {
uint16_t        startIndex;
dbFielsType_t   dataType;
void            (*Callback)();
} DBFieldDescription_t;


static        uint8_t STORAGE [STORAGE_SIZE]         = {0};
const static  uint8_t STORAGE_DEFAULT [STORAGE_SIZE] = {
0,0
};


const DBFieldDescription_t DB [STORAGE_SIZE] = {
//  StartIndex    dataType    callback
		{  0,       UINT8,        0},
		{  1,       UINT8,        0},
};


#endif /* DATABASE_H_ */
