// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section


/*
@startuml
class cLamp{
	+ cLamp (pinNumber, pinLevelOn, pinLevelOff, blinkPeriod)
	--
	+ ON()
	+ OFF()
	+ Blink(period)
	+ SetMode(mode)
}
class cTrafficLigh{
	+ Run()
	+ SetMode(newMode)
}
class cTrafficLightPeadestrian{
	+ Run()
	+ SetMode(newMode)
}
class cTrafficLightCars{
	+ Run()
	+ SetMode(newMode)
}
cTrafficLigh <|-left- cTrafficLightPeadestrian
cTrafficLigh <|-right- cTrafficLightCars
cLamp o-- cTrafficLightPeadestrian
cLamp o-- cTrafficLightCars
@enduml
@startuml
activate cCrossroads
cCrossroads -> cTrafficLight: Run()
cTrafficLight -> cTrafficLightCars : Run()
cTrafficLightCars -> cLamp : Run()
deactivate cCrossroads
cCrossroads -> cTrafficLight: Run()
cTrafficLight -> cTrafficLightPedestrians : Run()
activate cCrossroads
cCrossroads -> cTrafficLightPedestrians : getMode()
activate cTrafficLightPedestrians
cTrafficLightPedestrians -> cCrossroads : return mode
deactivate cTrafficLightPedestrians
deactivate cCrossroads
@enduml


#ifndef _Modbus_H_
#define _Modbus_H_
#include "Arduino.h"
//add your includes for the project Modbus here


//end of add your includes here


//add your function definitions for the project Modbus here




//Do not add code below this line
#endif /* _Modbus_H_ */
