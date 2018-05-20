/*
 * cModbusSlave.h
 *
 *  Created on: Mar 31, 2018
 *      Author: SAK
 */

#ifndef CMODBUSSLAVE_H_
#define CMODBUSSLAVE_H_

#include "Arduino.h"
#include "cModbusRegisters.h"


#define BUFFER_SIZE			64
#define POSITION_ADDRESS	0
#define POSITION_FUNCTION	1
#define CHAR_TIMEOUT		1

/**
@startuml
	cModbusSlave o-down- cModbusRegisters
	cModbusRegisters o-down- cDatabase
@enduml

@startuml
	cModbusSlave o-right- cModbusRegisters
	cModbusRegisters o-right- cDatabase

	class cModbusSlave {
		+ Run()
	}

	class cModbusRegisters{
		+getRegisterValue(registerNumber)
		+setRegisterValue(registerNumber, registerValue)
		--
		-getDatabaseId(registerNumber)
	}

	class cDatabase{
		+ getParameterValue(paramId)
		+ setParameterVelue(paramId, value)
	}


@enduml

@startuml
	activate  cModbusSlave
	cModbusSlave -> cModbusRegisters : getRegisterValue(registerNumber)
	activate cModbusRegisters
	cModbusRegisters -> cModbusRegisters :getDatabaseId(registerNumber)
	cModbusRegisters -> cDatabase : getParameterValue(paramId)
	activate cDatabase
	cDatabase -> cModbusRegisters : return parameterValue
	deactivate cDatabase
	cModbusRegisters -> cModbusSlave : return registerValue
	deactivate cModbusRegisters
	deactivate cModbusSlave
@enduml


**/



class cModbusSlave {
public:
	cModbusSlave(HardwareSerial *serial, uint8_t myAddress, cModbusRegisters *modbusRegister);
	void Run(void);

private:
	HardwareSerial *stream;

	bool isPackageReady;

	cModbusRegisters *modbusRegister;

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

	bool functionsHandler(void);

	void function_0x03_Handler(void);

};

#endif /* CMODBUSSLAVE_H_ */
