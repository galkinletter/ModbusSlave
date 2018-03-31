// Do not remove the include below
#include "Modbus.h"
#include "cEcho.h"

cEcho echo(&Serial);


//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(115200);
}

// The loop function is called in an endless loop
void loop()
{
	echo.Run();
	delay(1);
}
