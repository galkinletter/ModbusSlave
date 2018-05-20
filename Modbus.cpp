// Do not remove the include below
#include "Modbus.h"
#include "cModbusSlave.h"
#include "cModbusRegisters.h"
#include "cDatabase.h"

cDatabase DB;
cModbusRegisters mRegister(&DB);

cModbusSlave modbusSlave(&Serial, 1, &mRegister);


//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(115200);
}

// The loop function is called in an endless loop
void loop()
{
	modbusSlave.Run();
}
